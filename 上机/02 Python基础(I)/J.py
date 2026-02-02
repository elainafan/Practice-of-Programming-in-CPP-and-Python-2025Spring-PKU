lst = input().split()
n = int(lst[0])
m = int(lst[1])
l = [1] * n
tem = []
for i in range(0, m):
    for j in range(0, n):
        if (j + 1) % (i + 1) == 0:
            if l[j] == 0:
                l[j] = 1
            elif l[j] == 1:
                l[j] = 0
        else:
            pass
for i in range(0, n):
    if l[i] == 0:
        tem.append(i + 1)
res = ",".join(str(item) for item in tem)
print(res)
