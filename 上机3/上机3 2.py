lst=input().split()
x=int(lst[0])
y=int(lst[1])
d=lst[2]
z=int(lst[3])
if z==1:
    for i in range(0,x):
        for j in range(0,y):
            print(d,end='')
        print()
elif z==0:
    for i in range(0,x):
        if i==0 or i==x-1:
            for j in range(0,y):
                print(d,end='')
            print()
        else:
            for j in range(0,y):
                if j==0 or j==y-1:
                    print(d,end='')
                else:
                    print(' ',end='')
            print()