import machine
import utime

from chittiSat.mq2 import MQ2
from chittiSat.assistant import *

# Initialize MQ2 sensor on ADC pin 26
sensor = MQ2(pinData=26)
sensor.calibrate()

while True:
    # Read gas values
    Smoke = sensor.readSmoke()
    Lpg = sensor.readLPG()
    Methane = sensor.readMethane()   
    Hydrogen = sensor.readHydrogen()
    
    # Display readings on serial monitor
    print(f"Smoke value: {Smoke}")
    print(f"LPG leak: {Lpg}")
    print(f"Methane value: {Methane}")
    print(f"Hydrogen value: {Hydrogen}")
    
    # Send readings to dashboard
    dashboard.sendAir(Smoke, Lpg, Methane, Hydrogen)
    
    utime.sleep(0.5)
