from machine import Pin
from time import sleep

CLK = Pin(25, Pin.IN, Pin.PULL_UP)
Q0 = Pin(13, Pin.OUT)
Q1 = Pin(12, Pin.OUT)

count = 0  # Start counter at 0
prev = 1   # Used to detect button state change

while True:
    clk = CLK.value()

    # Detect falling edge
    if prev == 1 and clk == 0:
        count = (count + 1) % 4

        #Print the counter value in terminal
        print("Count:", count, " Binary:", f"{count:02b}")

    prev = clk

    # Output to LEDs
    Q0.value(count & 1)
    Q1.value((count >> 1) & 1)

    sleep(0.05)


#Count	Binary	Q1 (MSB)	Q0 (LSB)	What you see
#0	      00	     0	       0	     Both LEDs OFF
#1	      01	     0	       1	     Q0 ON
#2	      10	     1	       0	     Q1 ON
#3	      11	     1	       1	     Both LEDs ON