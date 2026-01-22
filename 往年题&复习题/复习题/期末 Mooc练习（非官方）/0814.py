def check(x):
    global ma, t
    temp = 0
    for length in ma:
        temp += length // x
    return temp >= t


lst = input().split()
n = int(lst[0])
t = int(lst[1])
ma = [0]
mr = 0
for i in range(1, n + 1):
    k = float(input())
    temp = int(k * 100)
    ma.append(temp)
    mr = max(mr, temp)
l = 1
r = mr + 1
res = 0
while r > l:
    mid = (r + l) // 2
    temp = 0
    for i in range(1, n + 1):
        temp += ma[i] // mid
    if temp >= t:
        l = mid + 1
        res = mid
    else:
        r = mid - 1
if check(res + 1):
    res = res + 1
if res < 1:
    print("0.00")
else:
    res = res / 100
    print(f"{res:.2f}")
