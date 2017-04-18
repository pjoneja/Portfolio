### Problem Statement
![ps1](https://github.com/pjoneja/Portfolio/blob/master/Physics%20Simulations/Trapezoidal%20and%20Romberg%20Integration/ps1.png?raw=true)

### My Approach
This was my first attempt at adaptive integration techniques

### Part 1: Adaptive Trapezoid Method

![trap](https://github.com/pjoneja/Portfolio/blob/master/Physics%20Simulations/Trapezoidal%20and%20Romberg%20Integration/trap.png?raw=true)

As you can see, the adaptive trapezoid method needs N = 4096 slices before it meets the target error of 1e-06. 

The adaptive method needs to be initialized with good guesses. The most straightforward way was to start at N=1, where the estimated value of the integral is simply a trapezoid from f(a) to f(b). That is what is happening in prev_I on line 23.

My approach for the adaptive part was to set up a Boolean accuracy_reached that represents whether the desired error has been reached. As such, accuracy_reached is initialized as False. 

Accuracy_reached needs to be flipped to True when the current error < target error. This condition needs to be checked during every iteration.

My adaptive integration runs while accuracy_reached is False. In this sense, it’s a do-while loop—the code in the do-while loop needs to run at least once.


### Part 2: Romberg Integration

![romberg](https://github.com/pjoneja/Portfolio/blob/master/Physics%20Simulations/Trapezoidal%20and%20Romberg%20Integration/romberg.png?raw=true)

The Romberg Method only requires the 7th Romberg number R7,7 to be computed to meet the desired error tolerance of 1e-06. This means only N = 64 slices are required. 

My approach when it came to computing, storing and managing R values was to store them in a big 100-by-100 array. I am making the assumption that we will never need to calculated the 101st row of the Romberg triangle because we will reach the computer’s own machine precision far before that. The size of this array is overkill.

Another weird thing about my code is that my R values have an initial index of 1. (that is R[1,1] is the first value). If you look in memory, my R array actually has a 0th column and 0th row that I’m not using. R[0,0] refers to a place in memory that I’m not using. I made this choice to start with R[1,1] because it matches more closely with the choice of index in the textbook, R1,1.  

In reality, I recognize that the R array will always be a lower-triangular matrix. In that sense, I could implement a jagged array and simply concatenate a new row of R values as they are computed.

Implementing this jagged array would make printing the Romberg triangle much more elegant. My code for printing the Romberg triangle right now is a nested for loop. While it does work perfectly, the if-else statement to handle endline characters is not very pretty.
