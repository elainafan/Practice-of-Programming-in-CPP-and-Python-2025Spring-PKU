def pd(x):
    if x % 4 == 0 and x % 100 != 0:
        return True
    if x % 400 == 0:
        return True
    return False


n = int(input())
rc = [0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 30]
c = [0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 30]
name = [
    0, "January", "February", "March", "April", "May", "June", "July",
    "August", "September", "October", "November", "December"
]
name_1 = [0, "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"]
for i in range(1, n + 1):
    lst = input().split()
    y = int(lst[0])
    m = int(lst[1])
    print(f"{name[m]},{y}")
    for j in range(1, 8):
        if j <= 6:
            print(name_1[j], end='\t')
        else:
            print(name_1[j])
    day = 0
    if pd(y):
        for j in range(1, m):
            day += rc[j]
        d = rc[m]
    else:
        for j in range(1, m):
            day += c[j]
        d = c[m]
    tem = (y - 1) // 4 + (y - 1) // 400 - (y - 1) // 100
    day += tem * 366 + (y - 1 - tem) * 365
    temp = (day + 1) % 7
    ma = temp % 7 + 1
    for j in range(1, ma):
        print('\t', end="")
    for j in range(1, d + 1):
        print(j, end='\t')
        if ma >= 7 and j != d:
            ma = 0
            print()
        ma += 1
    print()
