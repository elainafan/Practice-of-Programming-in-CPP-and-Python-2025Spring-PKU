vis_row = []
vis_xray = []
vis_yray = []
ma = []
coun = 0
for i in range(1, 10):
    temp = [0]
    for j in range(1, 9):
        temp.append(0)
    ma.append(temp)
for i in range(0, 9):
    vis_row.append(0)
for i in range(0, 19):
    vis_xray.append(0)
for i in range(0, 19):
    vis_yray.append(0)


def dfs(x):
    global ma, vis_row, vis_xray, vis_yray, coun
    if x == 9:
        coun += 1
        print(f"No. {coun}")
        for i in range(1, 9):
            for j in range(1, 9):
                print(ma[j][i], end=' ')
            print()
        return
    for i in range(1, 9):
        if vis_row[i] == 0 and vis_xray[i + x] == 0 and vis_yray[i - x +
                                                                 8] == 0:
            vis_row[i] = 1
            vis_xray[i + x] = 1
            vis_yray[i - x + 8] = 1
            ma[x][i] = 1
            dfs(x + 1)
            vis_row[i] = 0
            vis_xray[i + x] = 0
            vis_yray[i - x + 8] = 0
            ma[x][i] = 0
    return


dfs(1)
