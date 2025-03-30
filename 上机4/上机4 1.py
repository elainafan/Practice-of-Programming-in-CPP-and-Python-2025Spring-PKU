n=int(input())
p=[0,1]
q=[0,2]
ans=0
for i in range(2,n+1):
    p.append(q[i-1])
    q.append(p[i-1]+q[i-1])
for i in range(1,n+1):
    ans+=q[i]/p[i]
print(f"{ans:.4f}")