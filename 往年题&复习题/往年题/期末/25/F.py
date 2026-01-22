def trans(x):
    if x == 'S':
        return 1
    elif x == 'H':
        return 2
    elif x == 'C':
        return 3
    elif x == 'D':
        return 4


def trans_2(x):
    if x == '2':
        return 15
    elif x == 'A':
        return 14
    elif x == 'K':
        return 13
    elif x == 'Q':
        return 12
    elif x == 'J':
        return 11
    elif x == 'T':
        return 10
    else:
        return int(x)


while True:
    try:
        lst = input().split()
        dic = []
        for i in range(0, 18):
            dic.append([])
        for i in range(0, len(lst)):
            if lst[i] == "BJ":
                dic[17].append("BJ")
                continue
            if lst[i] == "LJ":
                dic[16].append("LJ")
                continue
            temp = trans_2(lst[i][0])
            tem = trans(lst[i][1])
            dic[temp].append([lst[i], tem])
        for i in range(0, len(dic[17])):
            print("BJ", end=" ")
        for i in range(0, len(dic[16])):
            print("LJ", end=" ")
        if len(dic[17]) + len(dic[16]) != 0:
            print()
        for i in range(15, 2, -1):
            if len(dic[i]) == 0:
                continue
            dic[i].sort(key=lambda x: (x[1]))
            for j in range(0, len(dic[i])):
                print(dic[i][j][0], end=" ")
            print()
        print()
    except EOFError:
        break
