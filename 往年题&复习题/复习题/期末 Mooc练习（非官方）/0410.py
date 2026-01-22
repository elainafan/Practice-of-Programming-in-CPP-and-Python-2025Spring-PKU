ma = -999999
mi = 999999
n = int(input())
lst = input().split()
for i in range(0, n):
    x = int(lst[i])
    ma = max(ma, x)
    mi = min(mi, x)
print(ma - mi)
