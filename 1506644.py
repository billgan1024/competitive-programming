count = int(input())
words = input().split()
result = 0
for x in words:
    if len(x) <= 10:
        result += 1
print(result)