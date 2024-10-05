#include <QCoreApplication>
#include <QtWebChannel>
#include <QtWebSockets>
#include <QSettings>
#include "shared/websocketclientwrapper.h"
#include "shared/websockettransport.h"
#include "kysdk/bios.h"
//#include "kysdk/dependence.h"
#include "kysdk/disk.h"
#include "kysdk/gps.h"
#include "kysdk/mainboard.h"
#include "kysdk/net.h"
#include "kysdk/netcard.h"
#include "kysdk/peripheralsenum.h"
#include "kysdk/process.h"
#include "kysdk/resolutionctl.h"
#include "kysdk/runinfo.h"
#include "kysdk/cpuinfo.h"
#include "kysdk/packageinfo.h"
#include "kysdk/resource.h"
#include "kysdk/sysinfo.h"
#include "kysdk/print.h"

#define CONFIG_FILE_NAME "/etc/websocket/kysdk-dbus-websocket.conf"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QSettings settings(CONFIG_FILE_NAME, QSettings::IniFormat);
    settings.beginGroup("WebSocketServer");
    int port = settings.value("port", 12345).toInt();
    settings.endGroup();

    QWebSocketServer server(QStringLiteral("WebSocket Setup !"), QWebSocketServer::NonSecureMode);
    if (!server.listen(QHostAddress::LocalHost, port))
    {
        qFatal("Failed to open web socket server.");
    }
    qDebug() << "port=" << port;

    //wrap WebSocket clients in QWebChannelAbstractTransport objects
    WebSocketClientWrapper clientWrapper(&server);

    // setup the channel
    QWebChannel channel(nullptr);
    QObject::connect(&clientWrapper, &WebSocketClientWrapper::clientConnected,
                     &channel, &QWebChannel::connectTo);

    Bios bios;
    //Dependence dependence;
    Cpuinfo cpuinfo;
    Disk disk;
    Gps gps;
    Mainboard mainboard;
    Net net;
    NetCard netcard;
    Packageinfo packageinfo;
    Peripheralsenum peripheralsenum;
    Print print;
    Process process;
    Resolutionctl resolutionctl;
    Resource resource;
    Runinfo runinfo;
    Sysinfo sysinfo;

    QHash<QString, QObject *> hash;
    hash["bios"] = &bios;
    hash["cpuinfo"] = &cpuinfo;
    //hash["dependence"] = &dependence;
    hash["disk"] = &disk;
    hash["gps"] = &gps;
    hash["mainboard"] = &mainboard;
    hash["net"] = &net;
    hash["netcard"] = &netcard;
    hash["packageinfo"] = &packageinfo;
    hash["peripheralsenum"] = &peripheralsenum;
    hash["print"] = &print;
    hash["process"] = &process;
    hash["resolutionctl"] = &resolutionctl;
    hash["resource"] = &resource;
    hash["runinfo"] = &runinfo;
    hash["sysinfo"] = &sysinfo;
    channel.registerObjects(hash);

    //Widget w;
//    w.show();

//    Screenctl s;
//    s.Open();
//    s.BeginSign();
    return a.exec();
}
