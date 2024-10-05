package lingmo.kysdk.java.method;
import lingmo.kysdk.java.client.DBusClient;
import  com.lingmo.kysdk.packageinfo;
import lombok.extern.slf4j.Slf4j;
import org.freedesktop.dbus.connections.impl.DBusConnection;
import org.freedesktop.dbus.exceptions.DBusException;

import java.util.List;

@Slf4j
public class PackageInfoMethod implements packageinfo{
    @Override
    public List<String> getPackageList(){
        DBusConnection conn = null;
        try {
            conn = DBusClient.getConn(DBusConnection.DBusBusType.SYSTEM);
            packageinfo obj = conn.getRemoteObject("com.lingmo.kysdk.service",
                    "/com/lingmo/kysdk/packageinfo", packageinfo.class);
            return obj.getPackageList();
        } catch (DBusException e) {
            if (conn != null) conn.disconnect();
            log.error("DBusException GetEUser :",e);
        }
        return null;
    }
    @Override
    public String getPackageVersion(String name){
        DBusConnection conn = null;
        try {
            conn = DBusClient.getConn(DBusConnection.DBusBusType.SYSTEM);
            packageinfo obj = conn.getRemoteObject("com.lingmo.kysdk.service",
                    "/com/lingmo/kysdk/packageinfo", packageinfo.class);
            return obj.getPackageVersion(name);
        } catch (DBusException e) {
            if (conn != null) conn.disconnect();
            log.error("DBusException GetEUser :",e);
        }
        return null;
    }
    @Override
    public int getPackageInstalled(String name,String version){
        DBusConnection conn = null;
        try {
            conn = DBusClient.getConn(DBusConnection.DBusBusType.SYSTEM);
            packageinfo obj = conn.getRemoteObject("com.lingmo.kysdk.service",
                    "/com/lingmo/kysdk/packageinfo", packageinfo.class);
            return obj.getPackageInstalled(name,version);
        } catch (DBusException e) {
            if (conn != null) conn.disconnect();
            log.error("DBusException GetEUser :",e);
        }
        return -1;
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

