lst=input().split()
x=int(lst[0])
y=int(lst[1])
z=lst[2]
if z=="+":
    print(x+y)
elif z=='-':
    print(x-y)
elif z=='*':
    print(x*y)
elif z=='/' and y!=0:
    print(x//y)
elif z=='/' and y==0:
    print("Divided by zero!")
else:
    print("Invalid operator!")