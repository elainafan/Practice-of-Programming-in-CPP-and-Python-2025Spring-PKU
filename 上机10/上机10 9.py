while True:
    try:
        lst=input()
        flag1=0
        flag2=0
        flag3=0
        flag4=0
        if len(lst)>8:
            flag3=1
        for i in range(0,len(lst)):
            if lst[i]=='#' or lst[i]=='*' or lst[i]=='&':
                flag1=1
            if lst[i]>='0' and lst[i]<='9':
                flag4=1
            if lst[i]>='a' and lst[i]<='z':
                flag2=1
            if lst[i]>='A' and lst[i]<='Z':
                flag2=1
        if flag1==1 and flag2==1 and flag3==1 and flag4==1:
            print("YES")
        else:
            print("NO")
    except EOFError:
        break