lst = input().split()
n = int(lst[0])
m = int(lst[1])
canteen = {}
price = {}
for i in range(0, m):
    k = input().split()
    course = k[0]
    p = int(k[1])
    num = int(k[2])
    canteen[course] = num
    price[course] = p
ans = 0
for i in range(0, n):
    k = input().split()
    tem = k[0]
    temp = k[1]
    te = k[2]
    if canteen[tem] != 0:
        ans += price[tem]
        canteen[tem] -= 1
    if canteen[temp] != 0:
        ans += price[temp]
        canteen[temp] -= 1
    if canteen[te] != 0:
        ans += price[te]
        canteen[te] -= 1
print(ans)
