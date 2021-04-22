inputList = input().split()
d = int(inputList[0])
h = int(inputList[1])
m = int(inputList[2])

mins = 0

if d < 11:
    mins = -1
elif d == 11:
    if h < 11:
        mins = -1
    elif h == 11:
        if m < 11:
            mins = -1
        else:
            mins += m - 11
    else:
        mins += (h - 11) * 60
        mins += (m - 11)
    
else:
    mins += (d - 11) * 1440
    mins += (h - 11) * 60
    mins += (m - 11)
    
print(mins)