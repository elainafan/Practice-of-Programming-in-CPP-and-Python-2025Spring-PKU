n=int(input())
man=[]
woman=[]
for i in range(0,n):
    lst=input().split()
    x=lst[0]
    y=float(lst[1])
    if x=="male":
        man.append(y)
    else:
        woman.append(y)
man.sort()
woman.sort(reverse=True)
for i in man:
    print(f"{i:.2f}",end=' ')
for i in woman:
    print(f"{i:.2f}",end=' ')