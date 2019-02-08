### Problem Statement
![ps1](https://github.com/pjoneja/Portfolio/blob/master/Physics%20Simulations/Naively%20Calculating%20Integrals/ps1.png?raw=true)
![ps2](https://github.com/pjoneja/Portfolio/blob/master/Physics%20Simulations/Naively%20Calculating%20Integrals/ps2.png?raw=true)

### My Approach
This was a straightforward assignment. I used the code profiler feature of my IDE (Spyder in Anaconda) to get a sense of the real run time of my code in seconds. 

1.	When N = 100, the error is still 0.00166207124565. We need to increase N for greater accuracy
2.	With some trial and error, the largest N that makes the program run in about 1.0 seconds is N = int(1e5). The error is 5.26e-08. In plain English, an error of about 50 billionths.

![timeit1](https://github.com/pjoneja/Portfolio/blob/master/Physics%20Simulations/Naively%20Calculating%20Integrals/timeit1.png?raw=true)

But then I realized that printing “x = …. “ for every iteration of the loop added considerable overhead! By commenting that line out, the code ran 5 times faster (for the same N = int(1e5))!

![timeit2](https://github.com/pjoneja/Portfolio/blob/master/Physics%20Simulations/Naively%20Calculating%20Integrals/timeit2.png?raw=true)

So now, without the overhead of printing lines, within a max of 1.0 seconds total runtime, the maximum N can be is int(6e5) which results in an error of 3.58e-09

![timeit3](https://github.com/pjoneja/Portfolio/blob/master/Physics%20Simulations/Naively%20Calculating%20Integrals/timeit3.png?raw=true)


