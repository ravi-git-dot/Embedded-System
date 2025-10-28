import machine
import utime
from chittiSat.sdcard import *
import uos

# SPI configuration
spi  = machine.SPI(1,sck = machine.Pin(14),mosi = machine.Pin(15), miso = machine.Pin(12))

# Initialize SD card
sd = SDCard(spi)


# Mount SD card to filesystem
uos.mount(sd, "/sd")

print("SD CARD CONNECTED SUCCESSFULLY!")
print("Files and folders in SD card:")
print(uos.listdir("/sd"))

                   