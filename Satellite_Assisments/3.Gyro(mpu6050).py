import machine
import utime

from chittiSat.gyro import *
from chittiSat.assistant import *

i2c =machine.I2C(0, scl = machine.Pin(1), sda = machine.Pin(0))
mpu = MPU6050(i2c)

while True:
    # Read gyro values
    gx = round(mpu.gyro.x, 2)
    gy = round(mpu.gyro.y, 2)
    gz = round(mpu.gyro.z, 2)
    
    # Read accelerometer values
    ax = round(mpu.accel.x, 2)
    ay = round(mpu.accel.y, 2)
    az = round(mpu.accel.z, 2)
    
    # Send data to dashboard
    dashboard.sendGyro(gx, gy, gz, ax, ay, az)
    utime.sleep(0.5)
    