lst = input().split()
n = int(lst[0])
m = int(lst[1])
ans = [0] * (m + 1)
ma = [0] * (n + 1)
for i in range(1, n + 1):
    k = int(input())
    ma[i] = k
    ans[k] += 1
for i in range(1, n + 1):
    if ans[ma[i]] == 1:
        print("BeiJu")
    else:
        print(ans[ma[i]] - 1)