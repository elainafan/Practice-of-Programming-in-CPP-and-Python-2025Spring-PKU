lst = input().split()
r = int(lst[0])
c = int(lst[1])
ma = [[0] * (c + 2) for _ in range(r + 2)]
for i in range(1, r + 1):
    k = input().split()
    for j in range(0, c):
        ma[i][j + 1] += int(k[j])
n = int(input())
for i in range(1, n + 1):
    k = input().split()
    x = int(k[0]) + 1
    y = int(k[1]) + 1
    temp = 0
    if ma[x][y] == 1:
        print("BOOM!")
        continue
    else:
        temp += ma[x - 1][y]
        temp += ma[x + 1][y]
        temp += ma[x][y - 1]
        temp += ma[x][y + 1]
        temp += ma[x - 1][y - 1]
        temp += ma[x - 1][y + 1]
        temp += ma[x + 1][y - 1]
        temp += ma[x + 1][y + 1]
        print(temp)
