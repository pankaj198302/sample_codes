# sample_codes
Sample code list for testing



# Using the Board 



# Flashing the boards with ESP32 Flashing tool





# Creating Partition for OTA

C:\Users\Lenovo\AppData\Local\Arduino15\packages\esp32\hardware\esp32\2.0.9\tools>gen_esp32part.exe --help

usage: gen_esp32part.exe [-h] [--flash-size [{1MB,2MB,4MB,8MB,16MB}]]
                         [--disable-md5sum] [--no-verify] [--verify] [--quiet]
                         [--offset OFFSET] [--secure]
                         input [output]

ESP32 partition table utility

positional arguments:
  input                 Path to CSV or binary file to parse.
  output                Path to output converted binary or CSV file. Will use
                        stdout if omitted.

optional arguments:
  -h, --help            show this help message and exit
  --flash-size [{1MB,2MB,4MB,8MB,16MB}]
                        Optional flash size limit, checks partition table fits
                        in flash
  --disable-md5sum      Disable md5 checksum for the partition table
  --no-verify           Don't verify partition table fields
  --verify, -v          Verify partition table fields (deprecated, this
                        behaviour is enabled by default and this flag does
                        nothing.
  --quiet, -q           Don't print non-critical status messages to stderr
  --offset OFFSET, -o OFFSET
                        Set offset partition table
  --secure              Require app partitions to be suitable for secure boot
  
  #Experimenting with Partition
  
  C:\Users\Lenovo\AppData\Local\Arduino15\packages\esp32\hardware\esp32\2.0.9\tools>gen_esp32part.exe otatest-parxsys.bin
Parsing binary partition input...
Verifying table...
# ESP-IDF Partition Table
# Name, Type, SubType, Offset, Size, Flags
nvs,data,nvs,0x9000,20K,
otadata,data,ota,0xe000,8K,
app0,app,ota_0,0x10000,1M,
app1,app,ota_1,0x150000,640K,
coredump,data,coredump,0x1f0000,64K,

C:\Users\Lenovo\AppData\Local\Arduino15\packages\esp32\hardware\esp32\2.0.9\tools>gen_esp32part.exe partitions
usage: gen_esp32part.exe [-h] [--flash-size [{1MB,2MB,4MB,8MB,16MB}]]
                         [--disable-md5sum] [--no-verify] [--verify] [--quiet]
                         [--offset OFFSET] [--secure]
                         input [output]
gen_esp32part.exe: error: argument input: can't open 'partitions': [Errno 13] Permission denied: 'partitions'

C:\Users\Lenovo\AppData\Local\Arduino15\packages\esp32\hardware\esp32\2.0.9\tools>gen_esp32part.exe partitions\ota-940KB_parxsys.csv partitions\ota-940KB_parxsys.bin
Parsing CSV input...
CSV Error: Partitions overlap. Partition at line 6 sets offset 0x1f0000. Previous partition ends 0x23b000

C:\Users\Lenovo\AppData\Local\Arduino15\packages\esp32\hardware\esp32\2.0.9\tools>gen_esp32part.exe --help
usage: gen_esp32part.exe [-h] [--flash-size [{1MB,2MB,4MB,8MB,16MB}]]
                         [--disable-md5sum] [--no-verify] [--verify] [--quiet]
                         [--offset OFFSET] [--secure]
                         input [output]

ESP32 partition table utility

positional arguments:
  input                 Path to CSV or binary file to parse.
  output                Path to output converted binary or CSV file. Will use
                        stdout if omitted.

optional arguments:
  -h, --help            show this help message and exit
  --flash-size [{1MB,2MB,4MB,8MB,16MB}]
                        Optional flash size limit, checks partition table fits
                        in flash
  --disable-md5sum      Disable md5 checksum for the partition table
  --no-verify           Don't verify partition table fields
  --verify, -v          Verify partition table fields (deprecated, this
                        behaviour is enabled by default and this flag does
                        nothing.
  --quiet, -q           Don't print non-critical status messages to stderr
  --offset OFFSET, -o OFFSET
                        Set offset partition table
  --secure              Require app partitions to be suitable for secure boot

C:\Users\Lenovo\AppData\Local\Arduino15\packages\esp32\hardware\esp32\2.0.9\tools>gen_esp32part.exe partitions\ota-940KB_parxsys.csv
Parsing CSV input...
CSV Error: Partitions overlap. Partition at line 6 sets offset 0x1f0000. Previous partition ends 0x23b000

C:\Users\Lenovo\AppData\Local\Arduino15\packages\esp32\hardware\esp32\2.0.9\tools>gen_esp32part.exe partitions\otatest-parxsys.csv
Parsing CSV input...
Verifying table...
¬P☺☻ÉPnvs¬P☺α otadata¬P►☺►app0¬P◄§
app1¬P☺♥▼☺coredumpδδ              w■c§ñtQÇ·V╥°µ<}∙                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                
C:\Users\Lenovo\AppData\Local\Arduino15\packages\esp32\hardware\esp32\2.0.9\tools>gen_esp32part.exe partitions\otatest-parxsys.bin
usage: gen_esp32part.exe [-h] [--flash-size [{1MB,2MB,4MB,8MB,16MB}]]
                         [--disable-md5sum] [--no-verify] [--verify] [--quiet]
                         [--offset OFFSET] [--secure]
                         input [output]
gen_esp32part.exe: error: argument input: can't open 'partitions\otatest-parxsys.bin': [Errno 2] No such file or directory: 'partitions\\otatest-parxsys.bin'

C:\Users\Lenovo\AppData\Local\Arduino15\packages\esp32\hardware\esp32\2.0.9\tools>gen_esp32part.exe otatest-parxsys.bin
Parsing binary partition input...
Verifying table...
# ESP-IDF Partition Table
# Name, Type, SubType, Offset, Size, Flags
nvs,data,nvs,0x9000,20K,
otadata,data,ota,0xe000,8K,
app0,app,ota_0,0x10000,1M,
app1,app,ota_1,0x150000,640K,
coredump,data,coredump,0x1f0000,64K,

C:\Users\Lenovo\AppData\Local\Arduino15\packages\esp32\hardware\esp32\2.0.9\tools>gen_esp32part.exe partitions\minimal.csv minimal.bin
Parsing CSV input...
Verifying table...

C:\Users\Lenovo\AppData\Local\Arduino15\packages\esp32\hardware\esp32\2.0.9\tools>gen_esp32part.exe minimal.bin
Parsing binary partition input...
Verifying table...
# ESP-IDF Partition Table
# Name, Type, SubType, Offset, Size, Flags
nvs,data,nvs,0x9000,20K,
otadata,data,ota,0xe000,8K,
app0,app,ota_0,0x10000,1280K,
spiffs,data,spiffs,0x150000,640K,
coredump,data,coredump,0x1f0000,64K,

C:\Users\Lenovo\AppData\Local\Arduino15\packages\esp32\hardware\esp32\2.0.9\tools>gen_esp32part.exe minimal.bin
Parsing binary partition input...
Verifying table...
# ESP-IDF Partition Table
# Name, Type, SubType, Offset, Size, Flags
nvs,data,nvs,0x9000,20K,
otadata,data,ota,0xe000,8K,
app0,app,ota_0,0x10000,1280K,
spiffs,data,spiffs,0x150000,640K,
coredump,data,coredump,0x1f0000,64K,

C:\Users\Lenovo\AppData\Local\Arduino15\packages\esp32\hardware\esp32\2.0.9\tools>gen_esp32part.exe partitions\minimal_duplicate.csv minimal_duplicate.bin
Parsing CSV input...
Verifying table...

C:\Users\Lenovo\AppData\Local\Arduino15\packages\esp32\hardware\esp32\2.0.9\tools>gen_esp32part.exe minimal_duplicate.bin
Parsing binary partition input...
Verifying table...
# ESP-IDF Partition Table
# Name, Type, SubType, Offset, Size, Flags
nvs,data,nvs,0x9000,20K,
otadata,data,ota,0xe000,8K,
app0,app,ota_0,0x10000,1280K,
spiffs,data,spiffs,0x150000,640K,

C:\Users\Lenovo\AppData\Local\Arduino15\packages\esp32\hardware\esp32\2.0.9\tools>gen_esp32part.exe partitions\minima_test.csv minimal_test.bin
Parsing CSV input...
Verifying table...

C:\Users\Lenovo\AppData\Local\Arduino15\packages\esp32\hardware\esp32\2.0.9\tools>gen_esp32part.exe minimal_test.bin
Parsing binary partition input...
Verifying table...
# ESP-IDF Partition Table
# Name, Type, SubType, Offset, Size, Flags
nvs,data,nvs,0x9000,20K,
otadata,data,ota,0xe000,8K,
app0,app,ota_0,0x10000,1280K,
spiffs,data,spiffs,0x150000,640K,

C:\Users\Lenovo\AppData\Local\Arduino15\packages\esp32\hardware\esp32\2.0.9\tools>gen_esp32part.exe partitions\minima_test.csv minimal_test.bin
Parsing CSV input...
Verifying table...

C:\Users\Lenovo\AppData\Local\Arduino15\packages\esp32\hardware\esp32\2.0.9\tools>gen_esp32part.exe minimal_duplicate.bin
Parsing binary partition input...
Verifying table...
# ESP-IDF Partition Table
# Name, Type, SubType, Offset, Size, Flags
nvs,data,nvs,0x9000,20K,
otadata,data,ota,0xe000,8K,
app0,app,ota_0,0x10000,1280K,
spiffs,data,spiffs,0x150000,640K,

C:\Users\Lenovo\AppData\Local\Arduino15\packages\esp32\hardware\esp32\2.0.9\tools>gen_esp32part.exe partitions\minima_test.csv minimal_ota.bin
Parsing CSV input...
Verifying table...

C:\Users\Lenovo\AppData\Local\Arduino15\packages\esp32\hardware\esp32\2.0.9\tools>gen_esp32part.exe minimal_ota.bin
Parsing binary partition input...
Verifying table...
# ESP-IDF Partition Table
# Name, Type, SubType, Offset, Size, Flags
nvs,data,nvs,0x9000,20K,
otadata,data,ota,0xe000,8K,
app0,app,ota_0,0x10000,1280K,
spiffs,data,spiffs,0x150000,940K,

C:\Users\Lenovo\AppData\Local\Arduino15\packages\esp32\hardware\esp32\2.0.9\tools>gen_esp32part.exe partitions\minima_test.csv minimal_940KB_ota.bin
Parsing CSV input...
Verifying table...

C:\Users\Lenovo\AppData\Local\Arduino15\packages\esp32\hardware\esp32\2.0.9\tools>gen_esp32part.exe minimal_940KB_ota.bin
Parsing binary partition input...
Verifying table...
# ESP-IDF Partition Table
# Name, Type, SubType, Offset, Size, Flags
nvs,data,nvs,0x9000,20K,
otadata,data,ota,0xe000,8K,
app0,app,ota_0,0x10000,1280K,
app1,app,ota_1,0x150000,940K,

C:\Users\Lenovo\AppData\Local\Arduino15\packages\esp32\hardware\esp32\2.0.9\tools>gen_esp32part.exe minimal_940KB_ota.bin
usage: gen_esp32part.exe [-h] [--flash-size [{1MB,2MB,4MB,8MB,16MB}]]
                         [--disable-md5sum] [--no-verify] [--verify] [--quiet]
                         [--offset OFFSET] [--secure]
                         input [output]
gen_esp32part.exe: error: argument input: can't open 'minimal_940KB_ota.bin': [Errno 2] No such file or directory: 'minimal_940KB_ota.bin'

C:\Users\Lenovo\AppData\Local\Arduino15\packages\esp32\hardware\esp32\2.0.9\tools>gen_esp32part.exe OTA-MQTT-HTTP-NTP.ino.partitions.bin
Parsing binary partition input...
Verifying table...
# ESP-IDF Partition Table
# Name, Type, SubType, Offset, Size, Flags
nvs,data,nvs,0x9000,20K,
otadata,data,ota,0xe000,8K,
app0,app,ota_0,0x10000,1280K,
spiffs,data,spiffs,0x150000,640K,
coredump,data,coredump,0x1f0000,64K,

C:\Users\Lenovo\AppData\Local\Arduino15\packages\esp32\hardware\esp32\2.0.9\tools>gen_esp32part.exe partitions\minima_test.csv ota-test-920KB.bin
Parsing CSV input...
Verifying table...

C:\Users\Lenovo\AppData\Local\Arduino15\packages\esp32\hardware\esp32\2.0.9\tools>gen_esp32part.exe ota-test-920KB.bin
Parsing binary partition input...
Verifying table...
# ESP-IDF Partition Table
# Name, Type, SubType, Offset, Size, Flags
nvs,data,nvs,0x9000,20K,
otadata,data,ota,0xe000,8K,
app0,app,ota_0,0x10000,1280K,
app1,app,ota_1,0x150000,920K,

C:\Users\Lenovo\AppData\Local\Arduino15\packages\esp32\hardware\esp32\2.0.9\tools>gen_esp32part.exe partitions\minima_test.csv ota-test-920KB.bin
Parsing CSV input...
Verifying table...

C:\Users\Lenovo\AppData\Local\Arduino15\packages\esp32\hardware\esp32\2.0.9\tools>gen_esp32part.exe ota-test-920KB.bin
Parsing binary partition input...
Verifying table...
# ESP-IDF Partition Table
# Name, Type, SubType, Offset, Size, Flags
nvs,data,nvs,0x9000,20K,
otadata,data,ota,0xe000,8K,
app0,app,ota_0,0x10000,920K,
app1,app,ota_1,0x150000,920K,

C:\Users\Lenovo\AppData\Local\Arduino15\packages\esp32\hardware\esp32\2.0.9\tools>gen_esp32part.exe ota-test-920KB.bin
Parsing binary partition input...
Verifying table...
# ESP-IDF Partition Table
# Name, Type, SubType, Offset, Size, Flags
nvs,data,nvs,0x9000,20K,
otadata,data,ota,0xe000,8K,
app0,app,ota_0,0x10000,920K,
app1,app,ota_1,0x150000,920K,

C:\Users\Lenovo\AppData\Local\Arduino15\packages\esp32\hardware\esp32\2.0.9\tools>gen_esp32part.exe partitions\minima_test.csv ota-test-950KB.bin
Parsing CSV input...
Verifying table...

C:\Users\Lenovo\AppData\Local\Arduino15\packages\esp32\hardware\esp32\2.0.9\tools>gen_esp32part.exe ota-test-950KB.bin
Parsing binary partition input...
Verifying table...
# ESP-IDF Partition Table
# Name, Type, SubType, Offset, Size, Flags
nvs,data,nvs,0x9000,20K,
otadata,data,ota,0xe000,8K,
app0,app,ota_0,0x10000,1000K,
app1,app,ota_1,0x150000,950K,

C:\Users\Lenovo\AppData\Local\Arduino15\packages\esp32\hardware\esp32\2.0.9\tools>gen_esp32part.exe OTA-MQTT-HTTP-NTP.ino.partitions.bin
Parsing binary partition input...
Verifying table...
# ESP-IDF Partition Table
# Name, Type, SubType, Offset, Size, Flags
nvs,data,nvs,0x9000,20K,
otadata,data,ota,0xe000,8K,
app0,app,ota_0,0x10000,1280K,
spiffs,data,spiffs,0x150000,640K,
coredump,data,coredump,0x1f0000,64K,

C:\Users\Lenovo\AppData\Local\Arduino15\packages\esp32\hardware\esp32\2.0.9\tools>gen_esp32part.exe partitions\minima_test.csv ota-testdefault.bin
Parsing CSV input...
Verifying table...

C:\Users\Lenovo\AppData\Local\Arduino15\packages\esp32\hardware\esp32\2.0.9\tools>gen_esp32part.exe ota-testdefault.bin
Parsing binary partition input...
Verifying table...
# ESP-IDF Partition Table
# Name, Type, SubType, Offset, Size, Flags
nvs,data,nvs,0x9000,20K,
otadata,data,ota,0xe000,8K,
app0,app,ota_0,0x10000,1280K,
spiffs,data,spiffs,0x150000,640K,
coredump,data,coredump,0x1f0000,64K,

C:\Users\Lenovo\AppData\Local\Arduino15\packages\esp32\hardware\esp32\2.0.9\tools>gen_esp32part.exe partitions\minima_test.csv ota-test1180.bin
Parsing CSV input...
Verifying table...

C:\Users\Lenovo\AppData\Local\Arduino15\packages\esp32\hardware\esp32\2.0.9\tools>gen_esp32part.exe ota-test1180.bin
Parsing binary partition input...
Verifying table...
# ESP-IDF Partition Table
# Name, Type, SubType, Offset, Size, Flags
nvs,data,nvs,0x9000,20K,
otadata,data,ota,0xe000,8K,
app0,app,ota_0,0x10000,1180K,
spiffs,data,spiffs,0x150000,640K,
coredump,data,coredump,0x1f0000,64K,

C:\Users\Lenovo\AppData\Local\Arduino15\packages\esp32\hardware\esp32\2.0.9\tools>gen_esp32part.exe partitions\minima_test.csv ota-test1080.bin
Parsing CSV input...
Verifying table...

C:\Users\Lenovo\AppData\Local\Arduino15\packages\esp32\hardware\esp32\2.0.9\tools>gen_esp32part.exe ota-test1080.bin
Parsing binary partition input...
Verifying table...
# ESP-IDF Partition Table
# Name, Type, SubType, Offset, Size, Flags
nvs,data,nvs,0x9000,20K,
otadata,data,ota,0xe000,8K,
app0,app,ota_0,0x10000,1080K,
spiffs,data,spiffs,0x150000,640K,
coredump,data,coredump,0x1f0000,64K,

C:\Users\Lenovo\AppData\Local\Arduino15\packages\esp32\hardware\esp32\2.0.9\tools>gen_esp32part.exe partitions\minima_test.csv ota-test980.bin
Parsing CSV input...
Verifying table...

C:\Users\Lenovo\AppData\Local\Arduino15\packages\esp32\hardware\esp32\2.0.9\tools>gen_esp32part.exe partitions\minima_test.csv ota-test940.bin
Parsing CSV input...
Verifying table...

C:\Users\Lenovo\AppData\Local\Arduino15\packages\esp32\hardware\esp32\2.0.9\tools>gen_esp32part.exe partitions\minima_test.csv ota-test940wocoredata.bin
Parsing CSV input...
Verifying table...

C:\Users\Lenovo\AppData\Local\Arduino15\packages\esp32\hardware\esp32\2.0.9\tools>gen_esp32part.exe ota-test940wocoredata.bin
Parsing binary partition input...
Verifying table...
# ESP-IDF Partition Table
# Name, Type, SubType, Offset, Size, Flags
nvs,data,nvs,0x9000,20K,
otadata,data,ota,0xe000,8K,
app0,app,ota_0,0x10000,940K,
spiffs,data,spiffs,0x150000,640K,

C:\Users\Lenovo\AppData\Local\Arduino15\packages\esp32\hardware\esp32\2.0.9\tools>gen_esp32part.exe partitions\minima_test.csv ota-test940wocoredatawithotapartition.bin
Parsing CSV input...
Verifying table...

C:\Users\Lenovo\AppData\Local\Arduino15\packages\esp32\hardware\esp32\2.0.9\tools>gen_esp32part.exe ota-test940wocoredatawithotapartition.bin
Parsing binary partition input...
Verifying table...
# ESP-IDF Partition Table
# Name, Type, SubType, Offset, Size, Flags
nvs,data,nvs,0x9000,20K,
otadata,data,ota,0xe000,8K,
app0,app,ota_0,0x10000,940K,
app1,app,ota_1,0x150000,640K,

C:\Users\Lenovo\AppData\Local\Arduino15\packages\esp32\hardware\esp32\2.0.9\tools>gen_esp32part.exe partitions\minima_test.csv ota-test940wocoredatawithotapartition940KB.bin
Parsing CSV input...
Verifying table...

C:\Users\Lenovo\AppData\Local\Arduino15\packages\esp32\hardware\esp32\2.0.9\tools>gen_esp32part.exe ota-test940wocoredatawithotapartition.bin
Parsing binary partition input...
Verifying table...
# ESP-IDF Partition Table
# Name, Type, SubType, Offset, Size, Flags
nvs,data,nvs,0x9000,20K,
otadata,data,ota,0xe000,8K,
app0,app,ota_0,0x10000,940K,
app1,app,ota_1,0x150000,640K,

C:\Users\Lenovo\AppData\Local\Arduino15\packages\esp32\hardware\esp32\2.0.9\tools>gen_esp32part.exe ota-test940wocoredatawithotapartition.bin
Parsing binary partition input...
Verifying table...
# ESP-IDF Partition Table
# Name, Type, SubType, Offset, Size, Flags
nvs,data,nvs,0x9000,20K,
otadata,data,ota,0xe000,8K,
app0,app,ota_0,0x10000,940K,
app1,app,ota_1,0x150000,640K,

C:\Users\Lenovo\AppData\Local\Arduino15\packages\esp32\hardware\esp32\2.0.9\tools>gen_esp32part.exe partitions\minima_test.csv ota-test940wocoredatawithotapartitionwooffset.bin
Parsing CSV input...
Verifying table...

C:\Users\Lenovo\AppData\Local\Arduino15\packages\esp32\hardware\esp32\2.0.9\tools>gen_esp32part.exe ota-test940wocoredatawithotapartitionwooffset.bin
Parsing binary partition input...
Verifying table...
# ESP-IDF Partition Table
# Name, Type, SubType, Offset, Size, Flags
nvs,data,nvs,0x9000,20K,
otadata,data,ota,0xe000,8K,
app0,app,ota_0,0x10000,940K,
app1,app,ota_1,0x100000,640K,

C:\Users\Lenovo\AppData\Local\Arduino15\packages\esp32\hardware\esp32\2.0.9\tools>gen_esp32part.exe partitions\minima_test.csv ota-test940wocoredatawithotapartitionwooffset940.bin
Parsing CSV input...
Verifying table...

C:\Users\Lenovo\AppData\Local\Arduino15\packages\esp32\hardware\esp32\2.0.9\tools>gen_esp32part.exe ota-test940wocoredatawithotapartitionwooffset940.bin
Parsing binary partition input...
Verifying table...
# ESP-IDF Partition Table
# Name, Type, SubType, Offset, Size, Flags
nvs,data,nvs,0x9000,20K,
otadata,data,ota,0xe000,8K,
app0,app,ota_0,0x10000,940K,
app1,app,ota_1,0x100000,940K,

C:\Users\Lenovo\AppData\Local\Arduino15\packages\esp32\hardware\esp32\2.0.9\tools>
  

