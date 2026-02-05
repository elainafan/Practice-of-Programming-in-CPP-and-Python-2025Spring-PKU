n = int(input())
ma = [0]
lst = input().split()
for i in range(0, n):
    ma.append(int(lst[i]))
ma.append(0)
ans = 0
for i in range(1, n + 1):
    if ma[i] > ma[i - 1] and ma[i] > ma[i + 1]:
        ans += 1
print(ans)
