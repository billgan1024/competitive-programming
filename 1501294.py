# -*- coding: utf-8 -*-
"""
Created on Sun Jul  7 16:13:36 2019

@author: billg
"""

string = input()

letters = []

for x in string:
    if not x in letters:
        letters.append(x)
        
frequencies = []

for x in letters:
    frequencies.append(string.count(x))

frequencies.remove(max(frequencies))
if len(frequencies) > 0:
    frequencies.remove(max(frequencies))

chars = 0
for x in frequencies:
    chars += x
    
print(chars)