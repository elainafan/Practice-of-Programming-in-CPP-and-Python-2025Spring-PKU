lst=input().split()
n=int(lst[0])
x=int(lst[1])
y=int(lst[2])
dict={}
for i in range(1,n+1):
    k=input().split()
    a=k[0]
    b=k[1]
    c=int(k[2])
    if b in dict:
        dict[b][1]+=1
        dict[b][0]+=c
    else:
        dict[b]=[c,1]
m=int(input())
for i in range(1,m+1):
    k=input()
    if dict[k][1]>=x and dict[k][0]/dict[k][1]>y:
        print("yes")
    else:
        print("no")