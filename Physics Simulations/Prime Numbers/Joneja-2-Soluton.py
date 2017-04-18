#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Jan 31 19:08:41 2017

@author: pranav
"""
from __future__ import division,print_function
from math import sqrt

search_until = 10000 #must be an int!

primes = [2]
for n in range(3,search_until+1):
    for prime in primes:
        if n % prime == 0:
            #found the first prime factor
            break #no need to check divisibility by the rest of the primes
        elif prime > int(sqrt(n)):
            #has now checked all primes <= sqrt(n)
            primes.append(n)
            break 

print(primes)
