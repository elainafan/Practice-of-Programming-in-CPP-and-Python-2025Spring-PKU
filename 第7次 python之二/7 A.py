lst=input().split()
n=int(lst[0])
m=int(lst[1])
kd=[]
for i in range(0,n):
    kd.append([])
for i in range(0,n):
    x=input().split()
    for j in range(0,m):
        tem=int(x[j])
        kd[i].append(tem)
for i in range(0,m):
    for j in range(0,n):
        print(kd[j][i],end=' ')
    print()