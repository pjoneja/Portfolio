from __future__ import division,print_function
from visual import display, sphere, color, rate
from math import cos,sin,pi
from numpy import empty,arange

#user defined parameters
c1=0.3 #radius multiplier
c2=50 #angular frequency multiplier
c3=500 #orbit radius multiplier

#user defined functions
def freq(T):
    return c2*(2*pi)/T

#planetary parameters
positions = [0, 57.9, 108.2, 149.6, 227.9, 778.5, 1433.4]
radii = [69550, 2440, 6052, 6371, 3386, 69173, 57316]
period = [1, 88.0, 224.7, 365.3, 687.0, 4331.6, 10759.2]
w = list(map(freq,period))

p = empty(7,sphere)

#setup
for n in range(7):
    p[n] = sphere()
    p[n].radius = c1*radii[n]
    p[n].pos = [0,c3*positions[n]]

p[0].color=color.yellow
p[1].color=color.red 
p[3].color=color.blue

#animate
for theta in arange(0,1000*pi,0.1):
    rate(30)
    for n in range(7):
        x=cos(w[n]*theta)
        y=sin(w[n]*theta)
        p[n].pos = [c3*positions[n]*x,c3*positions[n]*y]
        
