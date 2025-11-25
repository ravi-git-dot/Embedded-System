from machine import Pin
from time import sleep

# D0–D3 inputs (buttons)
D = [
    Pin(25, Pin.IN, Pin.PULL_UP),  # D0
    Pin(26, Pin.IN, Pin.PULL_UP),  # D1
    Pin(27, Pin.IN, Pin.PULL_UP),  # D2
    Pin(14, Pin.IN, Pin.PULL_UP)   # D3
]

# Q0–Q3 outputs (LEDs)
Q = [
    Pin(13, Pin.OUT),  # Q0
    Pin(32, Pin.OUT),  # Q1
    Pin(33, Pin.OUT),  # Q2
    Pin(12, Pin.OUT)   # Q3
]

while True:
    # Read all 4 inputs
    for i in range(4):
        bit = not D[i].value()  # button pressed = 1
        Q[i].value(bit)         # directly update LED

    sleep(0.05)
