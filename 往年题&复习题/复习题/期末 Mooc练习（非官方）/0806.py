n = int(input())
dict = {}
for i in range(1, n + 1):
    lst = input().split()
    name = lst[0]
    score = int(lst[1])
    if name in dict:
        dict[name][0] += 1
        dict[name][1] += score
    else:
        dict[name] = [1, score]
lst = sorted(dict.items(), key=lambda x: (-x[1][1], x[1][0], x[0]))
for item in lst:
    print(item[0], end=' ')
    print(item[1][0], end=' ')
    print(item[1][1])
