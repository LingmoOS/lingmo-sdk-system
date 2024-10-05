#include "gps.h"

Gps::Gps(QWidget *parent) : QWidget(parent)
{
    dbusConnect = -1;
    ServerName = "com.lingmo.kysdk.service";
    ServerInterface = "com.lingmo.kysdk.gps";
    ServerPath = "/com/lingmo/kysdk/gps";
}

Gps::Gps(QString urlPath)
{
    dbusConnect = -1;
    ServerName = "com.lingmo.kysdk.service";
    ServerInterface = "com.lingmo.kysdk.gps";
    ServerPath = "/com/lingmo/kysdk/gps";
    path = urlPath;
    path_list = urlPath.split("?");
}

QJsonObject Gps::deal_gps()
{
    qDebug()<<"gps url is "<<path;
    return deal_gps_path();
}

QJsonObject Gps::deal_gps_path()
{
    QJsonArray jarray;
    QJsonObject json;
    if(path == "/gps/getGPSInfo")
    {
        QString res = getGPSInfo();
        json.insert("Result",dbusConnect);
        json.insert("ResultMessage",res);
        return json;
    }
}

QString Gps::getGPSInfo()
{
    QVariant res = kdbus.dbusSend(ServerName,ServerPath,ServerInterface,"getGPSInfo") ;
    dbusConnect = kdbus.dbusConn;
    return res.toString();
}
