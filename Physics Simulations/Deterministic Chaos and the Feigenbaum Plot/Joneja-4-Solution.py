#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Jan 31 22:35:00 2017

@author: pranav
"""

from __future__ import division,print_function
from numpy import linspace, empty, size, array
import matplotlib.pyplot as plt

def logisticmap(r):
    x_p = 0.0
    x = 0.5
    for n in range(1001):
        x_p = r*x*(1-x)
        x = x_p
    return x_p

def getx(r):
    x = empty(1001)
    x[0] = logisticmap(r) #initial value, computes 1000 iterations to get value to settle
    for n in range(1000):
        x[n+1] = r*x[n]*(1-x[n])
    return x#returns values from iterations 1000 to 2000, after the value has settled 
    
r_array = linspace(1,4,301) #r from 1 to 4 in steps of 0.01
for i in range(size(r_array)):
    current_r = r_array[i]
    print("r =",current_r)
    
    x = getx(current_r)
    r = array([current_r] * size(x))
    
    plt.scatter(r, x, 1)

plt.xlabel("r")
plt.ylabel("x")
plt.axis([1, 4, 0, 1]) #r ranges from 1 to 4, x ranges from 0 to 1
plt.title("Feigenbaum Plot")
plt.show()


