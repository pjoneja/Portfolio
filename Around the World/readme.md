# Around the World NFC Exhibit
In 1936, Herbet Ekins flew around the world flying only on commercially operated flights. This interactive exhibit gives visitors a better understanding of this first-in-history journey that took 18 days. My job as an intern was to replace the old hydraulic and counter-weights system that was powering the exhibit in the past. This system had stopped working many years ago due to it's mechanical complexity. This was by far the most complicated exhibit I designed and built during my internship.

# What it looks like:
Final installation

[![youtube](http://img.youtube.com/vi/7LiJq8QrP9Y/0.jpg)](https://www.youtube.com/watch?v=7LiJq8QrP9Y)

teardown of old hydraulic systems
![online](https://github.com/pjoneja/Portfolio/blob/master/Around%20the%20World/IMG_1013.JPG?raw=true)

back of current build
![online](https://github.com/pjoneja/Portfolio/blob/master/Around%20the%20World/IMG_1127.JPG?raw=true)

testing in the workshop

[![youtube](http://img.youtube.com/vi/4Ho5DEPTds8/0.jpg)](https://www.youtube.com/watch?v=4Ho5DEPTds8)

#How the user interacts
Herbert took 5 flights during his journey. This exhibit breaks down his full trip into those 5 flights. There are five 'boarding passes' in a bucket in front of a map of the world. The user is invited to arrange the boarding passes in the correct order. When the visitor places the first pass in the correct position, the map lights up the path corresponding to the first flight. An embedded screen also responds to show some details about this particular flight. The user then proceeds to place the next four passes in the correct order (using intuition and trial-and-error), and the exhibit responds with lighting up the appropriate path and screen. When the last (fifth) boarding pass is placed in the correct slot, all the passes will be ordered correctly. At this point, the whole path around the world is connected. As a final 'reward', a bell rings three times and a final screen with powerful LED backlights turns on (the "success" lamp). 

#How it works
There are ~~three~~ five subsystems that work together to make this exhibit come together

1. The first subsystem is the NFC readers. There are five readers comprised of an [NFC reader shield](https://www.adafruit.com/products/789) attached to an Arduino Uno. Each arduino corresponds to a position 1-5 in which to place a boarding pass. The arduino is programmed to recognize the presence of a particular NFC tag, which is embedded inside a particular boarding pass. This is the mechanism by which the exhibit recognizes the correct tag. A signal is sent to the central driver when the correct tag is found.
2. The central driver. This subsystem consists of an Arduino Mega that takes inputs from the five readers and sends outputs to the screens, LEDs, bell and success lamp. The logic of central driver is described below. 
3. The LEDs. Behind the world map, strips of LEDs are taped to form an approximate path of the flight that Herbert would have taken. The museum didn't have any historical data on the path of the flights (we checked), so we just approximated a path that looked realistic. The LED strips consist of a series of multicolor LEDs that can be activated programmatically activated. A function in the code for the central driver uses a loop to drive the LEDs. If you watch the video above closely, the path is drawn with a leading red LED and trailed by blue LEDs. This is just a cool effect that was easy to implement with a loop.
4. The screens. The screens are industrial-grade LCDs paired with an SD card reader. Basically, just glorified (and shockingly expensive) digital photo frame. The screens also have an input jack that is intended to be used by a remote. We discovered that sending a LOW signal to the appropriate pin can be used to move from one image to the next. This is the mechanism by which the image on the screen is flipped.
5. The Bell and Success lamp. Both components are simply activated by supplying a signal to their respective transformers. The bell requires a 12V 1.0Amp transformer while the success lamp was powered by a 5V 0.5Amp one.

### Build time
7 days (and an extra three days install time).
