#include <QCoreApplication>
#include "kysdkrest.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QDBusConnection con = QDBusConnection::sessionBus();
    KySdkRest res;
    if(!con.registerService("com.lingmo.kysdk.service"))
    {
        qDebug() << "com.lingmo.kysdk.service 服务注册失败";
        return -1;
    }

    if(!con.registerObject("/com/lingmo/kysdk/resolution", &res,
                                  QDBusConnection::ExportAllContents))
    {
        qDebug() << "/com/lingmo/kysdk/resolution 对象注册失败";
        return -1;
    }

    return a.exec();
}
