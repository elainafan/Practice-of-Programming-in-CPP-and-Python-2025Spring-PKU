n = int(input())
a = input().split()
b = input().split()
res = 0
for i in range(0, n):
    x = int(a[i])
    y = int(b[i])
    res += x * y
print(res)
