package lingmo.kysdk.java.method;

import lingmo.kysdk.java.client.DBusClient;
import com.lingmo.kysdk.net;
import lombok.extern.slf4j.Slf4j;
import org.freedesktop.dbus.connections.impl.DBusConnection;
import org.freedesktop.dbus.exceptions.DBusException;
import java.util.List;

@Slf4j
public class NetMethod implements net {

    @Override
    public int getPortState(int port){
        DBusConnection conn = null;
        try {
            conn = DBusClient.getConn(DBusConnection.DBusBusType.SYSTEM);
            net obj = conn.getRemoteObject("com.lingmo.kysdk.service",
                    "/com/lingmo/kysdk/net", net.class);
            return obj.getPortState(port);
        } catch (DBusException e) {
            if (conn != null) conn.disconnect();
            log.error("DBusException GetEUser :",e);
        }
        return -1;
    }
    @Override
    public List<String>  getMultiplePortStat(int begin,int end){
        DBusConnection conn = null;
        try {
            conn = DBusClient.getConn(DBusConnection.DBusBusType.SYSTEM);
            net obj = conn.getRemoteObject("com.lingmo.kysdk.service",
                    "/com/lingmo/kysdk/net", net.class);
            return obj.getMultiplePortStat(begin,end);
        } catch (DBusException e) {
            if (conn != null) conn.disconnect();
            log.error("DBusException GetEUser :",e);
        }
        return null;
    }

    @Override
    public List<String> getGatewayInfo(){
        DBusConnection conn = null;
        try {
            conn = DBusClient.getConn(DBusConnection.DBusBusType.SYSTEM);
            net obj = conn.getRemoteObject("com.lingmo.kysdk.service",
                    "/com/lingmo/kysdk/net", net.class);
            return obj.getGatewayInfo();
        } catch (DBusException e) {
            if (conn != null) conn.disconnect();
            log.error("DBusException GetEUser :",e);
        }
        return null;
    }
    @Override
    public List<String> getFirewallState(){
        DBusConnection conn = null;
        try {
            conn = DBusClient.getConn(DBusConnection.DBusBusType.SYSTEM);
            net obj = conn.getRemoteObject("com.lingmo.kysdk.service",
                    "/com/lingmo/kysdk/net", net.class);
            return obj.getFirewallState();
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
