lst = input().split()
l = int(lst[0])
m = int(lst[1])
tr = [1]
for i in range(1, l + 1):
    tr.append(1)
for i in range(1, m + 1):
    k = input().split()
    st = int(k[0])
    ft = int(k[1])
    for j in range(st, ft + 1):
        tr[j] = 0
ans = 0
for i in range(0, l + 1):
    if tr[i] == 1:
        ans += 1
print(ans)
