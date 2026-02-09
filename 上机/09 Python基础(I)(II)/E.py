k = input().split()
n = int(k[0])
m = int(k[1])
ma = [[0] * (m + 2) for _ in range(n + 2)]
vis = [[0] * (m + 2) for _ in range(n + 2)]
pd = [[0] * (m + 2) for _ in range(n + 2)]
dx = [0, 1, -1, 0, 0]
dy = [0, 0, 0, 1, -1]
for i in range(1, n + 1):
    row = input().split()
    for j in range(1, m + 1):
        if row[j - 1][0] == 'X':
            vis[i][j] = 1
            pd[i][j] = 1
        ma[i][j] = int(row[j - 1][2:])
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
