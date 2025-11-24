from machine import Pin
from time import sleep

# LED Pins
led1 = Pin(12, Pin.OUT)
led2 = Pin(13, Pin.OUT)

# Button Pins (Internal pull-up)
button1 = Pin(25, Pin.IN, Pin.PULL_UP)
button2 = Pin(26, Pin.IN, Pin.PULL_UP)

while True:
    # Button1
    if button1.value() == 0:     # Pressed
        led1.on()
        print("Button1 pressed | value =", button1.value())
    else:
        led1.off()

    # Button2
    if button2.value() == 0:     # Pressed
        led2.on()
        print("Button2 pressed | value =", button2.value())
    else:
        led2.off()

    sleep(0.05)
