import machine
import utime

led = machine.Pin(0, machine.Pin.OUT)
sensor = machine.Pin(19, machine.Pin.IN, machine.Pin.PULL_DOWN)
led_blink = 0

while True:
    if sensor.value() == 1:
        print("Magnet Detection")
        for i in range(5):  # blink 5 times
            led.on()
            utime.sleep(0.1)
            led.off()
            utime.sleep(0.1)
        # wait until magnet is removed before detecting again
        while sensor.value() == 1:
            pass
    else:
        led.off()
        print("No Magnet Detection")
        utime.sleep(0.5)