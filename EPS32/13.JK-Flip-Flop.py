from machine import Pin
from time import sleep

# J(set) button
j_btn = Pin(26, Pin.IN, Pin.PULL_UP)

# K(reset) button
k_btn = Pin(25, Pin.IN, Pin.PULL_UP)

# Clock (Toggle) button
clk_btn = Pin(27, Pin.IN, Pin.PULL_UP)

# Output LED Q
q_led = Pin(13, Pin.OUT)

# starting value of Q
q = 0

# Used to detect when the clock button is just pressed
previous_clock = 0

while True:
    # PULL_UP logic:
    # button not pressed -> value() = 1
    # button pressed     -> value() = 0
    # we invert using not:
    # pressed     -> 1
    # not pressed -> 0
    
    J   = not j_btn.value()    # when pressed -> 1
    K   = not k_btn.value()    # when pressed -> 1
    clk = not clk_btn.value()  # when pressed -> 1
    
    # when clk btn is now pressed (rising edge)
    if clk == 1 and previous_clock == 0:
        
        # JK Flip-Flop rules
        if J == 0 and K == 0:
            # no change
            pass
        
        elif J == 1 and K == 0:
            # set output -> 1
            q = 1
        
        elif J == 0 and K == 1:
            # reset output -> 0
            q = 0
        
        elif J == 1 and K == 1:
            # toggle output
            q = 1 - q
            
    # Save clock state for next loop
    previous_clock = clk
    
    # update the LED
    if q == 1:
        q_led.on()
    else:
        q_led.off()
        
    sleep(0.1)
