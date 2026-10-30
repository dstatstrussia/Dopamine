=== FULL iPHONE DEBUG EXTRACTION ===
UDID: 00008140-001829642189801C
Device: iPhoneOverLordKDOne / V59AP / iPhone17,5
iOS: 27.2 (Build 24B119)
CPU: arm64e
ChipID: 33088
Baseband: 3.02.02

=== libimobiledevice Tools Used ===
BasebandCertId: 4
BasebandKeyHashInformation: AKeyStatus: 0
 SKeyStatus: 2
BasebandSerialNumber: HmB7NBFEGQAAAAAA
BasebandVersion: 3.02.02
BoardId: 4
BuildVersion: 24B119
CPUArchitecture: arm64e
ChipID: 33088
DeviceClass: iPhone
DeviceColor: 1
DeviceName: iPhoneOverLordKDOne
DieID: 6800909477183516
HardwareModel: V59AP
HasSiDP: true
HumanReadableProductVersionString: 27.2
PartitionType: GUID_partition_scheme
ProductName: iPhone OS
ProductType: iPhone17,5
ProductVersion: 27.2
ProductionSOC: true
ProtocolVersion: 2
SupportedDeviceFamilies[1]:
 0: 1
TelephonyCapability: true
UniqueChipID: 6800909477183516
UniqueDeviceID: 00008140-001829642189801C
WiFiAddress: dc:95:66:74:48:06

=== idevice_id ===
00008140-001829642189801C
=== idevicename ===
iPhoneOverLordKDOne
Usage: idevicedebug [OPTIONS] COMMAND

Interact with the debugserver service of a device.

Where COMMAND is one of:
  run BUNDLEID [ARGS...]  run app with BUNDLEID and optional ARGS on device.
  kill BUNDLEID           kill app with BUNDLEID

The following OPTIONS are accepted:
  -u, --udid UDID       target specific device by UDID
  -n, --network         connect to network device
      --detach          detach from app after launch, keeping it running
  -e, --env NAME=VALUE  set environment variable NAME to VALUE
  -d, --debug           enable communication debugging
  -h, --help            prints usage information
  -v, --version         prints version information

Homepage:    <https://libimobiledevice.org>
Bug Reports: <https://github.com/libimobiledevice/libimobiledevice/issues>
=== idevicedebug available ===
Usage: idevicesyslog [OPTIONS]

Relay syslog of a connected device.

OPTIONS:
  -u, --udid UDID       target specific device by UDID
  -n, --network         connect to network device
  -x, --exit            exit when device disconnects
  -h, --help            prints usage information
  -d, --debug           enable communication debugging
  -v, --version         prints version information
  --no-colors           disable colored output
  -o, --output FILE     write to FILE instead of stdout
                        (existing FILE will be overwritten)
  --colors              force writing colored output, e.g. for --output
  --syslog-relay        force use of syslog_relay service

COMMANDS:
  pidlist               Print pid and name of all running processes.
  archive PATH          Request a logarchive and write it to PATH.
                        Output can be piped to another process using - as PATH.
                        The file data will be in .tar format.
    --start-time VALUE  start time of the log data as UNIX timestamp
    --age-limit VALUE   maximum age of the log data
    --size-limit VALUE  limit the size of the archive

FILTER OPTIONS:
  -m, --match STRING      only print messages that contain STRING
  -M, --unmatch STRING    print messages that not contain STRING
  -t, --trigger STRING    start logging when matching STRING
  -T, --untrigger STRING  stop logging when matching STRING
  -p, --process PROCESS   only print messages from matching process(es)
  -e, --exclude PROCESS   print all messages except matching process(es)
                          PROCESS is a process name or multiple process names
                          separated by "|".
  -q, --quiet             set a filter to exclude common noisy processes
  --quiet-list            prints the list of processes for --quiet and exits
  -k, --kernel            only print kernel messages
  -K, --no-kernel         suppress kernel messages

For filter examples consult idevicesyslog(1) man page.

Homepage:    <https://libimobiledevice.org>
Bug Reports: <https://github.com/libimobiledevice/libimobiledevice/issues>
=== idevicesyslog available ===
Usage: idevicecrashreport [OPTIONS] DIRECTORY

Move crash reports from device to a local DIRECTORY.

OPTIONS:
=== idevicecrashreport ===
=== idevicescreenshot ===
Usage: idevicescreenshot [OPTIONS] [FILE]

Gets a screenshot from a connected device.

The image is in PNG format for iOS 9+ and otherwise in TIFF format.
