import dbus


class SessionBase(object):
    def __init__(self, object_path, interface_name):
        self.bus = dbus.SessionBus()
        self.proxy = self.bus.get_object(
            "com.lingmo.kysdk.service", object_path)
        self.interface = dbus.Interface(
            self.proxy, dbus_interface=interface_name)

class Base(object):

    def __init__(self, object_path, interface_name):
        self.bus = dbus.SystemBus()
        self.proxy = self.bus.get_object(
            "com.lingmo.kysdk.service", object_path)
        self.interface = dbus.Interface(
            self.proxy, dbus_interface=interface_name)


class Disk(Base):

    def __init__(self):
        super().__init__("/com/lingmo/kysdk/disk",
                         "com.lingmo.kysdk.disk")

    def getDiskList(self):
        return self.interface.getDiskList()

    def getDiskSectorSize(self, dev_path):
        return self.interface.getDiskSectorSize(dev_path)

    def getDiskTotalSizeMiB(self, dev_path):
        return self.interface.getDiskTotalSizeMiB(dev_path)

    def getDiskModel(self, dev_path):
        return self.interface.getDiskModel(dev_path)

    def getDiskSerial(self, dev_path):
        return self.interface.getDiskSerial(dev_path)

    def getDiskPartitionNums(self, dev_path):
        return self.interface.getDiskPartitionNums(dev_path)

    def getDiskType(self, dev_path):
        return self.interface.getDiskType(dev_path)

    def getDiskVersion(self, dev_path):
        return self.interface.getDiskVersion(dev_path)

    def getDiskSectorNum(self, dev_path):
        return self.interface.getDiskSectorNum(dev_path)


class Cpuinfo(Base):

    def __init__(self):
        super().__init__("/com/lingmo/kysdk/cpuinfo",
                         "com.lingmo.kysdk.cpuinfo")

    def getCpuArch(self):
        return self.interface.getCpuArch()

    def getCpuVendor(self):
        return self.interface.getCpuVendor()

    def getCpuModel(self):
        return self.interface.getCpuModel()

    def getCpuFreqMHz(self):
        return self.interface.getCpuFreqMHz()

    def getCpuCorenums(self):
        return self.interface.getCpuCorenums()

    def getCpuVirt(self):
        return self.interface.getCpuVirt()

    def getCpuProcess(self):
        return self.interface.getCpuProcess()


class NetCard(Base):

    def __init__(self):
        super().__init__("/com/lingmo/kysdk/netcard",
                         "com.lingmo.kysdk.netcard")

    def getNetCardName(self):
        return self.interface.getNetCardName()

    def getNetCardUp(self, netcard_name):
        return self.interface.getNetCardUp(netcard_name)

    def getNetCardUpcards(self):
        return self.interface.getNetCardUpcards()

    def getNetCardPhymac(self, netcard_name):
        return self.interface.getNetCardPhymac(netcard_name)

    def getNetCardPrivateIPv4(self, netcard_name):
        return self.interface.getNetCardPrivateIPv4(netcard_name)

    def getNetCardIPv4(self, netcard_name):
        return self.interface.getNetCardIPv4(netcard_name)

    def getNetCardPrivateIPv6(self, netcard_name):
        return self.interface.getNetCardPrivateIPv6(netcard_name)

    def getNetCardType(self, netcard_name):
        return self.interface.getNetCardType(netcard_name)

    def getNetCardProduct(self, netcard_name):
        return self.interface.getNetCardProduct(netcard_name)

    def getNetCardIPv6(self, netcard_name):
        return self.interface.getNetCardIPv6(netcard_name)


class Bios(Base):

    def __init__(self):
        super().__init__("/com/lingmo/kysdk/bios",
                         "com.lingmo.kysdk.bios")

    def getBiosVendor(self):
        return self.interface.getBiosVendor()

    def getBiosVersion(self):
        return self.interface.getBiosVersion()


class Mainboard(Base):

    def __init__(self):
        super().__init__("/com/lingmo/kysdk/mainboard",
                         "com.lingmo.kysdk.mainboard")

    def getMainboardName(self):
        return self.interface.getMainboardName()

    def getMainboardDate(self):
        return self.interface.getMainboardDate()

    def getMainboardSerial(self):
        return self.interface.getMainboardSerial()

    def getMainboardVendor(self):
        return self.interface.getMainboardVendor()


class Peripheralsenum(Base):

    def __init__(self):
        super().__init__("/com/lingmo/kysdk/peripheralsenum",
                         "com.lingmo.kysdk.peripheralsenum")

    def getAllUsbInfo(self):
        return self.interface.getAllUsbInfo()


class Packageinfo(Base):

    def __init__(self):
        super().__init__("/com/lingmo/kysdk/packageinfo",
                         "com.lingmo.kysdk.packageinfo")

    def getPackageList(self):
        return self.interface.getPackageList()

    def getPackageVersion(self, package_name):
        return self.interface.getPackageVersion(package_name)

    def getPackageInstalled(self, package_name, version=None):
        return self.interface.getPackageInstalled(package_name, version)


class Resource(Base):

    def __init__(self):
        super().__init__("/com/lingmo/kysdk/resource",
                         "com.lingmo.kysdk.resource")

    def getMemTotalKiB(self):
        return self.interface.getMemTotalKiB()

    def getMemUsagePercent(self):
        return self.interface.getMemUsagePercent()

    def getMemUsageKiB(self):
        return self.interface.getMemUsageKiB()

    def getMemAvailableKiB(self):
        return self.interface.getMemAvailableKiB()

    def getMemFreeKiB(self):
        return self.interface.getMemFreeKiB()

    def getMemVirtAllocKiB(self):
        return self.interface.getMemVirtAllocKiB()

    def getMemSwapTotalKiB(self):
        return self.interface.getMemSwapTotalKiB()

    def getMemSwapUsagePercent(self):
        return self.interface.getMemSwapUsagePercent()

    def getMemSwapUsageKiB(self):
        return self.interface.getMemSwapUsageKiB()

    def getMemSwapFreeKiB(self):
        return self.interface.getMemSwapFreeKiB()

    def getCpuCurrentUsage(self):
        return self.interface.getCpuCurrentUsage()

    def getUpTime(self):
        return self.interface.getUpTime()


class Process(Base):

    def __init__(self):
        super().__init__("/com/lingmo/kysdk/process",
                         "com.lingmo.kysdk.process")

    def getProcInfoCpuUsage(self, pid):
        return self.interface.getProcInfoCpuUsage(pid)

    def getProcInfoMemUsage(self, pid):
        return self.interface.getProcInfoMemUsage(pid)

    def getProcInfoStatus(self, pid):
        return self.interface.getProcInfoStatus(pid)

    def getProcInfoPort(self, pid):
        return self.interface.getProcInfoPort(pid)

    def getProcInfoStartTime(self, pid):
        return self.interface.getProcInfoStartTime(pid)

    def getProcInfoRunningTime(self, pid):
        return self.interface.getProcInfoRunningTime(pid)

    def getProcInfoCpuTime(self, pid):
        return self.interface.getProcInfoCpuTime(pid)

    def getProcInfoCmd(self, pid):
        return self.interface.getProcInfoCmd(pid)

    def getProcInfoUser(self, pid):
        return self.interface.getProcInfoUser(pid)

    def getProcInfo(self, process_name):
        return self.interface.getProcInfo(process_name)

    def getAllProcInfo(self):
        return self.interface.getAllProcInfo()

class GetSysLegalResolution(SessionBase):

    def __init__(self):
        super().__init__("/com/lingmo/kysdk/resolution",
                         "com.lingmo.kysdk.resolution")

    def getSysLegalResolution(self):
        return self.interface.getSysLegalResolution()

class Sysinfo(Base):

    def __init__(self):
        super().__init__("/com/lingmo/kysdk/sysinfo",
                         "com.lingmo.kysdk.sysinfo")

    def getSystemArchitecture(self):
        return self.interface.getSystemArchitecture()

    def getSystemName(self):
        return self.interface.getSystemName()

    def getSystemVersion(self, defatul=0):
        """
        defatul = 0 获取简略版本号
        defatul = 1 获取详细版本号
        """
        return self.interface.getSystemVersion(defatul)

    def getSystemActivationStatus(self):
        return self.interface.getSystemActivationStatus()

    def getSystemSerialNumber(self):
        return self.interface.getSystemSerialNumber()

    def getSystemKernelVersion(self):
        return self.interface.getSystemKernelVersion()

    def getSystemEffectUser(self):
        return self.interface.getSystemEffectUser()

    def getSystemProjectName(self):
        return self.interface.getSystemProjectName()

    def getSystemProjectSubName(self):
        return self.interface.getSystemProjectSubName()

    def getSystemProductFeatures(self):
        return self.interface.getSystemProductFeatures()

    def getSystemHostVirtType(self):
        return self.interface.getSystemHostVirtType()

    def getSystemHostCloudPlatform(self):
        return self.interface.getSystemHostCloudPlatform()

    def getSystemOSVersion(self):
        return self.interface.getSystemOSVersion()

    def getSystemUpdateVersion(self):
        return self.interface.getSystemUpdateVersion()

    def getSystemIsZYJ(self):
        return self.interface.getSystemIsZYJ()

    # def getSysLegalResolution(self):
    #     return self.interface.getSysLegalResolution()


class Net(Base):

    def __init__(self):
        super().__init__("/com/lingmo/kysdk/net",
                         "com.lingmo.kysdk.net")

    def getPortState(self, port):
        return self.interface.getPortState(port)

    def getMultiplePortStat(self, start_port, end_port):
        return self.interface.getMultiplePortStat(start_port, end_port)

    def getGatewayInfo(self):
        return self.interface.getGatewayInfo()

    def getFirewallState(self):
        return self.interface.getFirewallState()


class Runinfo(Base):

    def __init__(self):
        super().__init__("/com/lingmo/kysdk/runinfo",
                         "com.lingmo.kysdk.runinfo")

    def getNetSpeed(self, netcard):
        return self.interface.getNetSpeed(netcard)

    def getDiskRate(self, disk_path):
        return self.interface.getDiskRate(disk_path)

    def getCpuTemperature(self):
        return self.interface.getCpuTemperature()

    def getDiskTemperature(self, disk_path):
        return self.interface.getDiskTemperature(disk_path)


class Gps(Base):

    def __init__(self):
        super().__init__("/com/lingmo/kysdk/gps",
                         "com.lingmo.kysdk.gps")

    def getGPSInfo(self):
        return self.interface.getGPSInfo()


class Print(Base):

    def __init__(self):
        super().__init__("/com/lingmo/kysdk/print",
                         "com.lingmo.kysdk.print")

    def getPrinterList(self):
        return self.interface.getPrinterList()

    def getPrinterAvailableList(self):
        return self.interface.getPrinterAvailableList()

    def setPrinterOptions(self, num, paper_type, cups, option):
        return self.interface.setPrinterOptions(num, paper_type, cups, option)

    def getPrinterPrintLocalFile(self, print_name, file_path):
        return self.interface.getPrinterPrintLocalFile(print_name, file_path)

    def getPrinterCancelAllJobs(self, print_name):
        return self.interface.getPrinterCancelAllJobs(print_name)

    def getPrinterStatus(self, print_name):
        return self.interface.getPrinterStatus(print_name)

    def getPrinterFilename(self, url):
        return self.interface.getPrinterFilename(url)

    def getPrinterJobStatus(self, print_name, jobid):
        return self.interface.getPrinterJobStatus(print_name, jobid)

    def getPrinterDownloadRemoteFile(self, url, path):
        return self.interface.getPrinterDownloadRemoteFile(url, path)
