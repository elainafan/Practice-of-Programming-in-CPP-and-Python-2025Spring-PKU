n=int(input())
for i in range(1,2147483647):
    temp=i*n+1
    flag=0
    for j in range(0,n-1):
        if (temp*n)%(n-1)==0:
            if(j==n-2):
                temp=(temp*n)//(n-1)+1
                flag=1
            else:
                temp=(temp*n)//(n-1)+1
        else:
            break
    if flag==0:
        continue
    else:
        print(temp)
        break