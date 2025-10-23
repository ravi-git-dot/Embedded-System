import machine
import utime
import uos

from chittiSat.sdcard import SDCard
from chittiSat.pressure import BMP280
from chittiSat.assistant import calibrate, card

# Initialize I2C for BMP280
i2c = machine.I2C(0, scl=machine.Pin(1), sda=machine.Pin(0))
devices = i2c.scan()

if devices:
    print("I2C devices found:", devices)
else:
    print("No I2C devices found!")

# Initialize BMP280 sensor
bmp280 = BMP280(i2c)
calibrate.pressure(bmp280)

# Initialize SPI for SD card
spi = machine.SPI(1, sck=machine.Pin(14), mosi=machine.Pin(15), miso=machine.Pin(12))
sd = SDCard(spi)

# Mount SD card
try:
    uos.mount(sd, '/sd')
    print("SD card mounted successfully")
except Exception as e:
    print("Failed to mount SD card:", e)

print("Files on SD card:", uos.listdir('/sd'))

# Create a new file 
myfile = card.newFile(uos.listdir('/sd'))

with open (myfile, "w")  as f:
    
    f.write("Time(ms)")
    f.write(",")
    f.write("Pressure")
    f.write("\n")
    
    while True:
        Pressure = bmp280.pressure
        time = utime.ticks_ms() / 1000
        
        f.write(str(time))
        f.write(",")
        f.write(str(Pressure))
        f.write("\n")
        f.flush()
        
        print("Value Saved successfully in Sd card!")
        utime.sleep(10)