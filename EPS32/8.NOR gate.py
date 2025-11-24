from machine import Pin
from time import sleep

# Button
button1 = Pin(25, Pin.IN, Pin.PULL_UP)
button2 = Pin(26, Pin.IN, Pin.PULL_UP)

# LEDs
led_red   = Pin(13, Pin.OUT)   # Button1 status
led_blue  = Pin(12, Pin.OUT)   # Button2 status
led_white = Pin(14, Pin.OUT)   # Output LED (NOR)

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
    
    # NOR gate logic
    
    A = (b1 == 0) # assign A as button1 pressed
    B = (b2 == 0) # assign B as button2 pressed
    
    nor_gate = not(A or B)
    
    if nor_gate:
        led_white.on()
    else:
        led_white.off()
    
    sleep(0.5)
    
    
    