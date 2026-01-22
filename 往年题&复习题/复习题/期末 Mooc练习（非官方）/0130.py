lst = input().split()
a = int(lst[0])
b = int(lst[1])
c = int(lst[2])
if a + b > c and b + c > a and c + a > b:
    print("yes")
else:
    print("no")
