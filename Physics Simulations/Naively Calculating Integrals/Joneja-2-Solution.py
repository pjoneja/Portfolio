#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sat Feb 11 18:22:42 2017

@author: pranav
"""

from __future__ import division,print_function
from numpy import sqrt, pi

#time complexity of this script: O(N)
N = int(6e5)
h = 2/N
sum = 0
#limits of integration
low,high = -1,1

for k in range(1,N+1):
    x = low+h*k
    sum += h*sqrt(1-x**2)
    #print("x = {:4f}, sum = {:4f}".format(x,sum))

print("N = ", N)    
print("I_c = ",sum)
print("So error = ", abs(sum-pi/2))