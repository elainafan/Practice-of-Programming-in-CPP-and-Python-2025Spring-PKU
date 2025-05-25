d=int(input())
n=int(input())
mx=[]
my=[]
ma=[]
for i in range(0,n):
    k=input().split()
    mx.append(int(k[0]))
    my.append(int(k[1]))
    ma.append(int(k[2]))
ans=0
ret=0
for i in range(0,1025):
    for j in range(0,1025):
        temp=0
        for k in range(0,n):
            if abs(mx[k]-i)<=d and abs(my[k]-j)<=d:
                temp+=ma[k]
        if temp==ans:
            ret+=1
        if temp>ans:
            ret=1
            ans=temp
print(ret,end=' ')
print(ans)