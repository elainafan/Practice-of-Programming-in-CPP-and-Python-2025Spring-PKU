lst = input().split()
n = int(lst[0])
m = int(lst[1])
ans = 0
for i in range(1, n + 1):
    for j in range(i + 1, n + 1):
        if m % (i + j) == 0:
            print(i, end=' ')
            print(j)
            ans += 1
print(ans)
