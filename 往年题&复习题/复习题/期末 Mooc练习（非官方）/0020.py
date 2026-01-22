x = input()
lst = [' ', ' ', x, ' ', ' ']
bst = [' ', x, x, x, ' ']
rst = [x, x, x, x, x]
for i in range(0, 5):
    if i == 4:
        print(lst[i])
    else:
        print(lst[i], end='')
for i in range(0, 5):
    if i == 4:
        print(bst[i])
    else:
        print(bst[i], end='')
for i in range(0, 5):
    print(rst[i], end='')
