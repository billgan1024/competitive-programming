# -*- coding: utf-8 -*-
"""
Created on Mon Jul  8 07:55:43 2019

@author: Bill Gan
"""

def convertEmail(email):
    willDelete = False
    beforeAt = True
    newEmail = ""
    for x in email:
        x = x.lower()
        
        willWrite = True
        
        if x == "." and beforeAt:
                willWrite = False
                
        if x == "+" and beforeAt:
            willDelete = True
                
        
        if x == "@":
            beforeAt = False
            willDelete = False
        
        
        if willWrite and not willDelete: #writes the letter only if all the conditions are true
            newEmail += x
    return newEmail   

for x in range(10):
    count = int(input())
    emails = []
    unique = {}
    
    for y in range(count):
        email = convertEmail(input())
        unique[email] = 1
        
    print(len(unique.keys()))