lst=input().split()
n=int(lst[0])
m=int(lst[1])
a=[]
b=[]
for i in range(0,n):
    a.append([])
    k=input().split()
    for j in range(0,m):
        a[i].append(int(k[j]))
for i in range(0,n):
    b.append([])
    k=input().split()
    for j in range(0,m):
        b[i].append(int(k[j]))
for i in range(0,n):
    for j in range(0,m):
        a[i][j]=a[i][j]+b[i][j]
for i in range(0,n):
    for j in range(0,m):
        print(a[i][j],end=' ')
    print()