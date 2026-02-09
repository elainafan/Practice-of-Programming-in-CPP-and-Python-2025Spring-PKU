import math

lst = input().split()
n = int(lst[0])
a = int(lst[1])
b = int(lst[2])
te = 0
tem = 1
temp = 0
for i in range(1, n + 1):
    for j in range(1, i):

        if j / i < a / b and j / i > te / tem and math.gcd(i, j) == 1:
            te = j
            tem = i
print(te, end=' ')
print(tem)
