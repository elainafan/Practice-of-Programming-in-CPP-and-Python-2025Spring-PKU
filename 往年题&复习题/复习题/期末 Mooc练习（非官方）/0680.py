x = input()
l = len(x)
flag = 0
for i in range(0, l):
    if x[i] == x[l - 1 - i]:
        continue
    else:
        flag = 1
        break
if flag == 0:
    print("yes")
else:
    print("no")
