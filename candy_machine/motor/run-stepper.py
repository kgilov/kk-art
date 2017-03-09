#!/usr/bin/env python

import RPi.GPIO as GPIO
import time
import Stepper


# Variables

steps_per_revolution = 200
stepsReload = 320

# Enable pins for IN1-4 to control step sequence

motor_A_1_pin = 4
motor_A_2_pin = 17
motor_B_1_pin = 27
motor_B_2_pin = 22

# Enable button pin

btn_pin = 25

# Set pin states
GPIO.setmode(GPIO.BCM)
GPIO.setwarnings(False)

GPIO.setup(btn_pin, GPIO.IN, GPIO.PUD_UP)



def main():
	myStepper = Stepper.Stepper(steps_per_revolution, motor_A_1_pin, motor_A_2_pin, motor_B_1_pin, motor_B_2_pin)
	myStepper.setSpeed(140)
	myStepper.stop()
	try:
		while True:
			GPIO.wait_for_edge(btn_pin, GPIO.FALLING)
			myStepper.step(stepsReload)
			myStepper.stop()
			time.sleep(0.2)
			
			myStepper.step(-stepsReload)
			myStepper.stop()
			time.sleep(0.2)
					
	except KeyboardInterrupt:
		GPIO.cleanup()

if __name__ == '__main__':
    main()

	
