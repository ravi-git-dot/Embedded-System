from machine import Pin
from time import sleep


# Button
button1 = Pin(25, Pin.IN, Pin.PULL_UP)
button2 = Pin(26, Pin.IN, Pin.PULL_UP)

# LED1 → shows Button 1 status
# LED2 → shows Button 2 status
# LED3 → shows OR gate output
led1 = Pin(12, Pin.OUT)
led2 = Pin(13, Pin.OUT)
led_or = Pin(14, Pin.OUT)

while True:
    # Read buttons
    b1 = button1.value()   # 0 = pressed, 1 = not pressed
    b2 = button2.value()

    # Turn ON LED1 when Button1 is pressed
    if b1 == 0:
        led1.on()
    else:
        led1.off()

    # Turn ON LED2 when Button2 is pressed
    if b2 == 0:
        led2.on()
    else:
        led2.off()

    # OR GATE LOGIC
    # Output is ON if:
    # Button1 is pressed  OR  Button2 is pressed
    if b1 == 0 or b2 == 0:
        led_or.on()        # OR output LED ON
    else:
        led_or.off()       # OR output LED OFF

    sleep(0.05)             # small delay
