n = int(input())
dict = {}
name = []
dict_2 = {}
for i in range(1, n + 1):
    k = input().split()
    x = k[0]
    y = k[1]
    z = int(k[2])
    if y not in name:
        name.append(y)
    if y in dict:
        dict[y][x] = z
    else:
        dict[y] = {}
        dict[y][x] = z
m = int(input())
for i in range(1, m + 1):
    k = input().split()
    num = int(k[0])
    ma = 0
    res = []
    for j in name:
        temp = 0
        flag = 1
        for v in range(1, num + 1):
            if k[v] in dict[j].keys():
                temp += dict[j][k[v]]
            else:
                flag = 0
                break
        temp = temp / num
        if flag == 0:
            continue
        if temp > ma:
            ma = temp
            res.clear()
            res.append(j)
        elif temp == ma:
            res.append(j)
    res.sort()
    print(res[0])
