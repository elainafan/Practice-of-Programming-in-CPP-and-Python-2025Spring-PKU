n = int(input())
lst = []
for i in range(1, n + 1):
    temp = input().split()
    lst.append([temp[0], int(temp[1]), int(temp[2])])
lst.sort(key=lambda x: (-x[2], -x[1], x[0]))
for item in lst:
    print(item[0], end=' ')
    print(item[1], end=' ')
    print(item[2])
