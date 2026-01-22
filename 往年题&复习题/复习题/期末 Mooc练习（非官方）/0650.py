x = input()
ans = 0
l = len(x)
for i in range(0, l):
    if x[i] >= '0' and x[i] <= '9':
        ans += 1
print(ans)
