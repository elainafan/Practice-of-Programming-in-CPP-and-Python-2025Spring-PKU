def pd(x):
    if x % 4 == 0 and x % 100 != 0:
        return True
    elif x % 400 == 0:
        return True
    return False


n = int(input())
for i in range(1, n + 1):
    lst = input().split()
    y = int(lst[0])
    m1 = int(lst[1])
    m2 = int(lst[2])
    if m2 < m1:
        tem = m2
        m2 = m1
        m1 = tem
    if pd(y):
        if m1 == 1:
            if m2 == 4 or m2 == 7:
                print("YES")
            else:
                print("NO")
            continue
        elif m1 == 2:
            if m2 == 8:
                print("YES")
            else:
                print("NO")
            continue
        elif m1 == 3:
            if m2 == 11:
                print("YES")
            else:
                print("NO")
            continue
        elif m1 == 4:
            if m2 == 7:
                print("YES")
            else:
                print("NO")
            continue
        elif m1 == 9:
            if m2 == 12:
                print("YES")
            else:
                print("NO")
            continue
        else:
            print("NO")
    else:
        if m1 == 1:
            if m2 == 10:
                print("YES")
            else:
                print("NO")
            continue
        elif m1 == 2:
            if m2 == 11 or m2 == 3:
                print("YES")
            else:
                print("NO")
            continue
        elif m1 == 3:
            if m2 == 11:
                print("YES")
            else:
                print("NO")
            continue
        elif m1 == 4:
            if m2 == 7:
                print("YES")
            else:
                print("NO")
            continue
        elif m1 == 9:
            if m2 == 12:
                print("YES")
            else:
                print("NO")
            continue
        else:
            print("NO")
