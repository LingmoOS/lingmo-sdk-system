#include <QCoreApplication>
#include <QDBusConnection>
#include "logrotate.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QDBusConnection conn = QDBusConnection::systemBus();

    conn.registerService("com.kysdk.base");

    LogRotate logRotate;

    conn.registerObject("/com/kysdk/base/logrotate",&logRotate,QDBusConnection::ExportAllSlots);

    return a.exec();
}
