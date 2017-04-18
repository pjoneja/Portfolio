###Problem Statement


###My Approach
I approached this problem by solving each part individually. It was clear from the questions that each part could be logically considered it’s own function and the next part would call the previous function as necessary. This helps to organize code and prevent code being rewritten. Plus, if for some reason I need to change the semi-empirical formula, I only need to change it in one place: the BindingEnergy function.

To determine the most stable at a given Z (i.e. highest binding energy per nucleon at a given Z), my approach is similar to that learned in class and from previous experience:
1.	We initialize variables to hold our final answer. These must be assigned initial values of any number less than the minimum. In this case, the lowest value occurs when A = 1, Z = 1, which means the minimum binding energy per nucleon is –95.51. I initialized my holder variable less than this, maxBperA = -100.0
2.	We compute the binding energy per nucleon for every combination of A and Z in the required range. During every iteration of the for loop, compare against the holder variable (the maximum so far)
3.	If the current iteration is greater than the maximum so far, replace the holder variable’s value with the current iteration. 
4.	After computing all values, return the values corresponding to the most stable

A similar approach is used again to find the value of Z at which the maximum binding energy per nucleon is achieved. 

Answer:
Most stable atom is
Z = 24, A = 50, B/A = 8.532622751365931
