x = input()
if x[0] == '-':
    t = x[1:]
    res = t[::-1]
    l = len(res)
    flag = 0
    for i in range(0, l):
        if res[i] != '0':
            flag = i
            break
    fi = res[flag:]
    print('-', end='')
    print(fi)
else:
    res = x[::-1]
    if int(x) == 0:
        print("0")
        exit()
    l = len(res)
    flag = 0
    for i in range(0, l):
        if res[i] != '0':
            flag = i
            break
    fi = res[flag:]
    print(fi)
