#include "netlink.h"

NetLink::NetLink(QWidget *parent) : QWidget(parent)
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
    return res.toUInt();
}


