lst = input().split()
x = float(lst[0])
a = float(lst[1])
b = float(lst[2])
c = float(lst[3])
d = float(lst[4])
res = a * (x**3) + b * (x**2) + c * x + d
print(f"{res:.7f}")
