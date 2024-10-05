#ifndef BIOS_H
#define BIOS_H

#include <QWidget>
#include <QDBusInterface>
#include <QDBusMessage>
#include <QDebug>
#include <QDBusReply>
#include "kysdkdbus.h"

class Bios : public QObject
{
    Q_OBJECT
public:
    explicit Bios(QObject *parent = nullptr);
    int dbusConnect;
    Kysdkdbus kdbus;
    QString ServerName ;
    QString ServerInterface;
    QString ServerPath;


public slots:
    QString getBiosVendor();
    QString getBiosVersion();

signals:
    void sendText(const QString &text);

};

#endif // BIOS_H
