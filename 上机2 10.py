lst=input().split()
n=int(lst[0])
m=int(lst[1])
l=['0']
k=[]
for i in range(1,n+1):
    l.append(1)
for i in range(1,m+1):
    for j in range(1,n+1):
        if j%i==0:
            if l[j]==0:
                l[j]=1
            elif l[j]==1:
                l[j]=0
        else:
            pass
for i in range(1,n+1):
    if l[i]==0:
        k.append(i)
res=','.join(str(item) for item in k)
print(res)