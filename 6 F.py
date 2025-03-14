def operate(s):
    n=len(s)
    res=['']*n
    index=[0] #采用列表，这样作为可变对象可以传递到外部
    def lower_bound(l,r):
        if l>r:
            return 
        mid=(l+r)//2
        res[mid]=s[index[0]]
        index[0]+=1
        lower_bound(l,mid-1)
        lower_bound(mid+1,r)
    lower_bound(0,n-1)
    return ''.join(res)
u=input()
print(operate(u))
