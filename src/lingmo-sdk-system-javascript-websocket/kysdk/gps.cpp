#include "gps.h"

Gps::Gps(QObject *parent) : QObject(parent)
{
    dbusConnect = -1;
    ServerName = "com.lingmo.kysdk.service";
    ServerInterface = "com.lingmo.kysdk.gps";
    ServerPath = "/com/lingmo/kysdk/gps";
}

QString Gps::getGPSInfo()
{
    QVariant res = kdbus.dbusSend(ServerName,ServerPath,ServerInterface,"getGPSInfo") ;
    dbusConnect = kdbus.dbusConn;
    sendText(QString("%1").arg(res.toString()));
    return res.toString();
}
