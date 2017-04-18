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
points = int(4e2)           #Number of grid points along each side
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

#returns r
#the square of distance from current point (x0,y0) to some arbitrary point(x,y)
def r(x,y,x0,y0):
    return ((x-x0)**2+(y-y0)**2)**0.5

#helper function. python range function extended for floats
def frange(start,stop,step):
    i = start
    while (i <= stop):
        yield i
        i += step
 
#NUMERICAL METHOD             
#returns electric potential at point (x,y) using trapezoid method in two variables
def epotential(x,y):
    ep = 0.0
    outside_square = ((x < left) or (x > right) or (y < bottom) or (y > top))
    if outside_square:
        for x0 in frange (left,right,spacing):
            for y0 in frange(bottom,top,spacing):
                dq = sigma(x0,y0)
                rhat = r(x,y,x0,y0)
                ep += (spacing)**2*dq/rhat
    return k*ep

#NUMERICAL METHOD
#returns mag and dir of E field at point(i*spacing, j*spacing)
#using forward,backward and central difference methods
twospace = 2*spacing #compute once to save repeated computation
def efield(j,i):
    e_x,e_y = 0.0,0.0
    #partial-x
    if i == 0:
        #forward difference in x
        e_x = (ep[j,i+1]-ep[j,i])/spacing
    elif i == points-1:
        #backward difference in x
        e_x = (ep[j,i]-ep[j,i-1])/spacing
    else:
        #central difference in x
        e_x = (ep[j,i+1]-ep[j,i-1])/twospace
              
    #partial-y
    if j == 0:
        #forward difference in y
        e_y = (ep[j+1,i]-ep[j,i])/spacing
    elif j == points-1:
        #backward difference in y
        e_y = (ep[j,i]-ep[j-1,i])/spacing
    else:
        #central difference in y
        e_y = (ep[j+1,i]-ep[j-1,i])/twospace
         
    mag = (e_x**2+e_y**2)**0.5
    dir = atan2(-1*e_y,-1*e_x) #multiply by *-1 because physics convention: \
                               #"direction of force exerted on pos test charge"
    return mag,dir
    

#make arrays to store the values at each point
ep = empty([points,points],float)   #electric potential

efm = empty([points,points],float)  #electric field magnitude
efd = empty([points,points],float)  #electric field direction

prev_percent_done = 0
total = points**2
counter = 0
#calculate values in the array
for i in range(points):
    x = spacing*i
    for j in range(points):
        y = spacing*j
        ep[j,i] = epotential(x,y)
        #must be ep[j,i] because of the way python indexes arrays
        counter += 1
        print("{:4f}%".format(100*counter/total))
        
#    percent_done = int((i/points)*50)
#    if (percent_done != prev_percent_done):
#        print("Computing: {}% done".format(percent_done))
#        prev_percent_done = percent_done
        
for i in range(points):
    for j in range(points):
        efm[j,i],efd[j,i] = efield(j,i)
        #must be ep[j,i] because of the way python indexes arrays
        
#    percent_done = int(50+(i/points)*50)
#    if (percent_done != prev_percent_done):
#        print("Computing: {}% done".format(percent_done))
#        prev_percent_done = percent_done

close("all") #close all previously open plots
#make the plots

figure()
imshow(ep,origin="lower",extent=[0,side,0,side])
gray()
title("Electric Potential -- Numerically Computed")
show()

magnitude = figure()
imshow(efm,origin="lower",extent=[0,side,0,side])
gray()
title("Electric Field Magnitude -- Numerically Computed")
show()
magnitude.savefig("Magnitude.png", dpi = 400)

direction = figure()
imshow(efd,origin="lower",extent=[0,side,0,side])
hsv()
title("Electric Field Direction -- Numerically Computed")
show()
direction.savefig("Direction.png", dpi = 400)





