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

