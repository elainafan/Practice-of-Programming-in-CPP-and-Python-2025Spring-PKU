lst = input().split()
n = int(lst[0])
m = int(lst[1])
ma = [[0]]
fa = [[0]]
dx = [0, 1, -1, 0, 0]
dy = [0, 0, 0, 1, -1]
for i in range(1, n + 1):
    lst = input().split()
    ma.append([0])
    fa.append([0])
    for j in range(1, m + 1):
        ma[i].append(int(lst[j - 1]))
        fa[i].append(int(lst[j - 1]))
for i in range(2, n):
    for j in range(2, m):
        temp = 0
        for k in range(0, 5):
            ax = i + dx[k]
            ay = j + dy[k]
            temp += fa[ax][ay]
        ma[i][j] = round(temp / 5)
for i in range(1, n + 1):
    for j in range(1, m + 1):
        print(ma[i][j], end=' ')
    print()
