import machine
import utime

zero_led = machine.Pin(0, machine.Pin.OUT)
first_led = machine.Pin(1, machine.Pin.OUT)
Score = 1204;
    
while Score > 100:
    zero_led.on()
    utime.sleep(0.5)
    zero_led.off()
    utime.sleep(0.5)
    
    first_led.on()
    utime.sleep(0.5)
    first_led.off()
    utime.sleep(0.5)
    
print("Game over")