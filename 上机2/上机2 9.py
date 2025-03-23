n=int(input())
ans=0
lst=input().split()
for i in range(0,n):
    x=int(lst[i])
    a=x%10
    b=(x%100-a)//10
    c=(x%1000-b*10-a)//100
    d=x//1000
    if a-d-c-b>0:
        ans+=1
print(ans)