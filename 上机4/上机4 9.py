n=int(input())
ans=1e8
for i in range(1,n+1):
    if i*i*i>n:
        break
    for j in range(i,n+1):
        for k in range(j,n+1):
            if n==i*j*k:
                ans=min(ans,2*(i*j+j*k+k*i))
print(ans)