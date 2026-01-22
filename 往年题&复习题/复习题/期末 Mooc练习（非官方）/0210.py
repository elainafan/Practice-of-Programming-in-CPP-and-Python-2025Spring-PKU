lst = input().split()
x = int(lst[0])
y = lst[1]
ans = 0
if x <= 1000 and y == 'n':
    ans = 8
elif x > 1000 and y == 'n':
    if x % 500 == 0:
        ans = 4 * (x // 500)
    else:
        ans = 4 * (x // 500 + 1)
elif x <= 1000 and y == 'y':
    ans = 13
elif x > 1000 and y == 'y':
    if x % 500 == 0:
        ans = 4 * (x // 500) + 5
    else:
        ans = 4 * (x // 500 + 1) + 5
print(ans)
