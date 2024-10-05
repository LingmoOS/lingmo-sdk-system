#include "bios.h"

Bios::Bios(QObject *parent) : QObject(parent)
{
    dbusConnect = -1;
    ServerName = "com.lingmo.kysdk.service";
    ServerPath = "/com/lingmo/kysdk/bios";
    ServerInterface = "com.lingmo.kysdk.bios";

}


QString Bios::getBiosVendor()
{
    QVariant res = kdbus.dbusSend(ServerName,ServerPath,ServerInterface,"getBiosVendor");
    dbusConnect = kdbus.dbusConn;
    sendText(QString("%1").arg(res.toString()));
    qDebug() << res.toString();
    return res.toString();
}

QString Bios::getBiosVersion()
{
    QVariant res = kdbus.dbusSend(ServerName,ServerPath,ServerInterface,"getBiosVersion");
    dbusConnect = kdbus.dbusConn;
    sendText(QString("%1").arg(res.toString()));
    qDebug() << res.toString();
    return res.toString();
}
