def dfs(x):
    global n,ma,pa,dx,dy,mi,tem,flag
    for i in range(1,n+1):
        if pa[x-1][i]==0:
            pa[x][i]=(pa[x][i]+1)%2
            tem+=1
            for k in range(1,5):
                ax=x+dx[k]
                ay=i+dy[k]
                if ax>=1 and ay>=1 and ax<=n and ay<=n:
                    pa[ax][ay]=(pa[ax][ay]+1)%2
    if x!=n:
        dfs(x+1) 
    if x==n:
        f=0
        for i in range(1,n+1):
            if pa[n][i]==0:
                return 
        if tem<mi:
            mi=tem
        flag=1
        return 
    return 
    
n=int(input())
ma=[[]]
pa=[[]]
dx=[0,1,-1,0,0]
dy=[0,0,0,1,-1]
mi=9999
tem=0
for i in range(0,n):
    ma.append([0])
    pa.append([0])
for i in range(1,n+1):
    k=input()
    for j in range(0,n):
        if k[j]=='w':
            ma[i].append(0)
        else:
            ma[i].append(1)
        pa[i].append(0)
for i in range(1,n+1):
    for j in range(1,n+1):
        pa[i][j]=ma[i][j]
if n==1:
    if ma[1][1]==0:
        print(1)
    else:
        print(0)
else:
    flag=0
    for i in range(0,1<<n):
        temp=i
        tem=0
        for j in range(1,n+1):
            if ((temp>>(j-1))&1)==1:
                tem+=1
                pa[1][j]=(pa[1][j]+1)%2
                for k in range(1,5):
                    ax=1+dx[k]
                    ay=j+dy[k]
                    if ax>=1 and ax<=n and ay>=1 and ay<=n:
                        pa[ax][ay]=(pa[ax][ay]+1)%2
        dfs(2)
        for j in range(1,n+1):
            for k in range(1,n+1):
                pa[j][k]=ma[j][k]
    if flag==0:
        print("inf")
    else:
        print(mi)