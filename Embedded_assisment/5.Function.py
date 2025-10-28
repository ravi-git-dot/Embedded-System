import machine
import utime

zero_led = machine.Pin(0, machine.Pin.OUT)
first_led = machine.Pin(1, machine.Pin.OUT)

def led():
    blink = 0

    while blink<10:
        zero_led.on()
        utime.sleep(0.1)
        zero_led.off()
        utime.sleep(0.1)
        
        first_led.on()
        utime.sleep(0.1)
        first_led.off()
        utime.sleep(0.1)
        
        blink = blink + 1
led()    
print("Hi!!!")

led()
print("Ravi!!!")

led()
print("Hello!!!")

led()
print("Raj!!!!")

led()
print("Have a Good Day!!!")
