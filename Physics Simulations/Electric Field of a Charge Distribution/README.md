### Problem Statement
![ps1](https://github.com/pjoneja/Portfolio/blob/master/Physics%20Simulations/Electric%20Field%20of%20a%20Charge%20Distribution/ps1.png?raw=true)
![ps2](https://github.com/pjoneja/Portfolio/blob/master/Physics%20Simulations/Electric%20Field%20of%20a%20Charge%20Distribution/ps2.png?raw=true)

## My Approach

### Parts 1 and 2: Electric Potential and Electric Field

My solution is based on the wave interference code in Example 3.1. 

I found that computing the electric potential and electric field in separately defined functions makes the main loops more readable. It’s now easy to see that the whole script has time complexity O(points2)

![epefeq](https://github.com/pjoneja/Portfolio/blob/master/Physics%20Simulations/Electric%20Field%20of%20a%20Charge%20Distribution/epefeq.png?raw=true)

The first step towards finding the answer is: we need to compute partial derivatives of  in x and y. 
To extend my learning, I decided to make a comparison between numerical and “analytic” methods.

**Numerical Approach:**
Computing partial derivatives mean iterating down rows for  and down columns for . It’s clear that the central difference method will provide the best precision. However, the central difference method cannot be used on the first and last elements in the row or column. Instead, the forward difference method is used for the first elements and the backward difference method is used for the last element. All the elements in between can use the central difference method.

**Analytic Approach:**
This section explains my “analytic” approach. I call this section “analytic” in quotes because it requires deriving the partial derivatives with a pen and paper.

Using the chain rule, we have:
![diffs](https://github.com/pjoneja/Portfolio/blob/master/Physics%20Simulations/Electric%20Field%20of%20a%20Charge%20Distribution/diffs.png?raw=true)

Presented this way, the computational similarities between the two are clear. So I created c and r and to cut down repetitive computation.
![kr](https://github.com/pjoneja/Portfolio/blob/master/Physics%20Simulations/Electric%20Field%20of%20a%20Charge%20Distribution/kr.png?raw=true)

**For both numerical and analytic approaches:**
Finally, computing magnitude and direction of the E field.
![magphase](https://github.com/pjoneja/Portfolio/blob/master/Physics%20Simulations/Electric%20Field%20of%20a%20Charge%20Distribution/magphase.png?raw=true)

In python, I took advantage of the math library function atan2(y,x) which returns values from –pi to pi only. Mathematically, it finds the correct quadrant since its arguments are both x and y. 


### Results:
Figure 1:
![fig1](https://github.com/pjoneja/Portfolio/blob/master/Physics%20Simulations/Electric%20Field%20of%20a%20Charge%20Distribution/figure_1.png?raw=true)
--
Figure 2:
![fig2a](https://github.com/pjoneja/Portfolio/blob/master/Physics%20Simulations/Electric%20Field%20of%20a%20Charge%20Distribution/figure_2a.png?raw=true)
![fig2b](https://github.com/pjoneja/Portfolio/blob/master/Physics%20Simulations/Electric%20Field%20of%20a%20Charge%20Distribution/figure_2b.png?raw=true)
--


---

Next, the colors represent the direction in which the E field points. The color bar on the right also helps understand what’s going on. 

I plotted two scenarios:
1.	a dipole (one negative charge, one positive charge). 
2.	two positive charges. 

To read the plot, you need to know that areas with the same color mean the E field points in the same direction. You also need to know about diametrically opposite colors, representing the E field pointing in exactly opposite directions.  

In simple terms, 
Light blue is theta = 0, pointing to the right, 
Red is theta = pi (or –pi),  pointing to the left.

#### Scenario 1: dipole (one negative charge, one positive charge)
Figure 3:
![fig3a](https://github.com/pjoneja/Portfolio/blob/master/Physics%20Simulations/Electric%20Field%20of%20a%20Charge%20Distribution/figure_3a.png?raw=true)
![fig3b](https://github.com/pjoneja/Portfolio/blob/master/Physics%20Simulations/Electric%20Field%20of%20a%20Charge%20Distribution/figure_3b.png?raw=true)
--

#### Scenario 2: two positive charges
Figure 4:
![fig4a](https://github.com/pjoneja/Portfolio/blob/master/Physics%20Simulations/Electric%20Field%20of%20a%20Charge%20Distribution/figure_4a.png?raw=true)
![fig4b](https://github.com/pjoneja/Portfolio/blob/master/Physics%20Simulations/Electric%20Field%20of%20a%20Charge%20Distribution/figure_4b.png?raw=true)
--
---
---
---

### Part 3: Continuous Charge Distribution

The solution here expands on the previous one. Instead of q being a constant, it is instead integrated over as dq, itself a function of x and y. 

![dq](https://github.com/pjoneja/Portfolio/blob/master/Physics%20Simulations/Electric%20Field%20of%20a%20Charge%20Distribution/dq.png?raw=true)

It is at this stage in the problem that a numerical double integration followed by numerical derivatives makes a lot more sense. 

**Numerical Approach:**

The difficulty with the numerical approach is that sigma(x,y) is badly behaved. It varies very wildly within a small dx (or dy). This makes it a bad idea to use higher order methods like Romberg, because those methods only sample a few points in the function. Instead, since the integrand varies so much, an integration method that samples at a large number of points will better capture the shape of the function. 

I decided the best approach would be a “trapezoid method” in two variables. In practice, this means there is a line: ep += (spacing)**2*dq/r_hat. In regular trapezoid method, spacing is not squared. In this two dimensional trapezoid extension method, spacing must be squared to take the second dimension into account.

The rest of the approach is very similar to the first part of the problem. To take a derivative numerically, the central difference method is used wherever possible. The central difference method cannot be used along the edges of the matrix, so the forward and backward difference methods are used appropriately.

In all, this numerical approach is quite slow. I ran my code at a max of N=400.

**Analytical Approach:**
The good thing about an analytical approach is that the E field can be computed directly. No need to find the Electric Potential at every point and take a derivative. Still, my solution has time complexity O(N^4) which is incredibly slow. I could only bear to run it for N = 400 because it was too slow beyond that. 

### Results:
Figure 5:
![fig5a](https://github.com/pjoneja/Portfolio/blob/master/Physics%20Simulations/Electric%20Field%20of%20a%20Charge%20Distribution/figure_5a.png?raw=true)
![fig5b](https://github.com/pjoneja/Portfolio/blob/master/Physics%20Simulations/Electric%20Field%20of%20a%20Charge%20Distribution/figure_5b.png?raw=true)
--
Figure 6:
![fig6a](https://github.com/pjoneja/Portfolio/blob/master/Physics%20Simulations/Electric%20Field%20of%20a%20Charge%20Distribution/figure_6a.png?raw=true)
![fig6b](https://github.com/pjoneja/Portfolio/blob/master/Physics%20Simulations/Electric%20Field%20of%20a%20Charge%20Distribution/figure_6b.png?raw=true)
--
Figure 7:
![fig7](https://github.com/pjoneja/Portfolio/blob/master/Physics%20Simulations/Electric%20Field%20of%20a%20Charge%20Distribution/figure_7.png?raw=true)
