from machine import Pin
from time import sleep

# Buttons
T_btn  = Pin(25, Pin.IN, Pin.PULL_UP)   # T input
CLK_btn = Pin(26, Pin.IN, Pin.PULL_UP)  # Clock input

# Output LED (Q)
Q_led = Pin(13, Pin.OUT)

# initial output state
Q = 0

# to detect clock edge (when button just pressed)
prev_clk = 0

while True:
    # PULL_UP logic:
    # button not pressed -> value() = 1
    # button pressed     -> value() = 0
    # we invert using not:
    # pressed     -> 1
    # not pressed -> 0
    T   = not T_btn.value()
    CLK = not CLK_btn.value()

    # detect rising edge of clock:
    # prev_clk = 0 (not pressed before)
    # CLK     = 1 (just pressed now)
    if CLK == 1 and prev_clk == 0:
        # now one clock pulse happened

        if T == 0:
            # T = 0 -> no change in Q
            pass
        else:
            # T = 1 -> toggle Q
            Q = 1 - Q      # if Q=1 -> 0, if Q=0 -> 1

    # update previous clock value
    prev_clk = CLK

    # update LED based on Q
    if Q == 1:
        Q_led.on()
    else:
        Q_led.off()

    sleep(0.05)  
