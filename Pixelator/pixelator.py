import RPi.GPIO as GPIO
import time
from time import sleep
import picamera
import PIL
from PIL import Image

GPIO.setmode(GPIO.BCM)
GPIO.setup(4, GPIO.IN)
GPIO.setup(17, GPIO.IN)
GPIO.setup(9, GPIO.IN)

pixelsize = 0
prev_plus = 0
prev_minus = 0

h1 = 26
v1 = 18
h = [h1,2*h1,3*h1,6*h1,12*h1,48*h1]
v = [v1,2*v1,3*v1,6*v1,12*v1,48*v1]

camera = picamera.PiCamera()
camera.vflip = True
camera.image_effect = 'denoise'
camera.led = False
camera.resolution = (h[0],v[0])
camera.start_preview()

try:
	while True:
		plus = GPIO.input(17)
		minus = GPIO.input(4)
		if ((not prev_plus) and plus):
    	if (pixelsize < 5):
				pixelsize += 1
        if (pixelsize == 1):
          img = Image.open('black.png')
        else:
          camera.capture('cap.png')
          img = Image.open('cap.png')
          pad = Image.new('RGB', (
          ((img.size[0] + 31) // 32) * 32,
          ((img.size[1] + 15) // 16) * 16,
          ))
        pad.paste(img, (0, 0))
        o = camera.add_overlay(pad.tostring(), size=img.size)
        o.alpha = 255
        o.layer = 3
    		camera.resolution = (h[pixelsize],v[pixelsize])
    		sleep(0.1)
    		camera.remove_overlay(o)
		if ((not prev_minus) and minus):
			if (pixelsize > 0):			
				pixelsize -= 1
				if (pixelsize == 4):
          img = Image.open('black.png')
        else:
          camera.capture('cap.png')
          img = Image.open('cap.png')
          pad = Image.new('RGB', (
          ((img.size[0] + 31) // 32) * 32,
          ((img.size[1] + 15) // 16) * 16,
          ))
        pad.paste(img, (0, 0))
        o = camera.add_overlay(pad.tostring(), size=img.size)
        o.alpha = 255
        o.layer = 3
				camera.resolution = (h[pixelsize],v[pixelsize])
				sleep(0.1)
				camera.remove_overlay(o)
		if (GPIO.input(9)):
			quit()
		prev_plus = plus
		prev_minus = minus
		time.sleep(0.05)

except KeyboardInterrupt:
	print "\nKeyboardInterrupt"

except:
	print "\nOther error"

finally:
	GPIO.cleanup()
	camera.close()
