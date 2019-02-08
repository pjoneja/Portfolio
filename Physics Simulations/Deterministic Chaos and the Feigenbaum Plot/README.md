### Problem Statement
![ps1](https://github.com/pjoneja/Portfolio/blob/master/Physics%20Simulations/Deterministic%20Chaos%20and%20the%20Feigenbaum%20Plot/ps1.png?raw=true)
![ps2](https://github.com/pjoneja/Portfolio/blob/master/Physics%20Simulations/Deterministic%20Chaos%20and%20the%20Feigenbaum%20Plot/ps2.png?raw=true)
![ps3](https://github.com/pjoneja/Portfolio/blob/master/Physics%20Simulations/Deterministic%20Chaos%20and%20the%20Feigenbaum%20Plot/ps3.png?raw=true)

### My Approach
I was stumped by this problem for quite some time. For a long time, I tried to follow the ‘helpful’ comment about Python being able to perform arithmetic on entire arrays at once. I was able to make that work in a previous version of my code—but when it came to plotting, the plot function kept failing because my arrays had different sizes. If r only has 300 elements and x has 1000, there’s a mismatch. I know it’s possible to improve my code to take advantage of array arithmetic, but I wasn’t able to implement it successfully. Instead, my code calculates 1000 elements of the x matrix one by one in a big for loop. It could be faster, but it works!

The idea to set up an r_array and x_array and then plot using the scatter function as we go is a good one. It conserves memory by throwing away what’s already been plotted. There’s no reason to keep all the values in memory, that would be 300-by-1000 elements—a very large matrix indeed (plus, entire rows would be the exact same r value repeated). However, memory on modern computers is abundant and accessing memory is much faster than computing the values!

Another very useful concept is that recursive functions can begin with any value. In my code, the getx function requires an initial value of x, but instead of starting with ½ all over again, we can just find the value at the 1000th iteration pretty quickly and calculated the subsequent 1000 from there.

Answers:
1.	A fixed point means if you draw a vertical line through the Feigenbaum plot (corresponding to a particular r value), you would only cross through one dot representing one x value. A limit cycle means if you draw a similar vertical line, you would cross through a limited number of distinct dots, representing a small number of x values.Chaos looks like the “shaded” regions on the plot where there are a lot of dots. That’s because for every r value there actually are a lot of seemingly random dots that correspond to a wide spread of x values

2.	Based on my plot, the edge of chaos is approximately r = 3.5


![Feigenbaum](https://github.com/pjoneja/Portfolio/blob/master/Physics%20Simulations/Deterministic%20Chaos%20and%20the%20Feigenbaum%20Plot/figure_1.png?raw=true)