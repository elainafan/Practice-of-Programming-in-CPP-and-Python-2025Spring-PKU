n=int(input())
d=[0]
l=0
beer=[]
ans=1e8
mi=0
for i in range(1,n+1):
    lst=input().split()
    x=int(lst[0])
    y=int(lst[1])
    if(i!=n):
        d.append(d[i-1]+y)
    beer.append(x)
    l+=y
for i in range(0,n):
    temp=0
    for j in range(0,n):
        if i==j:
            continue
        else:
            temp+=beer[j]*min(abs(d[j]-d[i]),l-abs(d[j]-d[i]))
    if temp<ans:
        mi=i
        ans=temp
print(mi,end=',')
print(ans)