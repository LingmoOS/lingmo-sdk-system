#include "disk.h"

//Disk::Disk(QWidget *parent) : QWidget(parent)
//{
//    dbusConnect = -1;
//    ServerName = "com.lingmo.kysdk.service";
//    ServerInterface = "com.lingmo.kysdk.disk";
//    ServerPath = "/com/lingmo/kysdk/disk";
//}
Disk::Disk(){
        dbusConnect = -1;
        ServerName = "com.lingmo.kysdk.service";
        ServerInterface = "com.lingmo.kysdk.disk";
        ServerPath = "/com/lingmo/kysdk/disk";
}

Disk::Disk(QString urlPath)
{
    dbusConnect = -1;
    ServerName = "com.lingmo.kysdk.service";
    ServerInterface = "com.lingmo.kysdk.disk";
    ServerPath = "/com/lingmo/kysdk/disk";
    path = urlPath;
    path_list = urlPath.split("?");
}

QJsonObject Disk::deal_disk()
{
    qDebug()<<"disk url path is "<<path;

    if(path_list.size()>1)
    {
        return deal_disk_path_para();
    }else{
        return deal_disk_path();
    }
}

QJsonObject Disk::deal_disk_path()
{
    QJsonArray jarray;
    QJsonObject json;
    if(path == "/disk/getDiskList")
    {
        QStringList res = getDiskList();
        for(int i=0;i<res.size();i++)
        {
            jarray.append(res[i]);
        }
        json.insert("Result",dbusConnect);
        json.insert("ResultMessage",jarray);
        return json;
    }
}

QJsonObject Disk::deal_disk_path_para()
{
    QJsonArray jarry;
    QJsonObject json;
    QString diskName = path_list[1];
    diskName =diskName.split("=").last();
    qDebug()<<"diskname is "<<diskName;
    if(path_list[0] == "/disk/getDiskSectorSize")
    {
        int res = getDiskSectorSize(diskName);
        json.insert("Result",dbusConnect);
        json.insert("ResultMessage",res);
        return json;
    }
    else if(path_list[0] == "/disk/getDiskType")
    {
        QString res = getDiskType(diskName);
        json.insert("Result",dbusConnect);
        json.insert("ResultMessage",res);
        return json;
    }
    else if (path_list[0] == "/disk/getDiskVersion")
    {
        QString res = getDiskVersion(diskName);
        json.insert("Result",dbusConnect);
        json.insert("ResultMessage",res);
        return json;
    }
    else if (path_list[0] == "/disk/getDiskSectorNum")
    {
        long long res = getDiskSectorNum(diskName);
        json.insert("Result",dbusConnect);
        json.insert("ResultMessage",res);
        return json;
    }
    else if (path_list[0] == "/disk/getDiskTotalSizeMiB")
    {
        double res = getDiskTotalSizeMiB(diskName);
        json.insert("Result",dbusConnect);
        json.insert("ResultMessage",res);
        return json;
    }
    else if (path_list[0] == "/disk/getDiskModel")
    {
        QString res = getDiskModel(diskName);
        json.insert("Result",dbusConnect);
        json.insert("ResultMessage",res);
        return json;
    }
    else if (path_list[0] == "/disk/getDiskSerial")
    {
        QString res = getDiskSerial(diskName);
        json.insert("Result",dbusConnect);
        json.insert("ResultMessage",res);
        return json;
    }
    else if (path_list[0] == "/disk/getDiskPartitionNums")
    {
        int res = getDiskPartitionNums(diskName);
        json.insert("Result",dbusConnect);
        json.insert("ResultMessage",res);
        return json;
    }
}

QString Disk::getDiskType(QString DiskName)
{
    QVariant res = kdbus.dbusSendpara(ServerName,ServerPath,ServerInterface,"getDiskType", DiskName) ;
    qDebug()<<"res is "<<res.toString();
    dbusConnect = kdbus.dbusConn;
    return res.toString();
}

QString Disk::getDiskVersion(QString DiskName)
{
    QVariant res = kdbus.dbusSendpara(ServerName,ServerPath,ServerInterface,"getDiskVersion", DiskName) ;
    dbusConnect = kdbus.dbusConn;
    return res.toString();
}

unsigned int Disk::getDiskSpeed(QString DiskName)
{
    QVariant res = kdbus.dbusSendpara(ServerName,ServerPath,ServerInterface,"getDiskSpeed", DiskName) ;
    dbusConnect = kdbus.dbusConn;
    return res.toUInt();
}

unsigned long long Disk::getDiskSectorNum(QString DiskName)
{
    QVariant res = kdbus.dbusSendpara(ServerName,ServerPath,ServerInterface,"getDiskSectorNum", DiskName) ;
    dbusConnect = kdbus.dbusConn;
    return res.toULongLong();
}

QStringList Disk::getDiskList()
{
    QVariant res = kdbus.dbusSend(ServerName,ServerPath,ServerInterface,"getDiskList");
    dbusConnect = kdbus.dbusConn;
    return res.toStringList();
}

int Disk::getDiskSectorSize(QString DiskName)
{
    QVariant res = kdbus.dbusSendpara(ServerName,ServerPath,ServerInterface,"getDiskSectorSize", DiskName) ;
    dbusConnect = kdbus.dbusConn;
    return res.toInt();
}

double Disk::getDiskTotalSizeMiB(QString DiskName)
{
    QVariant res = kdbus.dbusSendpara(ServerName,ServerPath,ServerInterface,"getDiskTotalSizeMiB", DiskName) ;
    dbusConnect = kdbus.dbusConn;
    return res.toDouble();
}

QString Disk::getDiskModel(QString DiskName)
{
    QVariant res = kdbus.dbusSendpara(ServerName,ServerPath,ServerInterface,"getDiskModel", DiskName) ;
    dbusConnect = kdbus.dbusConn;
    return res.toString();
}

QString Disk::getDiskSerial(QString DiskName)
{
    QVariant res = kdbus.dbusSendpara(ServerName,ServerPath,ServerInterface,"getDiskSerial", DiskName) ;
    dbusConnect = kdbus.dbusConn;
    return res.toString();
}

unsigned int Disk::getDiskPartitionNums(QString DiskName)
{
    QVariant res = kdbus.dbusSendpara(ServerName,ServerPath,ServerInterface,"getDiskPartitionNums", DiskName) ;
    dbusConnect = kdbus.dbusConn;
    return res.toUInt();
}