package com.lingmo.kysdk;

import org.freedesktop.dbus.interfaces.DBusInterface;
import java.util.List;

public interface peripheralsenum extends DBusInterface {
    public List<String> getAllUsbInfo();
}
