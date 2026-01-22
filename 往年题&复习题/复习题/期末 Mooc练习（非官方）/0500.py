n = int(input())
lst = [0, 1, 2]
for i in range(3, n + 1):
    x = lst[i - 1]
    y = lst[i - 2]
    lst.append(x + y)
print(lst[n])
