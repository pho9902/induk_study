import RPi.GPIO as GPIO
import time 
from sys import version_ifno

if version_info.major == 3 : 
	raw_input = input

LedPin = 17

def print_message() : 
	print("Press Ctrl + C to end the program")
	raw_input("Press Enter to begin\n")

def setup() :
	GPIO.setmode(GPIO.BCM)
	GPIO.setup(LedPin, GPIO.OUT, initial = GPIO.HIGH)

def main() :
	print_message()
	while true :
		print("LED on")
		GPIO.output(LedPin, GPIO.LOW)
		time.sleep(0.5)
		print("LED off")
		GPIO.output(LedPin, GPIO.HIGH)
		time.sleep(0.5)

def destroy() :
	GPIO.output(LedPin, GPIO.HIGH)
	GPIO.cleanup()

if __name__ == '__main__' :
	setup()
	try : 
		main()
	except KeyboardInterrupt :
		destory()
