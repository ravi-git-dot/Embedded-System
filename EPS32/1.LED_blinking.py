from machine import Pin
from time import sleep

# Use GPIO 12
led1 = Pin(2, Pin.OUT)
led2 = Pin(4, Pin.OUT)

while True:
    led1.value(1) # LED1 ON
    sleep(1)
    led2.value(0)
    sleep(1)
    led1.value(0)  # LED1 OFF
    sleep(1)         
    led2.value(1) 
    sleep(1)
