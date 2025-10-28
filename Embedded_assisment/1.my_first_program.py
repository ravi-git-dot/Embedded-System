import machine
import utime

bread_board_led = machine.Pin(25, machine.Pin.OUT)

while True:
    utime.sleep(0.1)
    for i in range(5):  # blink 5 times
        bread_board_led.on()
        utime.sleep(0.5)
        bread_board_led.off()
        utime.sleep(0.5)
        print("Successfully run")
