n=int(input())
age=[]
nonage=[]
for i in range(0,n):
    lst=input().split()
    x=lst[0]
    y=int(lst[1])
    if y>=60:
        age.append([x,y,i])
    else:
        nonage.append([x,i])
age.sort(key=lambda x:(-x[1],x[2]))
nonage.sort(key=lambda x:x[1])
for i in range(0,len(age)):
    print(age[i][0])
for i in range(0,len(nonage)):
    print(nonage[i][0])