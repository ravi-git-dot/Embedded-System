import machine
import utime

from chittiSat.pressure import *
from chittiSat.assistant import *

i2c = machine.I2C(0, scl = machine.Pin(1), sda = machine.Pin(0))
devices = i2c.scan()

if devices :
    print(f" Devices is found,{devices}")
else:
    print(f"No devices found")
    
bmp =BMP280(i2c)
calibrate.pressure(bmp)

while True:
    
    pressure = bmp.pressure
    temperature = bmp.temperature
    
    dashboard.sendPressure(pressure, temperature)
    utime.sleep(0.5)
    


