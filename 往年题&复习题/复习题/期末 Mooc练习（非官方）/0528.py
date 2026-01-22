pi = 3.1415926536
lst = input().split()
n = int(lst[0])
f = int(lst[1])
k = input().split()
ans = [0]
mr = 0
for i in range(1, n + 1):
    ans.append(pi * int(k[i - 1]) * int(k[i - 1]))
    mr = max(mr, int(k[i - 1]))
l = 0
r = pi * mr * mr + 1
eps = 1e-6
res = 0
while r - l >= eps:
    mid = (l + r) / 2
    temp = 0
    for i in range(1, n + 1):
        temp += ans[i] // mid
    if temp >= f + 1:
        l = mid + eps
        res = mid
    else:
        r = mid - eps
print(f"{res:.3f}")

# 浮点二分更建议使用限定循环次数求解