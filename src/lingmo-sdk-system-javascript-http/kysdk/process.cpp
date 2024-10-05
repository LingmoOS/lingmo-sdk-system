#include "process.h"

Process::Process(QWidget *parent) : QWidget(parent)
{
    dbusConnect = -1;
    ServerName = "com.lingmo.kysdk.service";
    ServerInterface = "com.lingmo.kysdk.process";
    ServerPath = "/com/lingmo/kysdk/process";
}

Process::Process(QString urlPath)
{
    dbusConnect = -1;
    ServerName = "com.lingmo.kysdk.service";
    ServerInterface = "com.lingmo.kysdk.process";
    ServerPath = "/com/lingmo/kysdk/process";
    path = urlPath;
    path_list = urlPath.split("?");
}

QJsonObject Process::deal_process()
{
    qDebug()<<"process url path is "<<path;

    if(path_list.size()>1)
    {
        return deal_process_path_para();
    }else{
        return deal_process_path();
    }
}

QJsonObject Process::deal_process_path()
{
    QJsonArray jarray;
    QJsonObject json;
    if(path == "/process/getAllProcInfo")
    {
        QStringList res = getAllProcInfo();
        for(int i=0;i<res.size();i++)
        {
            jarray.append(res[i]);
        }
        json.insert("Result",dbusConnect);
        json.insert("ResultMessage",jarray);
        return json;
    }
}

QJsonObject Process::deal_process_path_para()
{
    QJsonArray jarray;
    QJsonObject json;
    QString pid = path_list[1];
    pid =pid.split("=").last();
    qDebug()<<"pid name is "<<pid;
    if(path_list[0] == "/process/getProcInfoCpuUsage")
    {
        double res = getProcInfoCpuUsage(pid.toInt());
        json.insert("Result",dbusConnect);
        json.insert("ResultMessage",res);
        return json;
    }
    else if(path_list[0] == "/process/getProcInfoMemUsage")
    {
        double res = getProcInfoMemUsage(pid.toInt());
        json.insert("Result",dbusConnect);
        json.insert("ResultMessage",res);
        return json;
    }
    else if(path_list[0] == "/process/getProcInfoStatus")
    {
        QString res = getProcInfoStatus(pid.toInt());
        json.insert("Result",dbusConnect);
        json.insert("ResultMessage",res);
        return json;
    }
    else if(path_list[0] == "/process/getProcInfoPort")
    {
        int res = getProcInfoPort(pid.toInt());
        json.insert("Result",dbusConnect);
        json.insert("ResultMessage",res);
        return json;
    }
    else if(path_list[0] == "/process/getProcInfoStartTime")
    {
        QString res = getProcInfoStartTime(pid.toInt());
        json.insert("Result",dbusConnect);
        json.insert("ResultMessage",res);
        return json;
    }
    else if(path_list[0] == "/process/getProcInfoRunningTime")
    {
        QString res = getProcInfoRunningTime(pid.toInt());
        json.insert("Result",dbusConnect);
        json.insert("ResultMessage",res);
        return json;
    }
    else if(path_list[0] == "/process/getProcInfoCpuTime")
    {
        QString res = getProcInfoCpuTime(pid.toInt());
        json.insert("Result",dbusConnect);
        json.insert("ResultMessage",res);
        return json;
    }
    else if(path_list[0] == "/process/getProcInfoCmd")
    {
        QString res = getProcInfoCmd(pid.toInt());
        json.insert("Result",dbusConnect);
        json.insert("ResultMessage",res);
        return json;
    }
    else if(path_list[0] == "/process/getProcInfoUser")
    {
        QString res = getProcInfoUser(pid.toInt());
        json.insert("Result",dbusConnect);
        json.insert("ResultMessage",res);
        return json;
    }
    else if(path_list[0] == "/process/getProcInfo")
    {
        QStringList res = getProcInfo(pid);
        for(int i=0;i<res.size();i++)
        {
            jarray.append(res[i]);
        }
        json.insert("Result",dbusConnect);
        json.insert("ResultMessage",jarray);
        return json;
    }
}


double Process::getProcInfoCpuUsage(int pid)
{
    QVariant res = kdbus.dbusSendpara(ServerName,ServerPath,ServerInterface,"getProcInfoCpuUsage",pid);
    dbusConnect = kdbus.dbusConn;
    return res.toDouble();
}

double Process::getProcInfoIoUsage(int pid)
{
    QVariant res = kdbus.dbusSendpara(ServerName,ServerPath,ServerInterface,"getProcInfoIoUsage",pid);
    dbusConnect = kdbus.dbusConn;
    return res.toDouble();
}

double Process::getProcInfoMemUsage(int pid)
{
    QVariant res = kdbus.dbusSendpara(ServerName,ServerPath,ServerInterface,"getProcInfoMemUsage",pid);
    dbusConnect = kdbus.dbusConn;
    return res.toDouble();
}

QString Process::getProcInfoStatus(int pid)
{
    QVariant res = kdbus.dbusSendpara(ServerName,ServerPath,ServerInterface,"getProcInfoStatus",pid);
    dbusConnect = kdbus.dbusConn;
    return res.toString();
}

int Process::getProcInfoPort(int pid)
{
    QVariant res = kdbus.dbusSendpara(ServerName,ServerPath,ServerInterface,"getProcInfoPort",pid);
    dbusConnect = kdbus.dbusConn;
    return res.toInt();
}

QString Process::getProcInfoStartTime(int pid)
{
    QVariant res = kdbus.dbusSendpara(ServerName,ServerPath,ServerInterface,"getProcInfoStartTime",pid);
    dbusConnect = kdbus.dbusConn;
    return res.toString();
}

QString Process::getProcInfoRunningTime(int pid)
{
    QVariant res = kdbus.dbusSendpara(ServerName,ServerPath,ServerInterface,"getProcInfoRunningTime",pid);
    dbusConnect = kdbus.dbusConn;
    return res.toString();
}

QString Process::getProcInfoCpuTime(int pid)
{
    QVariant res = kdbus.dbusSendpara(ServerName,ServerPath,ServerInterface,"getProcInfoCpuTime",pid);
    dbusConnect = kdbus.dbusConn;
    return res.toString();
}

QString Process::getProcInfoCmd(int pid)
{
    QVariant res = kdbus.dbusSendpara(ServerName,ServerPath,ServerInterface,"getProcInfoCmd",pid);
    dbusConnect = kdbus.dbusConn;
    return res.toString();
}

QString Process::getProcInfoUser(int pid)
{
    QVariant res = kdbus.dbusSendpara(ServerName,ServerPath,ServerInterface,"getProcInfoUser",pid);
    dbusConnect = kdbus.dbusConn;
    return res.toString();
}

QStringList Process::getProcInfo(QString procName)
{
    QVariant res = kdbus.dbusSendpara(ServerName,ServerPath,ServerInterface,"getProcInfo",procName);
    dbusConnect = kdbus.dbusConn;
    return res.toStringList();
}

QStringList Process::getAllProcInfo()
{
    QVariant res = kdbus.dbusSend(ServerName,ServerPath,ServerInterface,"getAllProcInfo");
    dbusConnect = kdbus.dbusConn;
    return res.toStringList();
}
