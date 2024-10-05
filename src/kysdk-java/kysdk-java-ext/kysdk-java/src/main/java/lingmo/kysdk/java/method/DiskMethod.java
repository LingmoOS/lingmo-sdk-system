package lingmo.kysdk.java.method;

import lingmo.kysdk.java.client.DBusClient;
import com.lingmo.kysdk.disk;
import lombok.extern.slf4j.Slf4j;
import org.freedesktop.dbus.connections.impl.DBusConnection;
import org.freedesktop.dbus.exceptions.DBusException;
import org.freedesktop.dbus.types.UInt32;
import org.freedesktop.dbus.types.UInt64;

import java.util.List;

@Slf4j
public class DiskMethod implements disk {
    @Override
    public List<String> getDiskList() {
        DBusConnection conn = null;
        try {
            conn = DBusClient.getConn(DBusConnection.DBusBusType.SYSTEM);
            disk obj = conn.getRemoteObject("com.lingmo.kysdk.service",
                    "/com/lingmo/kysdk/disk", disk.class);
            return obj.getDiskList();
        } catch (DBusException e) {
            if (conn != null) conn.disconnect();
            log.error("DBusException GetEUser :",e);
        }
        return null;
    }
    @Override
    public UInt32 getDiskSectorSize(String name) {
        DBusConnection conn = null;
        try {
            conn = DBusClient.getConn(DBusConnection.DBusBusType.SYSTEM);
            disk obj = conn.getRemoteObject("com.lingmo.kysdk.service",
                    "/com/lingmo/kysdk/disk", disk.class);
            return obj.getDiskSectorSize(name);
        } catch (DBusException e) {
            if (conn != null) conn.disconnect();
            log.error("DBusException GetEUser :",e);
        }
        return new UInt32(0);
    }
    @Override
    public float getDiskTotalSizeMiB(String name){
        DBusConnection conn = null;
        try {
            conn = DBusClient.getConn(DBusConnection.DBusBusType.SYSTEM);
            disk obj = conn.getRemoteObject("com.lingmo.kysdk.service",
                    "/com/lingmo/kysdk/disk", disk.class);
            return obj.getDiskTotalSizeMiB(name);
        } catch (DBusException e) {
            if (conn != null) conn.disconnect();
            log.error("DBusException GetEUser :",e);
        }
        return -1;
    }
    @Override
    public String getDiskModel(String name){
        DBusConnection conn = null;
        try {
            conn = DBusClient.getConn(DBusConnection.DBusBusType.SYSTEM);
            disk obj = conn.getRemoteObject("com.lingmo.kysdk.service",
                    "/com/lingmo/kysdk/disk", disk.class);
            return obj.getDiskModel(name);
        } catch (DBusException e) {
            if (conn != null) conn.disconnect();
            log.error("DBusException GetEUser :",e);
        }
        return null;
    }
    @Override
    public String getDiskSerial(String name){
        DBusConnection conn = null;
        try {
            conn = DBusClient.getConn(DBusConnection.DBusBusType.SYSTEM);
            disk obj = conn.getRemoteObject("com.lingmo.kysdk.service",
                    "/com/lingmo/kysdk/disk", disk.class);
            return obj.getDiskSerial(name);
        } catch (DBusException e) {
            if (conn != null) conn.disconnect();
            log.error("DBusException GetEUser :",e);
        }
        return null;
    }
    @Override
    public UInt32 getDiskPartitionNums(String name){
        DBusConnection conn = null;
        try {
            conn = DBusClient.getConn(DBusConnection.DBusBusType.SYSTEM);
            disk obj = conn.getRemoteObject("com.lingmo.kysdk.service",
                    "/com/lingmo/kysdk/disk", disk.class);
            return obj.getDiskPartitionNums(name);
        } catch (DBusException e) {
            if (conn != null) conn.disconnect();
            log.error("DBusException GetEUser :",e);
        }
        return new UInt32(0);
    }
    @Override
    public String getDiskType(String name){
        DBusConnection conn = null;
        try {
            conn = DBusClient.getConn(DBusConnection.DBusBusType.SYSTEM);
            disk obj = conn.getRemoteObject("com.lingmo.kysdk.service",
                    "/com/lingmo/kysdk/disk", disk.class);
            return obj.getDiskType(name);
        } catch (DBusException e) {
            if (conn != null) conn.disconnect();
            log.error("DBusException GetEUser :",e);
        }
        return null;
    }

    @Override
    public String getDiskVersion(String name){
        DBusConnection conn = null;
        try {
            conn = DBusClient.getConn(DBusConnection.DBusBusType.SYSTEM);
            disk obj = conn.getRemoteObject("com.lingmo.kysdk.service",
                    "/com/lingmo/kysdk/disk", disk.class);
            return obj.getDiskVersion(name);
        } catch (DBusException e) {
            if (conn != null) conn.disconnect();
            log.error("DBusException GetEUser :",e);
        }
        return null;
    }

    @Override
    public UInt64 getDiskSectorNum(String name){
        DBusConnection conn = null;
        try {
            conn = DBusClient.getConn(DBusConnection.DBusBusType.SYSTEM);
            disk obj = conn.getRemoteObject("com.lingmo.kysdk.service",
                    "/com/lingmo/kysdk/disk", disk.class);
            return obj.getDiskSectorNum(name);
        } catch (DBusException e) {
            if (conn != null) conn.disconnect();
            log.error("DBusException GetEUser :",e);
        }
        return new UInt64(0);
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
