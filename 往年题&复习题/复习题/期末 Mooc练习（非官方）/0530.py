def check(x, y):
    if x % y == 0:
        print(y)
        exit()
    elif y % x == 0:
        print(x)
        exit()
    if x > y:
        check(y, x % y)
    else:
        check(x, y % x)


lst = input().split()
a = int(lst[0])
b = int(lst[1])
check(a, b)
