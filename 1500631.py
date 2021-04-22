dataList = []

for x in range(5):
    dataList.append(input().split())

for x in range(5):
    if int(dataList[x][2]) < 1997:
        print("old enough")
    elif int(dataList[x][2]) == 1997:
        if int(dataList[x][1]) < 10:
            print("old enough")
        elif int(dataList[x][1]) == 10:
            if int(dataList[x][0]) <= 27:
                print("old enough")
            else:
                print("too young")
        else:
            print("too young")
    else:
        print("too young")