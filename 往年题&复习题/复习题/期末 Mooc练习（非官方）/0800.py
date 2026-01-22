t = int(input())
for i in range(1, t + 1):
    n = int(input())
    dict = {}
    for j in range(1, 10 * n + 1):
        lst = input().split()
        if lst[0] in dict:
            dict[lst[0]][0] += 1
            dict[lst[0]][1] += int(lst[1])
            dict[lst[0]][2] = dict[lst[0]][1] / dict[lst[0]][0]
        else:
            dict[lst[0]] = [1, int(lst[1]), int(lst[1])]
    ans = sorted(dict.items(), key=lambda x: (x[1][2]))
    print(ans[0][0])
