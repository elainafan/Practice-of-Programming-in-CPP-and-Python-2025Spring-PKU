def check(x):
    global n
    if x > n:
        return False
    if x == n:
        return True
    return check(2 * x + 1) or check(3 * x + 1)


lst = input().split(',')
k = int(lst[0])
n = int(lst[1])
if k > n:
    print("NO")
    exit()
t = check(k)
if t == True:
    print("YES")
else:
    print("NO")
