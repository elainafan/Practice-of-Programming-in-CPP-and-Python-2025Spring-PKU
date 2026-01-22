lst = input().split()
a = float(lst[0])
b = float(lst[1])
c = float(lst[2])
res = a + b + c
d = int(res)
if d == res:
    print(f"{res:.1f}")
else:
    print(res)
