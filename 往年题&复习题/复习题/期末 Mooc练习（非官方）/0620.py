dict = {}
while True:
    try:
        k = input()
        if k in dict:
            dict[k] += 1
        else:
            dict[k] = 1
    except EOFError:
        break
lst = sorted(dict.items(), key=lambda x: (-x[1], x[0]))
for item in lst:
    print(item[1], end=' ')
    print(item[0])
