import machine
import utime

on_board_led =machine.Pin(25, machine.Pin.OUT)

while True:
    on_board_led.on()
    utime.sleep(0.5)
    on_board_led.off()
    utime.sleep(0.5)
    
on_board_led.off()