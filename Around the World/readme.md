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
Herbert took 5 flights during his journey. This exhibit breaks down his full trip into those 5 flights. There are five 'boarding passes' in a bucket in front of a map of the world. The user is invited to arrange the boarding passes in the correct order. When the visitor places the first pass in the correct position, the map lights up the path corresponding to the first flight. An embedded screen also responds to show some details about this particular flight. The user then proceeds to place the next four passes in the correct order (using intuition and trial-and-error), and the exhibit responds with lighting up the appropriate path and screen. When the last (fifth) boarding pass is placed in the correct slot, all the passes will be ordered correctly. At this point, the whole path around the world is connected. As a final 'reward', a bell rings three times and a final screen with powerful LED backlights turns on. 

#How it works
There are ~~three~~ five subsystems that work together to make this exhibit come together
1. The first subsystem is the NFC readers. There are five readers comprised of an [NFC reader shield](https://www.adafruit.com/products/789) attached to an Arduino Uno. Each arduino corresponds to a position 1-5 in which to place a boarding pass. The arduino is programmed to recognize the presence of a particular NFC tag, which is embedded inside a particular boarding pass. This is the mechanism by which the exhibit recognizes the correct tag. A signal is sent to the central driver when the correct tag is found.
2. The central driver. 
* The screens
* The LEDs
* The Bell and Success light
