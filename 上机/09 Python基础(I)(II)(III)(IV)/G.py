n = int(input())
ans = []
for i in range(0, n):
    lst = input().split()
    a = int(lst[2])
    b = int(lst[3])
    c = int(lst[4])
    temp = a + b + c
    x = lst[0]
    y = lst[1]
    ans.append([temp, a, b, c, y, x])
ans.sort(key=lambda x: (-x[0], -x[1], -x[2], x[4], x[5]))
for i in range(0, n):
    print(i + 1, end=' ')
    print(ans[i][5])
