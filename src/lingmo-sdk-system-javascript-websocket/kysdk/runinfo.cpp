#include "runinfo.h"
#include <QDBusReply>

Runinfo::Runinfo(QObject *parent) : QObject(parent)
{
    dbusConnect = -1;
    ServerName = "com.lingmo.kysdk.service";
    ServerInterface = "com.lingmo.kysdk.runinfo";
    ServerPath = "/com/lingmo/kysdk/runinfo";
}

// double Runinfo::getIoSpeed()
// {
//     QVariant res = kdbus.dbusSend(ServerName,ServerPath,ServerInterface,"getIoSpeed");
//     dbusConnect = kdbus.dbusConn;
//     sendText(QString("%1").arg(QString::number(res.toDouble())));
//     return res.toDouble();
// }

double Runinfo::getNetSpeed(QString netcard)
{
    QVariant res = kdbus.dbusSendpara(ServerName,ServerPath,ServerInterface,"getNetSpeed", netcard);
    dbusConnect = kdbus.dbusConn;
    sendText(QString("%1").arg(QString::number(res.toDouble())));
    return res.toDouble();
}

int Runinfo::getDiskRate(QString diskname)
{
    QVariant res = kdbus.dbusSendpara(ServerName,ServerPath,ServerInterface,"getDiskRate", diskname);
    dbusConnect = kdbus.dbusConn;
    sendText(QString("%1").arg(res.toInt()));
    return res.toInt();
}

// double Runinfo::getMainboardTemperature()
// {
//     QVariant res = kdbus.dbusSend(ServerName,ServerPath,ServerInterface,"getMainboardTemperature");
//     dbusConnect = kdbus.dbusConn;
//     sendText(QString("%1").arg(QString::number(res.toDouble())));
//     return res.toDouble();
// }

double Runinfo::getCpuTemperature()
{
    QVariant res = kdbus.dbusSend(ServerName,ServerPath,ServerInterface,"getCpuTemperature");
    dbusConnect = kdbus.dbusConn;
    sendText(QString("%1").arg(QString::number(res.toDouble())));
    return res.toDouble();
}

double Runinfo::getDiskTemperature(QString diskpath)
{
    QVariant res = kdbus.dbusSendpara(ServerName,ServerPath,ServerInterface,"getDiskTemperature",diskpath);
    dbusConnect = kdbus.dbusConn;
    sendText(QString("%1").arg(QString::number(res.toDouble())));
    return res.toDouble();
}
