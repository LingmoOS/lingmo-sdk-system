#include "netlink.h"

NetLink::NetLink(QObject *parent) : QObject(parent)
{
    dbusConnect = -1;
    ServerName = "com.lingmo.kysdk.service";
    ServerInterface = "com.lingmo.kysdk.netLink";
    ServerPath = "/com/lingmo/kysdk/netlink";
}

unsigned int NetLink::getNetState()
{

    QVariant res = kdbus.dbusSend(ServerName,ServerPath,ServerInterface,"getNetState");
    dbusConnect = kdbus.dbusConn;
    sendText(QString("%1").arg(QString::number(res.toUInt())));
    return res.toUInt();
}


