# Pixelator live video camera exhbit
An interactive camera exhibit that demonstrates the concept of pixels and camera resolution. In the context of the the 'Looking at Earth' gallery, this exhibit illustrates how early earth-facing satellites were limited by low resolution, while newer ones can see much greater detail due to advances in camera resolution. The exhibit greatly simplifies the concept, and puts the user in control so that one can understand and interact with the idea of pixels and resolution.

# What it looks like
![online](https://github.com/pjoneja/Portfolio/blob/master/Pixelator/IMG_0907.JPG?raw=true)
The archaic system to be replaced by our Raspberri Pi.
![online](https://github.com/pjoneja/Portfolio/blob/master/Pixelator/IMG_7408.JPG?raw=true)
![online](https://github.com/pjoneja/Portfolio/blob/master/Pixelator/IMG_7407.JPG?raw=true)

Unfortunately, I don't have a picture of the Raspberry Pi we installed. But rest assured, it's a lot smaller than the old system. 

# How it works
* The screen in front of the visitor displays a live video feed of them captured from the Raspberry Pi camera. 
* The visitor is presented with two buttons to select a higher or lower resolution.
* Upon clicking a button, the Raspberry Pi captures a still image of the visitor. The still image is downsampled to the same resolution as displayed before. Onscreen, the downsampled still image is overlaid on top of the live video feed. 
* Then the video feed on the layer below is disabled (by replacing it with pure black). The camera resolution is changed using a built-in function. The new resolution is a constant multiple of the original resolution, with higher or lower resolution depending on the user's choice. The video feed is reinstated, and then the still image on top is removed.

To a viewer, the whole process looks like the screen just freezes for a fraction of a second and then displays the newly selected video feed. 

# Code features
* I made use of some existing libraries to make my job easier. For example, I used PyCamera to capture still images from the RPi camera. I also used Python Imaging Library (PIL) to open and display the saved image on screen. 
* There is an intelligent use of memory resources. Images are only stored temporarily - when a new still is captured, the old one is overwritten. Debugging this memory leak took a lot of fiddling, but I learned how to use the libraries on a deeper level. 
* Again, my knowledge of debouncing signals from the arcade buttons was indispensible in making sure this exhibit worked reliably. 
