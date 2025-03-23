lst=input().split()
m=int(lst[0])
n=int(lst[1])
ans=0
for i in range(m,n+1):
    if i%17==0:
        ans+=i
print(ans)