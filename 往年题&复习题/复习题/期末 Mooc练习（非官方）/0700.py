n = int(input())
for i in range(1, n + 1):
    lst = input().split()
    s1 = lst[0]
    s2 = lst[1]
    l = 0
    ans = 0
    while True:
        if s1.find(s2, l) == -1:
            break
        ans += 1
        print(s1.find(s2, l), end=' ')
        l = s1.find(s2, l) + len(s2)
    if ans == 0:
        print("no")
    else:
        print()
