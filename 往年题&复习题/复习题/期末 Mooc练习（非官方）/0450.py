n = int(input())
mi = 0
temp = 0
for i in range(1, n + 1):
    lst = input().split()
    x = int(lst[0])
    y = int(lst[1])
    if x >= 90 and x <= 140 and y >= 60 and y <= 90:
        temp += 1
    else:
        temp = 0
    mi = max(mi, temp)
print(mi)
