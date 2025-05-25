n=int(input())
ma=[]
for i in range(0,n):
    lst=input().split()
    id=i
    pd=0
    k=lst[0]
    value=int(lst[1])
    if k[0]=='P' or k[0]=='K' or k[0]=='U':
        pd=1
    ma.append([k,value,pd,id])
ma.sort(key=lambda x:(-x[1],-x[2],x[3]))
for l in ma:
    print(l[0],end=' ')
    print(l[1])