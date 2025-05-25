k=input().split()
n=int(k[0])
m=int(k[1])
ans=0
ret=0
ma=[[]]
for i in range(1,n+m+1):
    ma.append([0])
for i in range(n+1,n+m+1):
    for j in range(1,n+m+1):
        ma[i].append(0)
for i in range(1,n+1):
    t=input().split()
    for j in range(0,n):
        ma[i].append(int(t[j]))
for i in range(1,n+1):
    for j in range(n+1,n+m+1):
        ma[i].append(0)
for i in range(1,n+1):
    for j in range(1,n+1):
        temp=0
        for k in range(i,i+m):
            for v in range(j,j+m):
                temp+=ma[k][v]
        if temp==ans:
            ret+=1
        if temp>ans:
            ans=temp
            ret=1
print(ans,end=' ')
print(ret)