n=int(input())
d=[0]
beer=[]
ans=1e8
res=0
l=0
for i in range(0,n):
    lst=input().split()
    x=int(lst[0])
    y=int(lst[1])
    beer.append(x)
    d.append(d[i]+y)
    l+=y
for i in range(0,n):
    temp=0
    for j in range(0,n):
        if i==j:
            continue
        else:
            temp+=beer[j]*min(abs(d[j]-d[i]),abs(l-(d[j]-d[i])))
    if temp<ans:
        res=i
        ans=temp
print(res,ans)