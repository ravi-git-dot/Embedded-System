import machine
import utime

from chittiSat.gyro import MPU6050
from chittiSat.assistant import *

i2c = machine.I2C(0, sda = machine.Pin(0), scl = machine.Pin(1))

mpu6050 = MPU6050(i2c)

while True:
    # GyroScope - Spped
    gx = round(mpu6050.gyro.x, 2)
    gy = round(mpu6050.gyro.y, 2)
    gz = round(mpu6050.gyro.z, 2)
    # Acceleration - Height
    ax = round(mpu6050.accel.x, 2)
    ay = round(mpu6050.accel.y, 2)
    az = round(mpu6050.accel.z, 2)
    print(f"Gyro -> X:{gx}°/s Y:{gy}°/s Z:{gz}°/s | Accel -> X:{ax}g Y:{ay}g Z:{az}g")
    utime.sleep(1)
