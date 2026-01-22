def trans_1(x):
    if x == 'h':
        return 4
    elif x == 's':
        return 3
    elif x == 'd':
        return 2
    elif x == 'c':
        return 1


def trans_2(x):
    if x == 'J':
        return 11
    elif x == 'Q':
        return 12
    elif x == 'K':
        return 13
    elif x == 'A':
        return 14
    elif x == '2':
        return 15
    else:
        return int(x)


while True:
    try:
        lst = input().split()
        ans = []
        cnt = 0
        for i in range(0, len(lst)):
            a = trans_1(lst[i][0])
            b = trans_2(lst[i][1:])
            ans.append([a, b, lst[i]])
        ans.sort(key=lambda x: (-x[1], -x[0]))
        for item in ans:
            print(item[2], end=' ')
        print()
    except EOFError:
        break
