n = int(input())
ans = [0]
res = [0]
for i in range(1, 101):
    ans.append(0)
    res.append([])
for i in range(0, n):
    k = input().split()
    t = int(k[0])
    z = int(k[1])
    for j in range(2, z + 2):
        x = int(k[j])
        ans[x] += 1
        if t in res[x]:
            pass
        else:
            res[x].append(t)
mi = max(ans)
mixx = ans.index(mi)
print(mixx)
res[mixx].sort()
for i in res[mixx]:
    print(i, end=' ')