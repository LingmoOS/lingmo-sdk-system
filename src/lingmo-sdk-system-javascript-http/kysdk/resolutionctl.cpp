#include "resolutionctl.h"

Resolutionctl::Resolutionctl(QWidget *parent) : QWidget(parent)
{
    dbusConnect = -1;
    ServerName = "com.lingmo.kysdk.service";
    ServerPath = "/com/lingmo/kysdk/resolution";
    ServerInterface = "com.lingmo.kysdk.resolution";
}



QStringList Resolutionctl::getSysLegalResolution()
{
    QVariant res = kdbus.dbusSend(ServerName,ServerPath,ServerInterface,"getSysLegalResolution") ;
    dbusConnect = kdbus.dbusConn;
    return res.toStringList();
}
