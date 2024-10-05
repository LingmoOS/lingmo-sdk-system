package lingmo.kysdk.java.method;

import lingmo.kysdk.java.client.DBusClient;
import com.lingmo.kysdk.bios;
import lombok.extern.slf4j.Slf4j;
import org.freedesktop.dbus.connections.impl.DBusConnection;
import org.freedesktop.dbus.exceptions.DBusException;
import java.util.List;

@Slf4j
public class BiosMethod implements bios {

    @Override
    public String getBiosVendor(){
        DBusConnection conn = null;
        try {
            conn = DBusClient.getConn(DBusConnection.DBusBusType.SYSTEM);
            bios obj = conn.getRemoteObject("com.lingmo.kysdk.service",
                    "/com/lingmo/kysdk/bios", bios.class);
            return obj.getBiosVendor();
        } catch (DBusException e) {
            if (conn != null) conn.disconnect();
            log.error("DBusException GetEUser :",e);
        }
        return null;
    }

    @Override
    public String getBiosVersion(){
        DBusConnection conn = null;
        try {
            conn = DBusClient.getConn(DBusConnection.DBusBusType.SYSTEM);
            bios obj = conn.getRemoteObject("com.lingmo.kysdk.service",
                    "/com/lingmo/kysdk/bios", bios.class);
            return obj.getBiosVersion();
        } catch (DBusException e) {
            if (conn != null) conn.disconnect();
            log.error("DBusException GetEUser :",e);
        }
        return null;
    }

    @Override
    public boolean isRemote() {
        return false;
    }

    @Override
    public String getObjectPath() {
        return null;
    }
}
