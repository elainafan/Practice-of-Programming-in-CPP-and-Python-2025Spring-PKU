def pd(x):
    if x % 4 == 0 and x % 100 != 0:
        return True
    if x % 400 == 0:
        return True
    return False


n = int(input())
rc = [0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 30]
c = [0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 30]
for i in range(1, n + 1):
    lst = input().split()
    m = lst[0].split(':')
    l = lst[1].split('.')
    d = 0
    d += int(l[0]) - 1
    y = int(l[2])
    if pd(y):
        for j in range(1, int(l[1])):
            d += rc[j]
    else:
        for j in range(1, int(l[1])):
            d += c[j]
    tem = 0
    tem += (y - 2001) // 4 + (y - 2001) // 400 - (y - 2001) // 100 + 1
    if y == 2000:
        tem = 0
    d += (y - 2000 - tem) * 365 + tem * 366
    if d % 1000 == 0:
        year = d // 1000
        month = 1
        day = 1
    else:
        year = d // 1000
        if (d % 1000) % 100 == 0:
            month = (d % 1000) // 100 + 1
            day = 1
        else:
            month = (d % 1000) // 100 + 1
            day = d % 100 + 1
    temp = 0
    temp += int(m[0]) * 3600
    temp += int(m[1]) * 60
    temp += int(m[2])
    te = temp * 100000 // 86400
    hour = te // 10000
    minute = (te % 10000) // 100
    second = te % 100
    print(f"{hour}:{minute}:{second} {day}.{month}.{year}")
