#include "packageinfo.h"

Packageinfo::Packageinfo(QWidget *parent) : QWidget(parent)
{
    dbusConnect = -1;
    ServerName = "com.lingmo.kysdk.service";
    ServerInterface = "com.lingmo.kysdk.packageinfo";
    ServerPath = "/com/lingmo/kysdk/packageinfo";
}

Packageinfo::Packageinfo(QString urlPath)
{
    dbusConnect = -1;
    ServerName = "com.lingmo.kysdk.service";
    ServerInterface = "com.lingmo.kysdk.packageinfo";
    ServerPath = "/com/lingmo/kysdk/packageinfo";
    path = urlPath;
    path_list = urlPath.split("?");
}

QJsonObject Packageinfo::deal_packageinfo()
{
    qDebug()<<"packageinfo url path is "<<path;

    if(path_list.size()>1)
    {
        return deal_packageinfo_path_para();
    }else{
        return deal_packageinfo_path();
    }
}

QJsonObject Packageinfo::deal_packageinfo_path()
{
    QJsonArray jarray;
    QJsonObject json;
    if(path == "/packageinfo/getPackageList")
    {
        QStringList res = getPackageList();
        for(int i=0;i<res.size();i++)
        {
            jarray.append(res[i]);
        }
        json.insert("Result",dbusConnect);
        json.insert("ResultMessage",jarray);
        return json;
    }
}

QJsonObject Packageinfo::deal_packageinfo_path_para()
{
    QJsonArray jarray;
    QJsonObject json;
    QString packageName = path_list[1];
    packageName =packageName.split("=").last();
    qDebug()<<"package name is "<<packageName;
    if(path_list[0] == "/packageinfo/getPackageVersion")
    {
        QString res = getPackageVersion(packageName);
        json.insert("Result",dbusConnect);
        json.insert("ResultMessage",res);
        return json;
    }
    else if(path_list[0] == "/packageinfo/getPackageInstalled")
    {
        QString parainfo = path_list[1];
        QStringList para_list = parainfo.split("&");
        QString para_first = para_list.first();
        QString para_second = para_list.last();
        para_first = para_first.split("=").last();
        para_second = para_second.split("=").last();
        qDebug()<<"first para is "<<para_first;
        qDebug()<<"second para is "<<para_second;
        int res = getPackageInstalled(para_first, para_second);
        json.insert("Result",dbusConnect);
        json.insert("ResultMessage",res);
        return json;
    }
}

QStringList Packageinfo::getPackageList()
{
    QVariant res = kdbus.dbusSend(ServerName,ServerPath,ServerInterface,"getPackageList");
    dbusConnect = kdbus.dbusConn;
    return res.toStringList();
}

QString Packageinfo::getPackageVersion(QString packageName)
{
    QVariant res = kdbus.dbusSendpara(ServerName,ServerPath,ServerInterface,"getPackageVersion",packageName);
    dbusConnect = kdbus.dbusConn;
    return res.toString();
}

int Packageinfo::getPackageInstalled(QString packageName, QString packageNum)
{
    QVariant res = kdbus.dbusSendpara2(ServerName,ServerPath,ServerInterface,"getPackageInstalled",packageName,packageNum);
    dbusConnect = kdbus.dbusConn;
    return res.toInt();
}
