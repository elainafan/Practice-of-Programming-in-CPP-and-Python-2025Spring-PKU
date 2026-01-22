x = input()
a = [' ', ' ', x, ' ', ' ']
b = [' ', x, x, x, ' ']
c = [x, x, x, x, x]
d = [' ', x, x, x, ' ']
e = [' ', ' ', x, ' ', ' ']
for i in range(0, 5):
    if i == 4:
        print(a[i])
    else:
        print(a[i], end='')
for i in range(0, 5):
    if i == 4:
        print(b[i])
    else:
        print(b[i], end='')
for i in range(0, 5):
    if i == 4:
        print(c[i])
    else:
        print(c[i], end='')
for i in range(0, 5):
    if i == 4:
        print(d[i])
    else:
        print(d[i], end='')
for i in range(0, 5):
    if i == 4:
        print(e[i])
    else:
        print(e[i], end='')
