import machine
import utime


i2c = machine.I2C(0,scl = machine.Pin(1),sda=machine.Pin(0))
devices = i2c.scan()

if devices:
    print(f"Devices found ,{devices}")
else:
    print(f"No devices found")