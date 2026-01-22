n = int(input())
dict = {}
for i in range(1, n + 1):
    lst = input().split('-')
    temp = lst[0]
    if temp in dict:
        dict[temp] += 1
    else:
        dict[temp] = 1
    for j in range(1, len(lst)):
        temp = temp + '-' + lst[j]
        if temp in dict:
            continue
        else:
            dict[temp] = 1
m = int(input())
for i in range(1, m + 1):
    k = input()
    if k in dict:
        print("Yes")
    else:
        print("No")
