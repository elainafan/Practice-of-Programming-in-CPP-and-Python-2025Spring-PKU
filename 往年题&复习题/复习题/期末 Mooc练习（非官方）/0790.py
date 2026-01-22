ans = []
for i in range(0, 5):
    ans.append([])
    k = input().split()
    for j in range(0, 5):
        ans[i].append(int(k[j]))
ma = []
for i in range(0, 5):
    ma.append([0])
    for j in range(0, 5):
        ma[i][0] = max(ma[i][0], ans[i][j])
mi = []
for i in range(0, 5):
    mi.append([999999])
    for j in range(0, 5):
        mi[i][0] = min(mi[i][0], ans[j][i])
flag = 0
for i in range(0, 5):
    for j in range(0, 5):
        if ans[i][j] == ma[i][0] and ans[i][j] == mi[j][0]:
            flag = 1
            print(i + 1, j + 1, ans[i][j])
if flag == 0:
    print("not found")
