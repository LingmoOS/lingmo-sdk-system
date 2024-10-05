package lingmo.kysdk.java.method;

import lingmo.kysdk.java.client.DBusClient;
import com.lingmo.kysdk.gps;
import org.freedesktop.dbus.connections.impl.DBusConnection;
import org.freedesktop.dbus.exceptions.DBusException;
import lombok.extern.slf4j.Slf4j;

@Slf4j
public class GpsMethod implements gps {

    @Override
    public String getGPSInfo(){
        DBusConnection conn = null;
        try {
            conn = DBusClient.getConn(DBusConnection.DBusBusType.SYSTEM);
            gps obj = conn.getRemoteObject("com.lingmo.kysdk.service",
                    "/com/lingmo/kysdk/gps", gps.class);
            return obj.getGPSInfo();
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
