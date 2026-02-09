k = input().split()
n = int(k[0])
m = int(k[1])
ans = 0
ret = 0
ma = [[0] * (n + m + 1) for _ in range(n + m + 1)]
for i in range(1, n + 1):
    t = input().split()
    for j in range(1, n + 1):
        ma[i][j] = int(t[j - 1])
for i in range(1, n + 1):
    for j in range(1, n + 1):
        temp = 0
        for k in range(i, i + m):
            for v in range(j, j + m):
                temp += ma[k][v]
        if temp == ans:
            ret += 1
        if temp > ans:
            ans = temp
            ret = 1
print(ans, end=' ')
print(ret)
