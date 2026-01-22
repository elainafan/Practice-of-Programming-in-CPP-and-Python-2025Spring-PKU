n = int(input())
for i in range(1, 2147483647):
    ans = i * n + 1
    flag = 0
    for j in range(0, n - 1):
        if ans % (n - 1) == 0:
            ans = ans * n // (n - 1) + 1
            if j == n - 2:
                flag = 1
                break
            else:
                continue
        else:
            break
    if flag == 1:
        print(ans)
        break
