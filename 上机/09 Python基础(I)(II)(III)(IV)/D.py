n = int(input())
dict = {}
for i in range(0, n):
    lst = input().split()
    x = int(lst[0])
    y = int(lst[2])
    if lst[1] not in dict:
        if y == 0:
            dict[lst[1]] = [0, 1, x]
        else:
            dict[lst[1]] = [1, 0, x]
    else:
        if y == 0:
            dict[lst[1]][1] += 1
        else:
            dict[lst[1]][0] += 1
        dict[lst[1]][2] = min(dict[lst[1]][2], x)
dict_2 = sorted(dict.items(), key=lambda x: (-x[1][0], -x[1][1], x[1][2]))
for l in dict_2:
    print(l[0], end=' ')
    print(l[1][0], end=' ')
    print(l[1][1])
