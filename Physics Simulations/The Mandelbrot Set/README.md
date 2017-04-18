### Problem Statement
![ps1](https://github.com/pjoneja/Portfolio/blob/master/Physics%20Simulations/The%Mandelbrot%Set/ps1.png?raw=true)
![ps2](https://github.com/pjoneja/Portfolio/blob/master/Physics%20Simulations/The%Mandelbrot%Set/ps2.png?raw=true)

### My Approach
I had a lot of fun with this problem and decided to take it a step further. The original problem says to plot the points in Mandelbrot Set in black (and the points outside in white). 

This was easy enough, so I took it a step further: plotting how many iterations it took before |z| > 2.0. This allows us to see the finer details of the boundary of the Set. I plotted this using jet so I have beautiful, colorful plots.

My code to plot the Mandelbrot Set is similar in many ways to my code for the Feigenbaum Plot problem in the last homework. The similarities include a function takes the x,y position as an argument and returns how many iterations it took at that point. There is also a nested for loop that iterates over all the points in the NxN array that represents the window. 

I also added some useful features like a window resizing feature (change the left,right,bottom,top constants at the top) and an rough indication of the percent of the total computation that is done. 

Using this window reshaping feature, I zoomed in to the small details of the Mandelbrot Set to explore its fractal nature. See screenshots figure3 to figure6.


figure 0
![fig0](https://github.com/pjoneja/Portfolio/blob/master/Physics%20Simulations/The%Mandelbrot%Set/figure_0.png?raw=true)
figure 1
![fig1](https://github.com/pjoneja/Portfolio/blob/master/Physics%20Simulations/The%Mandelbrot%Set/figure_1.png?raw=true)
figure 2
![fig2](https://github.com/pjoneja/Portfolio/blob/master/Physics%20Simulations/The%Mandelbrot%Set/figure_2.png?raw=true)
figure 3
![fig3](https://github.com/pjoneja/Portfolio/blob/master/Physics%20Simulations/The%Mandelbrot%Set/figure_3.png?raw=true)
figure 4
![fig4](https://github.com/pjoneja/Portfolio/blob/master/Physics%20Simulations/The%Mandelbrot%Set/figure_4.png?raw=true)
figure 5
![fig5](https://github.com/pjoneja/Portfolio/blob/master/Physics%20Simulations/The%Mandelbrot%Set/figure_5.png?raw=true)
figure 6
![fig6](https://github.com/pjoneja/Portfolio/blob/master/Physics%20Simulations/The%Mandelbrot%Set/figure_6.png?raw=true)

