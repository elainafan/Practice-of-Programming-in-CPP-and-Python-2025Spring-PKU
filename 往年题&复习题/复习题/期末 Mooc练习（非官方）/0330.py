x = int(input())
flag = 0
if x < 0:
    flag = 1
    x = -x
if x == 0:
    print(0)
    exit()
lst = []
while x > 0:
    t = x % 2
    lst.append(t)
    x //= 2
l = len(lst)
res = lst[::-1]
if flag == 1:
    print("-", end='')
for i in range(0, l):
    print(res[i], end='')
