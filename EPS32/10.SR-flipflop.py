from machine import Pin
from time import sleep

# Buttons
S = Pin(25, Pin.IN, Pin.PULL_UP)  # Set
R = Pin(26, Pin.IN, Pin.PULL_UP)  # Reset

# Output LED (Q)
Q_led = Pin(13, Pin.OUT)

# Flip-flop output state
Q = 0

while True:
    s_val = not S.value()   # button press = 1
    r_val = not R.value()   # button press = 1

    # SR Flip-Flop Logic
    if s_val == 0 and r_val == 0:
        pass          # Hold (no change)

    elif s_val == 1 and r_val == 0:
        Q = 1         # Set

    elif s_val == 0 and r_val == 1:
        Q = 0         # Reset

    elif s_val == 1 and r_val == 1:
        print("Invalid State: S=1 and R=1")  # both pressed
        # Do nothing or handle differently

    # Update LED
    if Q == 1:
        Q_led.on()
    else:
        Q_led.off()

    sleep(0.2)
