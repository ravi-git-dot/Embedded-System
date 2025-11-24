from machine import Pin
from time import sleep

# Input buttons (active LOW)
button1 = Pin(25, Pin.IN, Pin.PULL_UP)
button2 = Pin(26, Pin.IN, Pin.PULL_UP)

# LEDs
# Red   → Button 1 status
# White → Button 2 status
# Blue  → AND gate output

led_red = Pin(13, Pin.OUT)
led_white = Pin(12, Pin.OUT)
led_blue = Pin(14, Pin.OUT)

while True:

    b1 = button1.value()   # 0 = pressed
    b2 = button2.value()   # 0 = pressed

    # LED for Button1
    if b1 == 0:
        led_red.on()
    else:
        led_red.off()

    # LED for Button2
    if b2 == 0:
        led_white.on()
    else:
        led_white.off()

    # AND gate logic: BOTH buttons must be pressed
    if b1 == 0 and b2 == 0:
        led_blue.on()
    else:
        led_blue.off()

    sleep(0.05)
