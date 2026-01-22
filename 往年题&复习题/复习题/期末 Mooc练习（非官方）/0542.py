def dfs(x, y):
    global vis, ma, dx, dy, flag
    if x == n and y == n:
        flag = 1
        return
    for i in range(1, 3):
        ax = x + dx[i]
        ay = y + dy[i]
        if ma[ax][ay] == 0 and vis[ax][
                ay] == 0 and ax >= 1 and ax <= n and ay >= 1 and ay <= n:
            vis[ax][ay] = 1
            dfs(ax, ay)
            vis[ax][ay] = 0
    return


n = int(input())
ma = []
vis = []
dx = [0, 1, 0]
dy = [0, 0, 1]
for i in range(1, n + 3):
    temp = [0]
    for j in range(1, n + 2):
        temp.append(0)
    ma.append(temp)
    vis.append(temp)
for i in range(1, n + 1):
    lst = input().split()
    for j in range(0, n):
        if lst[j] == '1':
            ma[i][j + 1] = 1
flag = 0
dfs(1, 1)
if flag == 0:
    print("No")
else:
    print("Yes")
