lst = input().split()
n = int(lst[0])
m = int(lst[1])
k = int(lst[2])
ma = []
res = []
dx = [0, 1, -1, 0, 0]
dy = [0, 0, 0, 1, -1]
for i in range(0, n + 1):
    ma.append([0])
    res.append([0])
    for j in range(0, m + 5):
        ma[i].append(0)
        res[i].append(0)
for i in range(1, n + 1):
    tem = input().split()
    for j in range(1, m + 1):
        ma[i][j] = int(tem[j - 1])
b = k // 2
for i in range(1, n + 1):
    for j in range(1, m + 1):
        res[i][j] = ma[i][j]
        for v in range(i - b, i + b + 1):
            for u in range(j - b, j + b + 1):
                if v >= 1 and v <= n and u >= 1 and u <= m:
                    res[i][j] = max(res[i][j], ma[v][u])
for i in range(1, n + 1):
    for j in range(1, m + 1):
        print(res[i][j], end=' ')
    print()
