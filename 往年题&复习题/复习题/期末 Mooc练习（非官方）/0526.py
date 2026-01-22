lst = input().split()
p = int(lst[0])
e = int(lst[1])
k = int(lst[2])
d = int(lst[3])
for i in range(1, 21253):
    if (d + i - p) % 23 == 0 and (d + i - e) % 28 == 0 and (d + i -
                                                            k) % 33 == 0:
        print(i)
        exit()
