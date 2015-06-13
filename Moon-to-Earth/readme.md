# Moon-to-Earth at Light Speed exhibit
An interactive exhibit showing how long it takes light to travel from the moon to the earth (~1.3 seconds). Built using 28 solid state relays, two 16-output decoders, a bank of LEDs and an Arduino. Written in C/C++. View in person at the Smithsonian National Air and Space Museum in D.C. or watch video here.

### What it looks like:
[![online](http://img.youtube.com/vi/pdLoG8gMEHI/0.jpg)](http://www.youtube.com/watch?v=pdLoG8gMEHI)
![online](https://github.com/pjoneja/Portfolio/blob/master/Moon-to-Earth/IMG_0862.JPG)
![online](https://github.com/pjoneja/Portfolio/blob/master/Moon-to-Earth/IMG_7341.JPG)
![online](https://github.com/pjoneja/Portfolio/blob/master/Moon-to-Earth/IMG_7352.JPG)

### How it works:
The arduino sends a 4-bit signal encoded with information about which LEDs to turn on. The arduino is programmed to wait for 46 milliseconds before advancing to the next state by sending the next 4-bit signal. The decoders receive this signal and select one of 16 outputs to turn LOW. The decoders have a response time in the order of nanoseconds, and so it is negligible in the overall exhibit. The outputs of the decoders are connected to inverted solid state relays, such that a LOW signal means the LED turns ON. This choice of inversion is made to save power consumption and extend the life of the relays. There are two decoders because more than 16 outputs were required. I made use of the "inhibit" pins to turn one of the two decoders off completely while the other is in operation. 
The end result looks rather simple, and to be honest, the project in itself is a great beginner's tutorial to Arduino. Still, each step required conscious design choices for reliability, maintainability, etc. 

### Further Notes/Improvements:
* The code is admittedly very long and repetitive. It goes against my programmer's instinct of not repeating myself in code. The only thing that changes from line to line is which pins I set HIGH and LOW.
To improve, I could leverage the fact that characters are stored as their ASCII representation, which means I could use a mathematical operations in binary to move from one state to another. For example A is stored as 65 in ASCII, so A + 1 = 66, which is also known as B. 
This feature could be useful in a for loop, allowing me to iterate through each of the 28 states. 
In the end, I followed this repetitive approach because I was on a time crunch to install this exhibit before the museum opened to visitors. After all, 28 states are not that many.
