exit = None
def times(n):
    num = 0
    while True:
        yield num
        num += n
# 在此处补充你的代码
n,m = map(int,input().split())
seq = times(n)
if str(type(seq)) == "<class 'generator'>":
    i = 0
    for x in seq:
        print(x)
        i += 1
        if i == m:
            break