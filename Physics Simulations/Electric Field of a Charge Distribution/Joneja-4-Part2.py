#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sun Feb 12 16:44:36 2017

@author: pranav
"""

from __future__ import division,print_function
from numpy import empty, pi
from math import atan2
from pylab import imshow, gray, show, title, hsv, figure, close, colorbar

#visualization parameters
side = 1.0                  #Side of the square in m
points = int(1e3)           #Number of grid points along each side
spacing = side/points       #Spacing of points in m
#time complexity of this script: O(points**2)

#charge and placement parameters
q1 = -1
q2 = 1
separation = 0.1            #Separation of centers in m

#physics parameters
epsilon0 = 8.854187817e-12  #permittivity of vacuum in Farads per m

#Calculate positions of the centers of charges
x1 = side/2 + separation/2
y1 = side/2
x2 = side/2 - separation/2
y2 = side/2

#make arrays to store the values at each point
ep = empty([points,points],float)   #electric potential

efmn = empty([points,points],float)  #electric field magnitude numerical
efdn = empty([points,points],float)  #electric field direction numerical

#
#            
##METHODS
            
#returns electric potential at point(x,y) 
def epotential(x,y):
    if (x == x1 and y == y1) or (x == x2 and y == y2):
        e1,e2 = 1.0,1.0 #skip division by 0, set to dummy values
    else:     
        e1 = q1/(4*pi*epsilon0*((x-x1)**2+(y-y1)**2)**0.5)
        e2 = q2/(4*pi*epsilon0*((x-x2)**2+(y-y2)**2)**0.5)
    return e1 + e2 #scalar addition

#returns mag and direction of E field at point(x,y)
#by numerically computing partial derivative
twospace = 2*spacing #compute once to save repeated computation
def efield_numerical(j,i):
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

#
#
##LOOPS

prev_percent_done = 0

#calculate values in the array
for i in range(points):
    x = spacing*i
    for j in range(points):
        y = spacing*j
        ep[j,i] = epotential(x,y)
        #must be ep[j,i] because of the way python indexes arrays
        
    percent_done = int((i/points)*50)
    if (percent_done != prev_percent_done):
        print("Computing: {}% done".format(percent_done))
        prev_percent_done = percent_done
        
for i in range(points):
    for j in range(points):
        efmn[j,i],efdn[j,i] = efield_numerical(j,i)
        
    percent_done = 50 + int((i/points)*50)
    if (percent_done != prev_percent_done):
        print("Computing: {}% done".format(percent_done))
        prev_percent_done = percent_done

close("all") #close all previously open plots
#make the plots
figure()
imshow(ep,origin="lower",extent=[0,side,0,side])
gray()
title("Electric Potential")
show()

figure()
imshow(efmn,origin="lower",extent=[0,side,0,side])
gray()
title("Electric Field Magnitude -- Computed Numerically")
show()

figure()
imshow(efdn,origin="lower",extent=[0,side,0,side])
hsv()
title("Electric Field Direction -- Computed Numerically")
colorbar()
show()





