def pd(x):
    f=first_order[x[1:]]
    g=second_order[x[0]]
    return f,g
while True:
    try:
        lst=input().split()
        first_order={'2':15,'A':14,'K':13,'Q':12,'J':11}
        second_order={'h':3,'s':2,'d':1,'c':0}
        for i in range(10,2,-1):
            first_order[str(i)]=i
        lst_1=sorted(lst,key=pd,reverse=True)
        for i in lst_1:
            print(i,end=' ')
        print()
    except EOFError:
        break