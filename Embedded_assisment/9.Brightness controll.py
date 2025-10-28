import machine
import utime

sensor = machine.ADC(machine.Pin(27))
led = machine.PWM(machine.Pin(0))  # PWM output


while True:
    value = sensor.read_u16()  # read sensor value
    voltage = value * (0.000056)  # accurate voltage conversion
    print("Voltage: {:.2f} V".format(voltage))
    led.duty_u16(value)  # adjust LED brightness
    utime.sleep(0.1)
