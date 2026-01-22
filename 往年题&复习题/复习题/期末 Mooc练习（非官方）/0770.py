lst = input().split()
n = int(lst[0])
m = int(lst[1])
k = int(lst[2])
ans = []
sav = []
res = []
for i in range(0, n):
    ans.append([])
    t = input().split()
    for j in range(0, m):
        ans[i].append(int(t[j]))
for i in range(0, m):
    sav.append([])
    t = input().split()
    for j in range(0, k):
        sav[i].append(int(t[j]))
for i in range(0, n):
    res.append([])
    for j in range(0, k):
        res[i].append(0)
        for v in range(0, m):
            res[i][j] += ans[i][v] * sav[v][j]
for i in range(0, n):
    for j in range(0, k):
        print(res[i][j], end=' ')
    print()
