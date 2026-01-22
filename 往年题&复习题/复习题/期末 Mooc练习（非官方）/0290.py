lst = input().split()
x = lst[0]
n = int(lst[1])
for i in range(1, n + 1):
    for j in range(1, i + 1):
        print(x, end='')
    print()
