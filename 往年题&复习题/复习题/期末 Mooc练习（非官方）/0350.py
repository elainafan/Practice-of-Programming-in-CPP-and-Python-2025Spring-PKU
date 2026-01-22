n = int(input())
l = [1, 1]
for i in range(2, n + 1):
    x = l[i - 1]
    y = l[i - 2]
    l.append(x + y)
print(l[n - 1])
