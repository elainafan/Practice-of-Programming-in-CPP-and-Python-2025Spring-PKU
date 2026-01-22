n = int(input())
lst = [0, 0, 0]
for i in range(1, n + 1):
    l = input().split()
    a = int(l[0])
    b = int(l[1])
    c = int(l[2])
    lst[0] += a
    lst[1] += b
    lst[2] += c
ans = lst[0] + lst[1] + lst[2]
print(lst[0], end=' ')
print(lst[1], end=' ')
print(lst[2], end=' ')
print(ans)
