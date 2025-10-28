import machine
import utime

green_led = machine.Pin(0, machine.Pin.OUT)
red_led = machine.Pin(1, machine.Pin.OUT)

marks = [45, 55, 80, 30, 90]  

for mark in marks:
    print(f"\nChecking mark: {mark}")
    if mark > 50:
        green_led.on()
        red_led.off()
        print("The Student is Pass, Good work keep it up!")
    else:
        red_led.on()
        green_led.off()
        print("The Student is Fail, you can study well next time!")

    utime.sleep(2)
    green_led.off()
    red_led.off()
