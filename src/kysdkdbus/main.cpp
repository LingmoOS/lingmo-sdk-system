#include <QCoreApplication>
#include "kysdkdbus.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QDBusConnection connection = QDBusConnection::systemBus();
    if(!connection.registerService("com.lingmo.kysdk.service"))
    {
        qDebug() << "com.lingmo.kysdk.service 服务注册失败";
        return -1;
    }

    KySdkDisk disk;
    if(!connection.registerObject("/com/lingmo/kysdk/disk", &disk,
                                  QDBusConnection::ExportAllContents))
    {
        qDebug() << "/com/lingmo/kysdk/disk 对象注册失败";
        return -1;
    }

    KySdkCpuInfo cpuinfo;
    if(!connection.registerObject("/com/lingmo/kysdk/cpuinfo", &cpuinfo,
                                  QDBusConnection::ExportAllContents))
    {
        qDebug() << "/com/lingmo/kysdk/cpuinfo 对象注册失败";
        return -1;
    }

    KySdkNetCard netcard;
    if(!connection.registerObject("/com/lingmo/kysdk/netcard", &netcard,
                                  QDBusConnection::ExportAllContents))
    {
        qDebug() << "/com/lingmo/kysdk/netcard 对象注册失败";
        return -1;
    }

    KySdkBios bios;
    if(!connection.registerObject("/com/lingmo/kysdk/bios", &bios,
                                  QDBusConnection::ExportAllContents))
    {
        qDebug() << "/com/lingmo/kysdk/bios 对象注册失败";
        return -1;
    }

    KySdkMainBoard mainboard;
    if(!connection.registerObject("/com/lingmo/kysdk/mainboard", &mainboard,
                                  QDBusConnection::ExportAllContents))
    {
        qDebug() << "/com/lingmo/kysdk/mainboard 对象注册失败";
        return -1;
    }

    KySdkPeripheralsEnum peripheralsenum;
    if(!connection.registerObject("/com/lingmo/kysdk/peripheralsenum", &peripheralsenum,
                                  QDBusConnection::ExportAllContents))
    {
        qDebug() << "/com/lingmo/kysdk/peripheralsenum 对象注册失败";
        return -1;
    }

    KySdkPackageInfo packageinfo;
    if(!connection.registerObject("/com/lingmo/kysdk/packageinfo", &packageinfo,
                                  QDBusConnection::ExportAllContents))
    {
        qDebug() << "/com/lingmo/kysdk/packageinfo 对象注册失败";
        return -1;
    }

    KySdkResource resource;
    if(!connection.registerObject("/com/lingmo/kysdk/resource", &resource,
                                  QDBusConnection::ExportAllContents))
    {
        qDebug() << "/com/lingmo/kysdk/resource 对象注册失败";
        return -1;
    }

    KySdkProcess process;
    if(!connection.registerObject("/com/lingmo/kysdk/process", &process,
                                  QDBusConnection::ExportAllContents))
    {
        qDebug() << "/com/lingmo/kysdk/process 对象注册失败";
        return -1;
    }
    
    KySdkResolution resolution;
    if(!connection.registerObject("/com/lingmo/kysdk/sysinfo", &resolution,
                                  QDBusConnection::ExportAllContents))
    {
        qDebug() << "/com/lingmo/kysdk/sysinfo 对象注册失败";
        return -1;
    }

    KySdkNet net;
    if(!connection.registerObject("/com/lingmo/kysdk/net", &net,
                                  QDBusConnection::ExportAllContents))
    {
        qDebug() << "/com/lingmo/kysdk/net 对象注册失败";
        return -1;
    }

    KySdkRunInfo runinfo;
    if(!connection.registerObject("/com/lingmo/kysdk/runinfo", &runinfo,
                                  QDBusConnection::ExportAllContents))
    {
        qDebug() << "/com/lingmo/kysdk/runinfo 对象注册失败";
        return -1;
    }

    KySdkGps gps;
    if(!connection.registerObject("/com/lingmo/kysdk/gps", &gps,
                                  QDBusConnection::ExportAllContents))
    {
        qDebug() << "/com/lingmo/kysdk/gps 对象注册失败";
        return -1;
    }

    KySdkPrint print;
    if(!connection.registerObject("/com/lingmo/kysdk/print", &print,
                                  QDBusConnection::ExportAllContents))
    {
        qDebug() << "/com/lingmo/kysdk/print 对象注册失败";
        return -1;
    }

    // QDBusConnection con = QDBusConnection::sessionBus();
    // KySdkRest res;
    // if(!con.registerObject("/com/lingmo/kysdk/resolution", &res,
    //                               QDBusConnection::ExportAllContents))
    // {
    //     qDebug() << "/com/lingmo/kysdk/resolution 对象注册失败";
    //     return -1;
    // }

    return a.exec();
}
