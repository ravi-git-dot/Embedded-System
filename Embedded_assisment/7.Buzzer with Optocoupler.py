import machine
import utime

buzzer = machine.Pin(0, machine.Pin.OUT)

while True:
    buzzer.off()