x=input()
mi=""
ans=0
temp=0
for i in range(0,len(x)):
    if i==0:
        ans=1
        temp=1
        mi=x[i]
        continue
    if x[i]==x[i-1]:
        if i==len(x)-1:
            temp+=1
            if temp>ans:
                mi=x[i]
                ans=temp
        else:
            temp+=1
    else:
        if temp>ans:
            ans=temp
            mi=x[i-1]
        temp=1
print(mi,end=' ')
print(ans)