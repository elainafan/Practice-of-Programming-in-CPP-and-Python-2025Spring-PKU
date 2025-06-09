lst=input().split()
n=int(lst[0])
m=int(lst[1])
ans=[0]
ma=[0]
for i in range(1,m+1):
    ans.append(0)
for i in range(1,n+1):
    k=int(input())
    ma.append(k)
    ans[k]+=1
for i in range(1,n+1):
    if ans[ma[i]]==1:
        print("BeiJu")
    else:
        print(ans[ma[i]]-1)