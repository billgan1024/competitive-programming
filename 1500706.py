num = int(input())

dataList = []

for x in range(num):
    dataList.append(input().split())
    

for x in range(num):
    if dataList[x][0] != dataList[x][1] and dataList[x][1] != dataList[x][2] and dataList[x][2] != dataList[x][0]:
        print("???")
    else:
        
        #check if all three are same
        if dataList[x][0] == dataList[x][1] and dataList[x][1] == dataList[x][2]:
            print(dataList[x][0])
        #check if two are same
        else:
            if dataList[x][0] == dataList[x][1] and dataList[x][1] != dataList[x][2]:
                print(dataList[x][0])
            elif dataList[x][1] == dataList[x][2] and dataList[x][1] != dataList[x][0]:
                print(dataList[x][1])
            elif dataList[x][0] == dataList[x][2] and dataList[x][2] != dataList[x][1]:
                print(dataList[x][0])