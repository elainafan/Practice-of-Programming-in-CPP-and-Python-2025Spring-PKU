def dfs(x):
    global ma
    if x == 1 or x == 2:
        return x
    ans = x
    ans += dfs(x - 1) + dfs(x - 2)
    return ans


m = int(input())
ma = [0]
for i in range(1, m + 1):
    k = int(input())
    ma.append(k)
for i in range(1, m + 1):
    print(dfs(ma[i]))
