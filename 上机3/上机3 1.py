n=int(input())
ans=0
res=1
for i in range(1,n+1):
    res*=i
    ans+=res
print(ans)