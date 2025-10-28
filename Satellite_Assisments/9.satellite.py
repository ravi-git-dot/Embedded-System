import machine
import utime
import uos

from chittiSat.mq2 import MQ2
from chittiSat.gyro import MPU6050
from chittiSat.assistant import *
from chittiSat.pressure import *
from chittiSat.sdcard import *

## i2c Configuration
i2c = machine.I2C(0, scl = machine.Pin(1), sda = machine.Pin(0))
devices = i2c.scan()

if devices:
    print(devices)
    
## MQ2 Sensor
sensor = MQ2(pinData = 26)
sensor.calibrate()

## mpu sensor 
mpu6050 = MPU6050(i2c)

## Pressure
bmp = BMP280(i2c)
calibrate.pressure(bmp)

## SDcard
spi  = machine.SPI(1, sck = machine.Pin(14), mosi = machine.Pin(15), miso = machine.Pin(12))
sd = SDCard(spi)

uos.mount(sd, '/sd')
print("SD card connect successfully!")
print(uos.listdir('/sd'))

## creating new file
my_file = card.newFile(uos.listdir("/sd"))
with open(my_file, "w") as f:
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
    
    f.write("Ax")
    f.write(",")
    
    f.write("Ay")
    f.write(",")
    
    f.write("Az")
    f.write(",")
    
    f.write("Gx")
    f.write(",")
    
    f.write("Gy")
    f.write(",")
    
    f.write("Gz")
    f.write("\n")
    
    while True:
            time = utime.ticks_ms() / 1000  # 1 sec = 1000 ms  
            
            pressure = bmp.pressure
            temperature = bmp.temperature
            
            Smoke = sensor.readSmoke()
            LPG = sensor.readLPG()
            Methane = sensor.readMethane()
            Hydrogen = sensor.readHydrogen()
            
            ax = round(mpu6050.accel.x, 2)
            ay = round(mpu6050.accel.y, 2)
            az = round(mpu6050.accel.z, 2)
            
            gx = round(mpu6050.gyro.x, 2)
            gy = round(mpu6050.gyro.y, 2)
            gz = round(mpu6050.gyro.z, 2)
            
            f.write(str(time))
            f.write(",")
            
            f.write(str(pressure))
            f.write(",")
            
            f.write(str(temperature))
            f.write(",")
            
            f.write(str(Smoke))
            f.write(",")
            
            f.write(str(LPG))
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
            
            print("Our data is saved")
            
            #dashboard.sendWoair(pressure, temperature, ax, ay, az, gx, gy, gz)
            dashboard.sendAll(pressure, temperature, Smoke, LPG, Methane, Hydrogen, ax, ay, az, gx, gy, gz)
            #utime.sleep(0.2)
            
        

