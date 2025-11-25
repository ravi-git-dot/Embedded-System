from machine import Pin
from time import sleep

# Buttons
D = Pin(25, Pin.IN, Pin.PULL_UP)      # Data input
clk = Pin(26, Pin.IN, Pin.PULL_UP)    # Clock input

# Output LED (Q)
Q_led = Pin(13, Pin.OUT)

# initialized output status
Q = 0

while True:
    # Why we use NOT?
    # Because with PULL_UP:
    # - button not pressed -> value = 1
    # - button pressed     -> value = 0
    # But we want:
    # - pressed -> 1
    # - not pressed -> 0
    # So we use NOT to invert
    
    d_val   = not D.value()   # pressed -> 1
    clk_val = not clk.value() # pressed -> 1
    
    # D Flip-Flop operation
    if clk_val == 1:          # clock button pressed
        Q = d_val             # store D input
    
    # update LED according to Q
    if Q == 1:
        Q_led.on()
    else:
        Q_led.off()
        
    sleep(0.1)
