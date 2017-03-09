#!/usr/bin/env python

import time
import datetime
from Segment7 import SevenSegment

# ===========================================================================
# Clock Example
# ===========================================================================
segment = SevenSegment(address=0x70)

# print "Press CTRL+Z to exit"
def writeACDC():
	segment.writeDigit(0, 10)
	segment.writeDigit(1, 12)
	segment.writeDigit(2, 13)
	segment.writeDigit(3, 12)
	time.sleep(2)
	segment.setBrightness(1)
	time.sleep(1)
	segment.setBrightness(15)
	time.sleep(2)
	

def writeSpecial(pos, value, dot=False):
	for x in range(0, value + 1):
		segment.writeDigit(pos, x, dot)
		time.sleep(0.3)
def firstTime():
	now = datetime.datetime.now()
	hour = now.hour
	minute = now.minute
	writeSpecial(0, int(hour / 10))
	writeSpecial(1, hour % 10, dot=True)
	writeSpecial(2, int(minute / 10))
	writeSpecial(3, minute % 10)
	
# Continually update the time on a 4 char, 7-segment display
def main():
	firstTime()
	while(True):
		now = datetime.datetime.now()
		hour = now.hour
		minute = now.minute
		second = now.second
		# Set hours
		segment.writeDigit(0, int(hour / 10))     # Tens
		if (second % 2):
			segment.writeDigit(1, hour % 10, dot=True)          # Ones, # Toggle dot each second right 7-segment dot
		else:
			segment.writeDigit(1, hour % 10)          # Ones
		# Set minutes	
		segment.writeDigit(2, int(minute / 10))   # Tens
		segment.writeDigit(3, minute % 10)        # Ones
	  
		# Wait one second
		time.sleep(1)
if __name__ == '__main__':
  try:
    main()
  except:
    print "Error or Exit."