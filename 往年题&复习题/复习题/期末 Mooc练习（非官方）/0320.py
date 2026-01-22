lst = input().split()
a = int(lst[0])
b = int(lst[1])
c = int(lst[2])
ma = max(a, b, c)
for i in range(ma, a * b * c + 1):
    if i % a == 0 and i % b == 0 and i % c == 0:
        print(i)
        break
