from machine import Pin
from time import sleep

button = Pin(25, Pin.IN, Pin.PULL_UP)
led = Pin(13, Pin.OUT)

while True:
    if button.value() == 0:
        led.on()
        print("Button pressed → LED ON")
    else:
        led.off()
        print("LED OFF")
    sleep(0.1)
