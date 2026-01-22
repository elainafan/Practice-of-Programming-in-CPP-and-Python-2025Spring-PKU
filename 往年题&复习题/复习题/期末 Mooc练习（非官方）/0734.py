n = int(input())
ans = []
for i in range(0, n):
    lst = input().split()
    ans.append([lst[0], int(lst[1])])
ans.sort(key=lambda x: (-x[1], x[0]))
for i in range(0, n):
    print(ans[i][0], end=' ')
    print(ans[i][1])
