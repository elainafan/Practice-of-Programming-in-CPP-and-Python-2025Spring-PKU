x = input()
l = len(x)
for i in range(2, l + 1):
    for j in range(0, l + 1 - i):
        res = x[j:(j + i)]
        k = res[::-1]
        if k == res:
            print(res)
