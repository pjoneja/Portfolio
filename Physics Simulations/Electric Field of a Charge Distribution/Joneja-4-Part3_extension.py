#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sun Feb 12 16:44:36 2017

@author: pranav
"""

from __future__ import division,print_function
from numpy import empty, pi, sin
from math import atan2
from pylab import imshow, gray, show, title, hsv, figure, close


#visualization parameters
side = 1.0                  #Side of the visualization window in m
points = int(1e2)           #Number of grid points along each side
spacing = side/points       #Spacing of points in m

#charge distribution parameters
L = 0.1                     #Side of the square charge distribution in m
q0 = 100                    #q-naught of charge distribution
#boundaries of the charge distribution
left = side/2 - L/2
right = side/2 + L/2
bottom = side/2 - L/2
top = side/2 + L/2

#physics parameters
epsilon0 = 8.854187817e-12  #permittivity of vacuum in Farads per m
k = 1/(4*pi*epsilon0)       #compute coefficent once to save repeated computation 

#time complexity of this script: O(points**4)

tpl = 2*pi/L
def sigma(x0,y0):
    return q0*sin(tpl*x0)*sin(tpl*y0)

#returns r-squared, 
#the square of distance from current point (x0,y0) to some arbitrary point(x,y)
def r(x,y,x0,y0):
    return ((x-x0)**2+(y-y0)**2)**-1.5

def frange(start,stop,step):
    i = start
    while (i <= stop):
        yield i
        i += step
    


#returns mag and direction of electric field at point(x,y)
def efield(x,y):
    e_x,e_y = 0.0,0.0
    outside_square = ((x < left) or (x > right) or (y < bottom) or (y > top))
    if outside_square:
        for x0 in frange (left,right,spacing):
            for y0 in frange(bottom,top,spacing):
                dq = sigma(x0,y0)
                rhat = r(x,y,x0,y0)
                e_x += dq*(x-x0)*rhat
                e_y += dq*(y-y0)*rhat
        
        e_x *= k
        e_y *= k
    
    mag = (e_x**2+e_y**2)**0.5
    dir = atan2(e_y,e_x)
    return mag,dir
    

#make arrays to store the values at each point
efm = empty([points,points],float)  #electric field magnitude
efd = empty([points,points],float)  #electric field direction

prev_percent_done = 0

#calculate values in the array
for i in range(points):
    x = spacing*i
    for j in range(points):
        y = spacing*j
        efm[j,i],efd[j,i] = efield(x,y)
        #must be ep[j,i] because of the way python indexes arrays
        
    percent_done = int((i/points)*100)
    if (percent_done != prev_percent_done):
        print("Computing: {}% done".format(percent_done))
        prev_percent_done = percent_done

close("all") #close all previously open plots
#make the plots

figure()
imshow(efm,origin="lower",extent=[0,side,0,side])
gray()
title("Electric Field Magnitude")
show()

figure()
imshow(efd,origin="lower",extent=[0,side,0,side])
hsv()
title("Electric Field Direction")
show()





