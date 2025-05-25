def dfs(x,y):
    global n,ma,vis,dx,dy,flag
    if x==n and y==n:
        flag=1
        return 
    for i in range(1,3):
        ax=x+dx[i]
        ay=y+dy[i]
        if ax>=1 and ay>=1 and ax<=n and ay<=n and vis[ax][ay]==0 and ma[ax][ay]==0:
            vis[ax][ay]=1
            dfs(ax,ay)
            vis[ax][ay]=0
n=int(input())
ma=[[]]
vis=[[]]
dx=[0,1,0]
dy=[0,0,1]
for i in range(0,n):
    ma.append([0])
    vis.append([0])
for i in range(1,n+1):
    lst=input().split()
    for j in range(0,n):
        ma[i].append(int(lst[j]))
        vis[i].append(0)
vis[1][1]=1
flag=0
dfs(1,1)
if flag==1:
    print("Yes")
else:
    print("No")