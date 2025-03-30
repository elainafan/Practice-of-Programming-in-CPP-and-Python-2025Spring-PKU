n=int(input())
p=[0,1]
q=[0,2]
ans=0
for i in range(1,n):
    q.append(p[i]+q[i])
    p.append(q[i])
for i in range(1,n+1):
    ans+=q[i]/p[i]
print(f"{ans:.4f}")