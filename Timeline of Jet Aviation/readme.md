# Timeline of Jet Aviation exhibit
An interactive video selector. Visitors press numbered buttons to select videos from a large video catalogue. The videos depict the advances in design and technology of jet-powered aircraft, from early, prototypical jets like the Bell XP-59A to a variety of specialized, modern jets like the Lockheed SR-71 and the Airbus A300. The exhibit has a simple design on the surface, but like everything else at the museum, it was necessary to take many more details into account while designing the user interface.

### What it looks like:
![online](https://github.com/pjoneja/Portfolio/blob/master/Timeline%20of%20Jet%20Aviation/IMG_0934.JPG)
![online](https://github.com/pjoneja/Portfolio/blob/master/Timeline%20of%20Jet%20Aviation/IMG_0935.JPG)

### State Machine Design:
The initial state is a welcome screen, inviting the visitor to select a video he/she would like to view. Each video is represented by a two-digit number from 01-92. For videos 01-09, a single digit will suffice. 

The state machine will remain at the initial state until one of the numbered arcade buttons is clicked. When a button is clicked, the machine advances to an intermediate state, inviting the visitor to input the second digit of their selection. This state is designed to have the same user interface as television channel selection:
![online](https://github.com/pjoneja/Portfolio/blob/master/Timeline%20of%20Jet%20Aviation/9_.gif)

When a second digit is pressed, the user's two-digit selection is complete and the machine will play the appropriate video numbered 10-92. If after a 5 second timeout, no second digit is input, the machine will begin to play the appropriate video in the range 01-09. Once the media stops playing, the machine returns to its initial state, awaiting a new input from the user. At any state, the red "back" button can be pressed to return immediately to the initial state. This design feature's purpose is reduce user frustration and provide an way back in case of an input error. Essentially, this is done to keep the user in control.

To make matters a little more complicated, a small number of the videos are actually still images. While observing how museum visitors were using an early prototype, I noticed that some visitors were confused by still images because they were expecting videos instead. They acted as though they thought the machine was buggy or lagging, when it was actually just displaying the still image for about 6 seconds. In their impatience, they would either press erratically on the buttons or simply walk away from the exhibit. This rudimentary user testing phase convinced me that we would need to resolve this. 

Unfortunately, the original designer of the exhibit and the curator of this particular gallery were unable to obtain any moving videos for those selections. To compensate, I came up with the idea of having a small countdown timer that would assure the visitor that the machine was functioning properly, without distracting them too much. I made attempts to make the media player (proprietary BrightSign equipment) display an automatic timer, but quickly learned that this was not a readily available function. In the end, I decided to simply edit the media files themselves to show a small countdown in the top-right corner, similar to the design of Snapchat images. This was a little tedious, but for only a dozen or two files, it was not too bad. 

The end result is a simple state machine which can be imagined as a tree diagram with two layers.  

### How it was implemented:

There are four main components to this exhibit:
* The bank of arcade buttons facing the user, connected to
* An Arduino Due, digitally reading the button states and outputting keyboard strokes over USB to
* A proprietary BrightSign media player, basically a toughened up Roku box that would receive those keyboard strokes and play media from an SD card to
* A screen

Originally, I would have preferred to implement the state machine logic in C++ code on the Arduino and used serial communication to tell the BrightSign player which file to play and for how long. After all, an Arduino is much easier to directly program than a locked-down media player. Unfortunately, a number of factors twisted my arm into letting the BrightSign player be the master instead:
* The BrightSign player requires the use of proprietary BrightAuthor software to load media onto the SD card. This was VERY rudimentary software with a bare-bones GUI and no ability to script/automate actions. In other words I would be forced to select each of the 92 media files along with 10 intermediate states and 1 initial state and manually describe the serial commands each should respond to. One. By. One.
* Ordering an RS-232 shield for the Arduino would be an arduous task, because it would have to go through my supervisor's approval, and then his supervisor's approval, before finally getting shipped about 4-5 business days later. Far too long for such a simple project. 
* BrightSign players are very well suited for use in a media kiosk and such, taking USB inputs from keyboards, mice and even touch screens. There were many supporting functions in the software to suppor this use.

So, since I would have to wrestle with the BrightAuthor software regardless of what I did with an Arduino, it began to make sense to get the arduino to pretend to be a keyboard. All I needed was an Arduino that could spoof keyboard strokes over USB, which is where the Arduino Due came in. Even here, a smaller Arduino Leonardo would have sufficed... but a Due was already in the museum's inventory, whereas a Leonardo would have to be specially ordered. In the end, this project's implementations was largely shaped by the tools/equipment available and the strengths of those particular tools in working together. The big lesson here: adapt yourself for what you have, not for what you prefer. (Of course this lesson should be heeded within limits; if there really is a better tool out there, and it will make your project vastly more reliable/maintainable/simpler, then make a judgment call.)

### Further Notes:
I remembered lessons learned from the previous two exhibits and made sure to debounce the inputs from the arcade buttons. At first, I programmed the arduino with 11 chunks of code that would debounce the button signals and output the appropriate keyboard stroke.  But once again, I found this code to be very long and repetitive. It went against my programmer's instinct of not repeating myself in code. I was quickly able to fold all the code into one 'for' loop. Both versions are included here. They behave identically.



