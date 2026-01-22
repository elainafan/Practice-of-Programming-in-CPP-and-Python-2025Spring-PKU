n = int(input())
res = 1
ans = 0
for i in range(1, n + 1):
    res *= i
    ans += res
print(ans)
