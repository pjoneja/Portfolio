### Problem Statement
![ps1](https://github.com/pjoneja/Portfolio/blob/master/Physics%20Simulations/Visualization%20of%20the%20Solar%20System/ps1.png?raw=true)
![ps2](https://github.com/pjoneja/Portfolio/blob/master/Physics%20Simulations/Visualization%20of%20the%20Solar%20System/ps2.png?raw=true)

### My Approach
In this problem, we are basically writing a python script that runs simply top to bottom. There are barely any user defined functions to create. Since we are working sequentially, the proper sequence is to setup the necessary objects and place them in their initial locations. Once the objects are present, a simple nested-loop can take care of animating frame by frame. This is a strong indication that object-oriented programming is necessary, and since there are many objects, an array of such objects is a good way to manage them.

I think fiddling around with user-defined parameters proved to be quite hard. If I changed the planetary radius factor (c1) then it made the sun overlap other planets in the visualization. If the I changed the orbit radius factor (c3), then the farthest planets force the window to resize and so the closest planets would become too small again. I think even more fiddling with user parameters is necessary.

I decided to add an angular frequency factor (c2) to quickly change the perceived period of orbit. Some plants look quite fast indeed!

[![youtube](http://img.youtube.com/vi/AYdgTquUytY/0.jpg)](https://www.youtube.com/watch?v=AYdgTquUytY)