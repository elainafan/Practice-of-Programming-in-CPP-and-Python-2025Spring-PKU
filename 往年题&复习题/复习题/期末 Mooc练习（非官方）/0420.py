n = int(input())
lst = input().split()
ans = 0
for i in range(0, n):
    x = int(lst[i])
    if x >= 30:
        ans += 1
print(ans)
