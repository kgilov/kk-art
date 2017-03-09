#!/usr/bin/env python

import RPi.GPIO as GPIO
import time

GPIO.setmode(GPIO.BCM)
GPIO.setwarnings(False)

class Stepper:

	def __init__(self, n_steps_revolution, motor_A_1_pin, motor_A_2_pin, motor_B_1_pin, motor_B_2_pin):
		
		self.step_number = 0      # which step the motor is on
		self.step_delay = 0        # delay b/w steps to achieve the speed in rpm
		self.direction = 0      # motor direction
		self.last_step_time = 0    # time stamp in ms of the last step taken
		self.step_sequence = ((1,0,1,0),(0,1,1,0),(0,1,0,1),(1,0,0,1))
  
		self.n_steps_revolution = n_steps_revolution
		self.motor_A_1_pin = motor_A_1_pin
		self.motor_A_2_pin = motor_A_2_pin
		self.motor_B_1_pin = motor_B_1_pin
		self.motor_B_2_pin = motor_B_2_pin
		GPIO.setup(self.motor_A_1_pin, GPIO.OUT)
		GPIO.setup(self.motor_A_2_pin, GPIO.OUT)
		GPIO.setup(self.motor_B_1_pin, GPIO.OUT)
		GPIO.setup(self.motor_B_2_pin, GPIO.OUT)

	def setSpeed(self, speed_rpm):
		self.step_delay = 60 * 1000 / self.n_steps_revolution / speed_rpm

	def step(self, steps_move):
		steps_left = abs(steps_move)
		millis = lambda: round(time.time() * 1000,2)
		if (steps_move > 0) :
			self.direction = 1
		if (steps_move < 0) :
			self.direction = 0

		while (steps_left > 0):
			if ((millis() - self.last_step_time) >= self.step_delay):
				self.last_step_time = millis()
				if (self.direction == 1):
					self.step_number += 1
					if (self.step_number == self.n_steps_revolution):
						self.step_number = 0
				else:
					if(self.step_number == 0):
						self.step_number = self.n_steps_revolution
					self.step_number -= 1
				steps_left -= 1
				self.stepMotor(self.step_number % 4)
	
	def stepMotor(self, step):
		GPIO.output(self.motor_A_1_pin, self.step_sequence[step][0])
		GPIO.output(self.motor_A_2_pin, self.step_sequence[step][1])
		GPIO.output(self.motor_B_1_pin, self.step_sequence[step][2])
		GPIO.output(self.motor_B_2_pin, self.step_sequence[step][3])

	def stop(self):
		GPIO.output(self.motor_A_1_pin, 0)
		GPIO.output(self.motor_A_2_pin, 0)
		GPIO.output(self.motor_B_1_pin, 0)
		GPIO.output(self.motor_B_2_pin, 0)
			
			

	
