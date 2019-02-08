#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Jan 31 17:16:28 2017

@author: pranav
"""
from __future__ import division,print_function

#1
def BindingEnergy(A,Z):
    a1=15.67
    a2=17.23
    a3=0.75
    a4=93.2
    if (A % 2 == 1):
        a5=0
    elif (Z % 2 == 0):
        a5=12.0
    else:
        a5=-12.0
    #print("a5=",a5)    
    
    B=a1*A-a2*A**(2/3)-a3*(Z*Z)/(A**(1/3))-a4*((A-2*Z)**2)/A+a5/(A**0.5)
    
    return B


#2
def BindingEnergyPerNucleon(A,Z):
    B=BindingEnergy(A,Z)
    return B/A

#3
def MostStable(Z):
    maxA = 0 #not "maxA" per se, it's really A corresponding to max binding energy per nucleon
    maxBperA = -100.0 #must be initialized smaller than hydrogen atom's lowest
    for A in range(Z,3*Z+1):
        curBperA = BindingEnergyPerNucleon(A,Z)
        #print("B/A=",curBperA,"A=",A)
        if (curBperA > maxBperA):
            maxBperA = curBperA
            maxA = A
    #print("A = {}, B/A = {:4f}".format(maxA,maxBperA))
    return [maxA,maxBperA]

#4 
maxBoverall = 0.0
maxAoverall = 0
maxZoverall = 0          
for Z in range(1,101):
    current = MostStable(Z)
    print("Z = {:2d} --> A = {:2d}, B/A = {:4f}".format(Z,current[0],current[1]))
    if (current[1] > maxBoverall):
        maxBoverall = current[1]
        maxAoverall = current[0]
        maxZoverall = Z
        
print("Most stable atom is")
print("Z = {}, A = {}, B/A = {}".format(maxZoverall,maxAoverall,maxBoverall))
