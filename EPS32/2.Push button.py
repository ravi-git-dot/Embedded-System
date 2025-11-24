from machine import Pin
from time import sleep

button = Pin(25, Pin.IN, Pin.PULL_UP)   # Change pin if needed

while True:
    if button.value() == 0:
        led.value() == 1# Button pressed
        print("Button PRESSED")
    else:
        print("Button RELEASED")

    sleep(0.2)
