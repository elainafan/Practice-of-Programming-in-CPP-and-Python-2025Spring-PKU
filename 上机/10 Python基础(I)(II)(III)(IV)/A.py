def pd(x):
    if x == 1:
        return False
    elif x == 2 or x == 3:
        return True
    else:
        for i in range(2, x + 1):
            if i * i > x:
                return True
            if x % i == 0:
                return False
    return True


s = int(input())
ans = 0
for i in range(1, (s // 2) + 1):
    if pd(i) == True and pd(s - i) == True:
        ans = max(ans, i * (s - i))
print(ans)
