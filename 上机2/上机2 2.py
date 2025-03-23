lst=input().split()
n=int(lst[0])
x=int(lst[1])
y=int(lst[2])
if y%x==0:
    d=y//x
    print(n-d)
elif y%x!=0:
    d=y//x+1
    print(n-d)