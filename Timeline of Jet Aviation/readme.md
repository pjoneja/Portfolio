# Timeline of Jet Aviation exhibit
An interactive video selector. Visitors press numbered buttons to select videos from a large video catalogue. The videos depict the advances in design and technology of jet-powered aircraft. The exhibit has a simple design on the surface, but like everything else at the museum, it was necessary to take many more details into account while designing the user interface.

### What it looks like:
![online](https://github.com/pjoneja/Portfolio/blob/master/Timeline%20of%20Jet%20Aviation/IMG_0934.JPG)
![online](https://github.com/pjoneja/Portfolio/blob/master/Timeline%20of%20Jet%20Aviation/IMG_0935.JPG)

### Design and How it works:
This exhibit was designed as a state machine. The initial state is a welcome screen, inviting the visitor to select a video he/she would like to view. Each video is represented by a two-digit number from 01-92. For videos 01-09, a single digit will suffice. 

The state machine will remain at the initial state until one of the numbered arcade buttons is clicked. When a button is clicked, the machine advances to an intermediate state, inviting the visitor to input the second digit of their selection. This state is designed to have the same user interface as television channel selection:
![online](https://github.com/pjoneja/Portfolio/blob/master/Timeline%20of%20Jet%20Aviation/9_.gif)
to telev When a second digit is pressed, the user's two-digit selection is complete and the machine will play the appropriate video numbered 10-92. If after a 5 second timeout, no second digit is input, the machine will begin to play the appropriate video in the range 01-09. 

The end result looks rather simple, and to be honest, the project in itself is a great beginner's tutorial to Arduino. Still, each step required conscious design choices for reliability, maintainability, etc. 

### Further Notes/Improvements:
* The code is admittedly very long and repetitive. It goes against my programmer's instinct of not repeating myself in code. The only thing that changes from line to line is which pins I set HIGH and LOW.
To improve, I could leverage the fact that characters are stored as their ASCII representation, which means I could use a mathematical operations in binary to move from one state to another. For example A is stored as 65 in ASCII, so A + 1 = 66, which is also known as B. 
This feature could be useful in a for loop, allowing me to iterate through each of the 28 states. 
In the end, I followed this repetitive approach because I was on a time crunch to install this exhibit before the museum opened to visitors. After all, 28 states are not that many.
