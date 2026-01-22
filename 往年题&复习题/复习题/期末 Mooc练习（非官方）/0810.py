lst = input().split()
n = int(lst[0])
m = int(lst[1])
course = {}
price = {}
ans = 0
for i in range(0, m):
    tem = input().split()
    x = int(tem[1])
    y = int(tem[2])
    course[tem[0]] = y
    price[tem[0]] = x
for i in range(0, n):
    tem = input().split()
    a = tem[0]
    b = tem[1]
    c = tem[2]
    if course[a] > 0:
        ans += price[a]
        course[a] -= 1
    if course[b] > 0:
        ans += price[b]
        course[b] -= 1
    if course[c] > 0:
        ans += price[c]
        course[c] -= 1
print(ans)
