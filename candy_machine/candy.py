#!/usr/bin/env python

import sys, signal, os, random

sys.path.append('/home/pi/app/candy/motor')
sys.path.append('/home/pi/app/candy/display')

import RPi.GPIO as GPIO
import time
import Stepper
import datetime
from Segment7 import SevenSegment

class TimeoutError(Exception):
    pass
	
	
# Variables

steps_per_revolution = 200
stepsReload = 320
speed = 140

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
GPIO.cleanup()
#pull up set to read 1. When connect to GND - read 0
GPIO.setup(btn_pin, GPIO.IN, GPIO.PUD_UP)  

#set address I2C for display
address = 0x70

segment = SevenSegment(address)
myStepper = Stepper.Stepper(steps_per_revolution, motor_A_1_pin, motor_A_2_pin, motor_B_1_pin, motor_B_2_pin)

def initMotor():
	myStepper.setSpeed(speed)
	myStepper.stop()

def initDisplay():
	segment.writeDigit(0, 0)
	segment.writeDigit(1, 0)
	segment.writeDigit(2, 0)
	segment.writeDigit(3, 0)
	time.sleep(1)
	
	
def writeSpecial(pos, value, dot=False):
	for x in range(0, value + 1):
		segment.writeDigit(pos, x, dot)
		time.sleep(0.3)

def reload():
	myStepper.step(stepsReload)
	myStepper.stop()
	time.sleep(0.2)
		
	myStepper.step(-stepsReload)
	myStepper.stop()
	time.sleep(0.2)

def showNumber():
	##number = 12.34
	try:
		number = getNumber()
	except TimeoutError:
		try:
			number = getNumberFile()
		except IOError:
			number = float(random.randrange(0, 10000)) / 100
			
	num_int = int(number)		
	if (num_int < 100 ):		
		num_float = int((number - num_int) * 100)
		num_0 = int(num_int /10)
		num_1 = num_int % 10
		num_2 = int(num_float /10)
		num_3 = num_float % 10	
		dot_1 = True
		dot_2 = False
	else:
		num_float = int((number - num_int) * 10)
		num_0 = int(num_int /100)
		num_int_tens = num_int % 100
		num_1 = int(num_int_tens /10)
		num_2 = num_int_tens % 10
		num_3 = num_float	
		dot_1 = False
		dot_2 = True
	
	if (num_0 == 0):
		segment.writeDigitRaw(0, 0x00)
	else:
		writeSpecial(0, num_0)
	writeSpecial(1, num_1, dot_1)
	writeSpecial(2, num_2, dot_2)
	writeSpecial(3, num_3)

def handler(signum, frame):
    raise TimeoutError("Couldn't get online connection!")
	
def getNumber():

	# Set the signal handler and a 5-second alarm
	signal.signal(signal.SIGALRM, handler)
	signal.alarm(5)
	try:
		# connect to URL
		# read current number 
	
		# number = ****
	
		number = float(random.randrange(0, 10000)) / 100
	finally:
		signal.alarm(0)          # Disable the alarm
	
	try:
		number = float(number)
	except ValueError:
		number = 12.34
	
	if (number <=0 ):
	  number = 0.01
	if (number >= 1000 ):
	  number = 999.9
	
	try:
		fd = open('number.txt', 'w')
		fd.write(str(number))
		fd.close()
	except IOError:
		pass
	
	return number

def handler2(signum, frame):
	raise IOError("Couldn't open file!")

def getNumberFile():
	# Set the signal handler and a 5-second alarm
	signal.signal(signal.SIGALRM, handler2)
	signal.alarm(5)
	try:
		fd = open('number.txt', 'r')
		number = float(fd.readline())
		fd.close()	
	finally:
		signal.alarm(0)          # Disable the alarm

	return number
	
def totals():
	
	if( not os.path.isfile('totals.txt')):
		fd = open('totals.txt', 'w')
		fd.write('0')
		fd.close()
	
	fd = open('totals.txt', 'r+')		
	number = int(fd.readline()) + 1
	fd.seek(0)
	fd.truncate()
	fd.write(str(number))
	fd.close()
	
	
def main():
	initMotor()
	initDisplay()
	segment.setBrightness(7)

	try:
		while True:
			GPIO.wait_for_edge(btn_pin, GPIO.FALLING)
			segment.clearDisplay()
			segment.setBrightness(15)
			showNumber()
			time.sleep(.5)
			reload()
			time.sleep(2)
			segment.setBrightness(7)
			try:
				totals()    ## save the run to accumulate total runs
			except IOError:
				pass
					
	except KeyboardInterrupt:
		GPIO.cleanup()

if __name__ == '__main__':
    main()

	

