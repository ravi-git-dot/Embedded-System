from machine import Pin
from time import sleep

button1 = Pin(25, Pin.IN, Pin.PULL_UP)
button2 = Pin(26, Pin.IN, Pin.PULL_UP)

led1 = Pin(12, Pin.OUT)
led2 = Pin(13, Pin.OUT)

while True:
    # Button 1 check
    if button1.value() == 0:
        led1.on()
        print("Button1 pressed -> LED1 ON")
    else:
        led1.off()

    # Button 2 check
    if button2.value() == 0:
        led2.on()
        print("Button2 pressed -> LED2 ON")
    else:
        led2.off()

    sleep(0.1)
