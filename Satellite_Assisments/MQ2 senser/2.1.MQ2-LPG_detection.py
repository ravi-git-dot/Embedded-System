from machine import Pin
from chittiSat.mq2 import MQ2
import utime

# Initialize LED and MQ2 sensor
led = Pin(25, Pin.OUT)       
sensor = MQ2(pinData=26)        

print("Calibrating MQ2 sensor, please wait...")
sensor.calibrate()
print("Calibration complete!\n")

while True:
    Gas = sensor.readLPG()
    print("Gas leakage level:", Gas, "ppm")
    
    if Gas > 10:
        print("LPG Gas Detected!")
        led.on()
    else:
        print("No LPG gas detected.")
        led.off()
    
    utime.sleep(0.5)
    print()
