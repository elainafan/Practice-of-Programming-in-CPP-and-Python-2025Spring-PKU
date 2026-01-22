def pd(x):
    if x % 4 == 0 and x % 100 != 0:
        return True
    if x % 400 == 0:
        return True
    return False


n = int(input())
rc = [0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 30]
c = [0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 30]
dd = [
    "", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday",
    "Sunday"
]
for i in range(1, n + 1):
    lst = input().split()
    y = int(lst[0])
    m = int(lst[1])
    d = int(lst[2])
    day = 0
    if m >= 13:
        print("Illegal")
        continue
    if pd(y):
        if d > rc[m] or d <= 0:
            print("Illegal")
            continue
    else:
        if d > c[m] or d <= 0:
            print("Illegal")
            continue
    if y >= 0:
        if pd(y):
            for j in range(1, m):
                day += rc[j]
        else:
            for j in range(1, m):
                day += c[j]
        day += d
        tem = 0
        tem = (y - 1) // 4 + (y - 1) // 400 - (y - 1) // 100
        tem += 1
        if y == 0:
            tem = 0
        day += tem * 366 + (y - tem) * 365
        res = (day + 5) % 7
        if res == 0:
            res = 7
        print(dd[res])
    else:
        rday = 0
        if pd(y):
            for j in range(1, m):
                rday += rc[j]
        else:
            for j in range(1, m):
                rday += c[j]
        rday += d - 1
        if pd(y):
            day += 366 - rday
        else:
            day += 365 - rday
        tem = (-(y + 1)) // 4 + (-(y + 1)) // 400 - (-(y + 1)) // 100
        day += (-(y + 1) - tem) * 365 + tem * 366
        res = abs(day) % 7
        res = 6 - res
        if res == 0:
            res = 7
        print(dd[res])
