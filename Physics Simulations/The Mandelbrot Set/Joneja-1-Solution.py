#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Fri Feb 10 17:44:37 2017

@author: pranav
"""

from __future__ import division,print_function
from numpy import empty
#import matplotlib.pyplot as plt
from pylab import imshow, gray, jet, show

#window size
left,right,bottom,top = -2,2,-2,2
#NOTE: left < right and bottom < top must be true

N = 1000 #spacing
iter_limit = 100 #max number of iterations
#time complexity of this script: O(N**2)
#iter_limit does have a (smaller) effect on time complexity

def iterationsInMandelbrotSet(x,y):
    z_p = 0.0 + 0j
    z = 0.0 + 0j
    c = complex(x,y)
    iter = 0
    
    while (iter < iter_limit):
        z_p = z**2+c
        z = z_p
        iter += 1
        if (abs(z_p) > 2.0):
            break #if the value of z_p is ever greater than 2.0, \ 
            #then we know this point is not in the mandelbrot set
    return iter

to_show = empty([N,N],float)
prev_percent_done = 0


for i in range(N):
    x = left+(((right-left)*i)/N)
    for j in range(N):
        y = bottom+(((top-bottom)*j)/N)
        to_show[j,i] = iterationsInMandelbrotSet(x,y)
        #has to be [j,i] because of the way arrays are handled column-by-row
        
    percent_done = int((i/N)*100)
    if (percent_done != prev_percent_done):
        print("Simulation running: {}% done".format(percent_done))
        prev_percent_done = percent_done
    
imshow(to_show, extent=[left,right,bottom,top])
jet()
show()    
    
    
    
