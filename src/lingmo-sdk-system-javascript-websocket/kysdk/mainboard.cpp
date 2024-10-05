#include "mainboard.h"

Mainboard::Mainboard(QObject *parent) : QObject(parent)
{
    dbusConnect = -1;
    ServerName = "com.lingmo.kysdk.service";
    ServerInterface = "com.lingmo.kysdk.mainboard";
    ServerPath = "/com/lingmo/kysdk/mainboard";
}


QString Mainboard::getMainboardName()
{
    QVariant res = kdbus.dbusSend(ServerName,ServerPath,ServerInterface,"getMainboardName");
    dbusConnect = kdbus.dbusConn;
    sendText(QString("%1").arg(res.toString()));
    qDebug() << res.toString();
    return res.toString();
}

QString Mainboard::getMainboardDate()
{
    QVariant res = kdbus.dbusSend(ServerName,ServerPath,ServerInterface,"getMainboardDate");
    dbusConnect = kdbus.dbusConn;
    sendText(QString("%1").arg(res.toString()));
    qDebug() << res.toString();
    return res.toString();
}

QString Mainboard::getMainboardSerial()
{
    QVariant res = kdbus.dbusSend(ServerName,ServerPath,ServerInterface,"getMainboardSerial");
    dbusConnect = kdbus.dbusConn;
    sendText(QString("%1").arg(res.toString()));
    qDebug() << res.toString();
    return res.toString();
}

QString Mainboard::getMainboardVendor()
{
    QVariant res = kdbus.dbusSend(ServerName,ServerPath,ServerInterface,"getMainboardVendor");
    dbusConnect = kdbus.dbusConn;
    sendText(QString("%1").arg(res.toString()));
    qDebug() << res.toString();
    return res.toString();
}
