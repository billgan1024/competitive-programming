# -*- coding: utf-8 -*-
"""
Created on Sun Jul  7 18:19:49 2019

@author: Bill Gan
"""
import math

num = int(input())

def isPrime(n):
    if n == 1:
        return False
    rootn = math.sqrt(n)
    
    for x in range(2, math.floor(rootn + 1)):
        if n % x == 0:
            return False
    
    return True
        
while isPrime(num) == False:
    num += 1
    
print(num)