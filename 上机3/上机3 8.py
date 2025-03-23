n=int(input())
ma=[]
ans=0
for i in range(0,n):
    ma.append([])
    k=input().split()
    for j in range(0,n):
        ma[i].append(int(k[j]))
lx=0 
ly=0
for i in range(0,n):
    flag=0
    for j in range(0,n):
        if ma[i][j]==0:
            lx=i
            ly=j
            flag=1
            break
    if flag==1:
        break
rx=0 
ry=0
for i in range(n-1,-1,-1):
    flag=0
    for j in range(n-1,-1,-1):
        if ma[i][j]==0:
            rx=i
            ry=j
            flag=1
            break
    if flag==1:
        break
ans=(rx-lx-1)*(ry-ly-1)
print(ans)