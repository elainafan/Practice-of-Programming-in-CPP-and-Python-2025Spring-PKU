lst = input().split()
l = int(lst[0])
r = int(lst[1])
ans = 0
for i in range(l, r + 1):
    temp = i
    while (temp > 0):
        t = temp % 10
        if t == 2:
            ans += 1
        temp //= 10
print(ans)
