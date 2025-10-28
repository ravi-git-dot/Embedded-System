import machine
import utime
import uos

from chittiSat.mq2 import MQ2
from chittiSat.gyro import MPU6050
from chittiSat.sdcard import *
from chittiSat.pressure import *
from chittiSat.assistant import *

led = machine.Pin(25, machine.Pin.OUT)

#I2C congiration
i2c = machine.I2C(0, scl = machine.Pin(1), sda = machine.Pin(0))
dev = i2c.scan()

# MQ2 sensor (Air quality)
sensor = MQ2(pinData = 26)
sensor.calibrate()

# MPU6050 (Gyro + Accelerometer)
mpu6050 = MPU6050(i2c)

# BMP280 (Pressure + Temperature)
bmp = BMP280(i2c)
calibrate.pressure(bmp)

# SPI for SD Card
spi = machine.SPI(1, sck = machine.Pin(14), mosi= machine.Pin(15),miso= machine.Pin(12))
sd = SDCard(spi)

# Mount SD Card
uos.mount(sd,'/sd') 
print("SD CARD CONNECTED SUCCESSFULLY!")
print(uos.listdir("/sd"))

# create new file
myfile = card.newFile(uos.listdir('/sd'))

with open(myfile, "w") as f:
    f.write("Time")
    f.write(",")
    f.write("Pressure")
    f.write(",")
    f.write("Temperature")
    f.write(",")
    f.write("Smoke")
    f.write(",")
    f.write("LPG")
    f.write(",")
    f.write("Methane")
    f.write(",")
    f.write("Hydrogen")
    f.write(",")
    f.write("ax")
    f.write(",")
    f.write("ay")
    f.write(",")
    f.write("az")
    f.write(",")
    f.write("gx")
    f.write(",")
    f.write("gy")
    f.write(",")
    f.write("gz")
    f.write("\n")#next line
    
    while True:
        current_time = utime.ticks_ms() / 1000
        
        # Read weather data
        pressure = bmp.pressure
        temperature =bmp.temperature
        
        # Read air quality
        Smoke = sensor.readSmoke()
        Lpg = sensor.readLPG()
        Methane = sensor.readMethane()
        Hydrogen = sensor.readHydrogen()
        
        # Read motion data
        gx = round(mpu6050.gyro.x, 2)
        gy = round(mpu6050.gyro.y, 2)
        gz = round(mpu6050.gyro.z, 2)
        
        ax = round(mpu6050.accel.x, 2)
        ay = round(mpu6050.accel.y, 2)
        az = round(mpu6050.accel.z, 2)
        
        # Write data line
        f.write(str(current_time))
        f.write(",")
        f.write(str(pressure))
        f.write(",")
        f.write(str(temperature))
        f.write(",")
        f.write(str(Smoke))
        f.write(",")
        f.write(str(Lpg))
        f.write(",")
        f.write(str(Methane))
        f.write(",")
        f.write(str(Hydrogen))
        f.write(",")
        f.write(str(ax))
        f.write(",")
        f.write(str(ay))
        f.write(",")
        f.write(str(az))
        f.write(",")
        f.write(str(gx))
        f.write(",")
        f.write(str(gy))
        f.write(",")
        f.write(str(gz))
        f.write("\n")
        f.flush()
        
        # Blink LED
        led.toggle()
        utime.sleep(1)





