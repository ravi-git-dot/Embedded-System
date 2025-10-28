import machine
import utime

led = machine.Pin(0, machine.Pin.OUT)

while True:
    utime.sleep(0.1)
    for i in range(5):  # blink 5 times
            led.on()
            utime.sleep(0.1)
            led.off()
            utime.sleep(0.1)
            print("Success fully run")