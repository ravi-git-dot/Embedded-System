import machine
import utime

mq2 = machine.ADC(26)

while True:
    smoke_value = mq2.read_u16()
    
    voltage = mq2.read_u16()* (3.3 / 65535)
    
    print(f"Smoke Value is : {smoke_value}")
    print(f"Voltage Value is : {voltage:.2f} V")
    
    utime.sleep(1)
