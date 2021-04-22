import math


def isPrime(n):
    if n == 1:
        return False
    rootn = math.sqrt(n)
    
    for x in range(2, math.floor(rootn + 1)):
        if n % x == 0:
            return False
    
    return True

numList = []
for x in range(5):
    numList.append(int(input()))

for num in numList:

    
    if isPrime(num):
        factors = 0
    else:
        factors = 1
    
    while not isPrime(num):
        for y in range(2, num - 1):
            if num % y == 0:
                num = int(num / y)
                factors += 1
                break
        
    
    
            
    print(factors)