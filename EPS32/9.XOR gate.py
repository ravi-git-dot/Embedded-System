from machine import Pin
from time import sleep

# Button
button1 = Pin(25, Pin.IN, Pin.PULL_UP)
button2 = Pin(26, Pin.IN, Pin.PULL_UP)

# LEDs
led_red   = Pin(13, Pin.OUT)   # Button1 status
led_blue  = Pin(12, Pin.OUT)   # Button2 status
led_white = Pin(14, Pin.OUT)   # Output LED (XOR)

while True:
    
    b1 = button1.value() # 0 pressed
    b2 = button2.value() # 0 pressed
    
    #leds Indication
    if b1 == 0:
        led_red.on()
    else:
        led_red.off()
        
    if b2 == 0:
        led_blue.on()
    else:
        led_blue.off()
    
    # XOR logic
    A = (b1 == 0)   # button1 pressed  1
    B = (b2 == 0)   # button2 pressed  1

    xor_out = (A != B)     # XOR condition: different = 1

    if xor_out:
        led_white.on()
    else:
        led_white.off()

    sleep(0.05)
        