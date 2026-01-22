lst = input().split(',')
s = lst[0]
a = lst[1]
b = lst[2]
l = s.find(a)
r = s.rfind(b)
if l == -1 or r == -1:
    print(-1)
    exit()
if r - l >= len(a):
    print(r - l - len(a))
else:
    print(-1)
