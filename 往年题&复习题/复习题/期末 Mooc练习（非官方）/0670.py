lst = input()
flag = 0
for i in range(0, len(lst)):
    if lst.count(lst[i]) == 1:
        flag = 1
        print(lst[i])
        break
if flag == 0:
    print("no")
