n=int(input())
ans=1e8
for i in range(1,n+1):
    for j in range(i,n+1):
        for k in range(j,n+1):
            if not n==i*j*k:
                continue
            else:
                ans=min(2*(i*j+j*k+k*i),ans)
print(ans)
