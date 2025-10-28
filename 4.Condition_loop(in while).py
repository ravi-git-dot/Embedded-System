import machine
import utime

first_led = machine.Pin(0, machine.Pin.OUT)
second_led = machine.Pin(1, machine.Pin.OUT)
blink = 0

while blink < 10:
    utime.sleep(0.1)
    first_led.on()
    utime.sleep(0.2)
    first_led.off()
    utime.sleep(0.2)
    print("First LED ON -- Blink number:", blink)
    
    second_led.on()
    utime.sleep(0.2)
    second_led.off()
    utime.sleep(0.28ii)
    print("Secound Led on -- Blink number:", blink)
    
    blink = blink + 1
    
    
print("Both Led off")
print("Condition limit reached, Have a good day")   