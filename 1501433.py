base2 = input()
base3 = input()



        

def switch2(a, pos):
    if a[pos] == "1":
        char = "0"
    else:
        char = "1"
    newstring = ""
    
    for x in range(len(a)):
        if x == pos:
            newstring += char
        else:
            newstring += a[x]
    return newstring

def switch3(a, pos, key):
    if a[pos] == "1":
        if key == 1:
            char = "0"
        elif key == 2:
            char = "2"
    elif a[pos] == "2":
        if key == 1:
            char = "0"
        elif key == 2:
            char = "1"
    else:
        if key == 1:
            char = "1"
        elif key == 2:
            char = "2"
        
    newstring = ""
    
    for x in range(len(a)):
        if x == pos:
            newstring += char
        else:
            newstring += a[x]
    return newstring

def convertBase(string, base):
    digits = list(reversed(string))
    num = 0 #the base 10 number
    for z in range(len(digits)):
        num += int(digits[z]) * int(base**z)
    return num
    

for x in range(len(base2)):
    currentCase = switch2(base2, x)
    
    number = convertBase(currentCase, 2)
    
    
    
    #one of the cases for the number
    #switch all the cases for the base 3 number
    for y in range(len(base3)):
        case1 = switch3(base3, y, 1)
        case2 = switch3(base3, y, 2)
        
        if number == convertBase(case1, 3) or number == convertBase(case2, 3):
            print(number)
            break