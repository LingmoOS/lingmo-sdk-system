package lingmo.kysdk.java.method;

import lingmo.kysdk.java.client.DBusClient;
import com.lingmo.kysdk.runinfo;
import lombok.extern.slf4j.Slf4j;
import org.freedesktop.dbus.connections.impl.DBusConnection;
import org.freedesktop.dbus.exceptions.DBusException;

@Slf4j
public class RunInfoMethod implements runinfo {
    @Override
    public double getNetSpeed(String nc){
        DBusConnection conn = null;
        try {
            conn = DBusClient.getConn(DBusConnection.DBusBusType.SYSTEM);
            runinfo runinfo = conn.getRemoteObject("com.lingmo.kysdk.service",
                    "/com/lingmo/kysdk/runinfo", com.lingmo.kysdk.runinfo.class);
            return runinfo.getNetSpeed(nc);
        } catch (DBusException e) {
            if (conn != null) conn.disconnect();
            log.error("DBusException GetEUser :",e);
        }
        return -1.0;
    }
    @Override
    public int getDiskRate(String disk){
        DBusConnection conn = null;
        try {
            conn = DBusClient.getConn(DBusConnection.DBusBusType.SYSTEM);
            runinfo runinfo = conn.getRemoteObject("com.lingmo.kysdk.service",
                    "/com/lingmo/kysdk/runinfo", com.lingmo.kysdk.runinfo.class);
            return runinfo.getDiskRate(disk);
        } catch (DBusException e) {
            if (conn != null) conn.disconnect();
            log.error("DBusException GetEUser :",e);
        }
        return -1;
    }
    @Override
    public double getCpuTemperature(){
        DBusConnection conn = null;
        try {
            conn = DBusClient.getConn(DBusConnection.DBusBusType.SYSTEM);
            runinfo obj = conn.getRemoteObject("com.lingmo.kysdk.service",
                    "/com/lingmo/kysdk/runinfo", runinfo.class);
            return obj.getCpuTemperature();
        } catch (DBusException e) {
            if (conn != null) conn.disconnect();
            log.error("DBusException GetEUser :",e);
        }
        return -1.0;
    }

    @Override
    public double getDiskTemperature(String name){
        DBusConnection conn = null;
        try {
            conn = DBusClient.getConn(DBusConnection.DBusBusType.SYSTEM);
            runinfo obj = conn.getRemoteObject("com.lingmo.kysdk.service",
                    "/com/lingmo/kysdk/runinfo", runinfo.class);
            return obj.getDiskTemperature(name);
        } catch (DBusException e) {
            if (conn != null) conn.disconnect();
            log.error("DBusException GetEUser :",e);
        }
        return -1.0;
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
