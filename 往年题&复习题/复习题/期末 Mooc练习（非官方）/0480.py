def check(x):
    return x.swapcase()


n = int(input())
for i in range(0, n):
    t = input()
    k = input().split()
    l = len(k)
    for j in range(0, l):
        ans = 0
        d = len(k[j])
        for v in range(0, d):
            if k[j][v] == t or check(k[j][v]) == t:
                ans += 1
        print(ans, end=' ')
    print()
