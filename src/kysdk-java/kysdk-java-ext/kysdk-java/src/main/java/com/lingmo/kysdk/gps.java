package com.lingmo.kysdk;

import org.freedesktop.dbus.interfaces.DBusInterface;

public interface gps extends DBusInterface {
    public String getGPSInfo();
}
