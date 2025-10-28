import machine
import utime


trigger = machine.Pin(0, machine.Pin.OUT)
echo = machine.Pin(1, machine.Pin.IN, machine.Pin.PULL_DOWN)
buzzer = machine.Pin(3, machine.Pin.OUT)
led_indication = machine.Pin(2, machine.Pin.OUT)
blink = 0

while True:
    trigger.low()
    utime.sleep_us(2)
    trigger.high()
    utime.sleep_us(5)
    trigger.low()

    while echo.value() == 0:
        send = utime.ticks_us()

    while echo.value() == 1:
        received = utime.ticks_us()
        
    duration = received - send

    distance = (duration *0.0343) / 2
    print(f"Distance from Wall: {distance:.2f} cm")
    utime.sleep(0.1) 
    
    if distance < 100:
        buzzer.on()
        if blink < 10 :
            led_indication.on()
            utime.sleep(0.1)
            led_indication.off()
            utime.sleep(0.1)
            blink = blink + 1
        else:
            blink = 0
    else:
        buzzer.off()
