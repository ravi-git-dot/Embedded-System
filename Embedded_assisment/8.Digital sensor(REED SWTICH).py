import machine
import utime

led = machine.Pin(0, machine.Pin.OUT)
sensor = machine.Pin(19, machine.Pin.IN, machine.Pin.PULL_DOWN)
led_blink = 0

while True:
    if sensor.value() == 1:
        if led_blink<5: 
            led.on()
            utime.sleep(0.1)
            led.off()
            utime.sleep(0.1)
            led_blink = led_blink + 1
            print(f"Magnet Detection {led_blink}")
        else:
            led_blink = 0
    else:
        led.off()
        print("No Magnet Detection")
        utime.sleep(0.5) 