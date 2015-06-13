# Capacitive Touch Keyboard Piano exhibit
An interactive exhibit intended to show that the visibile portion of the electromagnetic spectrum is analogous to one octave on a piano. Built using an MPR121 Capacitive Touch Sensor and a VS1053 Music Player Shield w/uSD Card, both from Adafruit, as well as an Arduino. View in person at the Smithsonian National Air and Space Museum in D.C. or watch video here.

### What it looks like
![online](https://github.com/pjoneja/Portfolio/blob/master/Capacitive%20Touch%20Piano/IMG_0865.JPG)
![online](https://github.com/pjoneja/Portfolio/blob/master/Capacitive%20Touch%20Piano/IMG_0866.JPG)
![online](https://github.com/pjoneja/Portfolio/blob/master/Capacitive%20Touch%20Piano/IMG_0869.JPG)

### How it works
* The MPR121 Capacitive Touch/Proximity Sensor measures baseline capacitance in eight electrodes located under the piano surface.
* A visitor places a finger on one of the eight keys. The electromagnetic field from their finger changes the capacitance in the electrode directly below the desired key.
* The sensor detects this change and tells the arduino which key was touched.
* The arduino selects and plays the appropriate file from the SD card attached to the VS1053 Music Player Shield

### How the extended version works
There's a little easter egg I made: If you play *Mary Had A Little Lamb* on the piano keys, the exhibit will follow up with Kenny Loggins' *Danger Zone*
* An array with 26 integer entries is declared
* Each time a key is pressed, its number is stored as the 26th entry. (The keys are numbered 0-7)
* The next time a key is pressed, the entries in the array are rolled back one space, making room for the new entry
* During each loop, the Arduino checks if the entries in the array match a known, constant array that represents *Mary Had A Little Lamb*
* If the corresponding entries in the arrays don't match, the Arduino continues normal operation. If the whole array matches, then the Arduino interrupts normal operation and begins playing *Danger Zone*

This little easter egg is an experiment of mine. If I hear *Danger Zone* going off too frequently because visitors discover my secret, I will uninstall it.
With the museum welcoming over 8 million visitors annually, there is actually a good chance *someone* will find out. If only 0.1% of visitors interact with this tiny exhibit and only 0.1% of those visitors play *Mary Had A Little Lamb*, that's still 8 easter egg discoveries every year.

### Further Notes / Improvements
* In installing this exhibit, there was *a lot* of fiddling with sensitivity threshholds and debounce timing to determine how sensitive the keyboard should be to touch, without playing 'phantom' notes due to ambient changes in the electromagnetic field. The design of the exhibit calls for a 3/8"-thick piece of plexiglass between the electrodes and the top surface where visitors place their fingers. This distance is large enough to require a very high level of sensitivity. In my humble opinion, the plexiglass should be replaced with a conductive material. Or at least, there should be a conductive material inserted into the plexiglass. 
When I brought this up with my supervisor, he told me the folks over at the exhibit design department would probably not take too kindly to an intern, barely 7 days on the job, telling them how to improve the design. I would have hoped that the people designing and the people building these exhibits would have a much closer working relationship.  
