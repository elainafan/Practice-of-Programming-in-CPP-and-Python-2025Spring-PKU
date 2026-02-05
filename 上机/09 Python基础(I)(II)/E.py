k = input().split()
n = int(k[0])
m = int(k[1])
ma = [[]]
vis = [[]]
pd = [[]]
dx = [0, 1, -1, 0, 0]
dy = [0, 0, 0, 1, -1]
for i in range(0, n + 1):
    ma.append([0])
    vis.append([0])
    pd.append([0])
for i in range(1, n + 1):
    lst = input().split()
    for j in range(0, m):
        value = int(lst[j][2:])
        if (lst[j][0] == 'X'):
            vis[i].append(1)
            pd[i].append(1)
        else:
            vis[i].append(0)
            pd[i].append(0)
        ma[i].append(value)
for i in range(1, n + 1):
    for j in range(1, m + 1):
        if vis[i][j] == 1:
            temp = ma[i][j]
            for k in range(1, 5):
                ax = i + dx[k]
                ay = j + dy[k]
                if ax >= 1 and ax <= n and ay >= 1 and ay <= m:
                    temp += ma[ax][ay]
                    pd[ax][ay] = 1
            print(f"({i},{j}):{temp}")
ans = 0
for i in range(1, n + 1):
    for j in range(1, m + 1):
        if pd[i][j] == 1:
            ans += ma[i][j]
print(ans)
