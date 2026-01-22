n = int(input())
ma = [[0]]
dp = [[0]]
for i in range(1, n + 1):
    temp = [0]
    ma.append([])
    for j in range(1, n + 1):
        temp.append(0)
    dp.append(temp)
for i in range(1, n + 1):
    lst = input().split()
    ma[i].append(0)
    for j in range(1, i + 1):
        ma[i].append(int(lst[j - 1]))
for i in range(1, n + 1):
    for j in range(1, n - i + 1):
        ma[i].append(0)
dp[1][1] = ma[1][1]
for i in range(2, n + 1):
    for j in range(1, n + 1):
        dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + ma[i][j]
ans = 0
for i in range(1, n + 1):
    ans = max(ans, dp[n][i])
print(ans)
