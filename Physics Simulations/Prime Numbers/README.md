### Problem Statement
![ps1](https://github.com/pjoneja/Portfolio/blob/master/Physics%20Simulations/Prime%20Numbers/ps1.png?raw=true)
![ps2](https://github.com/pjoneja/Portfolio/blob/master/Physics%20Simulations/Prime%20Numbers/ps2.png?raw=true)

### My Approach
The problem statement makes it clear that this algorithm’s speed advantages stem from the fact that you only have to find one prime factor less than sqrt(n). As stated, “As soon as you find a single prime factor you can stop checking the rest of them—you know n is not a prime.” This strongly encourages the use of a break statement to break out of a for loop and continue to the next numbers in the search. 

The order of if and else-if statements is also important. If any prime factors are found before we iterate to numbers greater than sqrt(n), then we should break the loop. Similarly, once we know the number is prime, there’s no need to iterate over any numbers greater than sqrt(n) 

I was tempted to use a slice of the primes list that are less than sqrt(n), but even finding the index of that slice and then iterating over that slice is more effort than needed. 

Reading the problem statement and hints literally was really helpful in this problem.

![2]((https://github.com/pjoneja/Portfolio/blob/master/Physics%20Simulations/Prime%20Numbers/Joneja-2.png?raw=true)