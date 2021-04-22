size = int(input())

inputList = []

for x in range(size):
    inputList.append(int(input()))
    
while len(inputList) > 0:
    print(min(inputList))
    inputList.remove(min(inputList))