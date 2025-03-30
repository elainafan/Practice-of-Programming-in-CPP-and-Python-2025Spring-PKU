x=input()
l=len(x)
ans=0
k=""
temp=0
for i in range(0,l):
    if i==0:
        temp=1
        ans=1
        k=x[0]
    else:
        if x[i]!=x[i-1]:
            temp=1
            if temp>ans:
                ans=temp
                k=x[i-1]
            continue
        else:
            if i!=l-1:
                temp+=1
                continue
            else:
                temp+=1
                if temp>ans:
                    ans=temp
                    k=x[i]
print(k,ans)
            
