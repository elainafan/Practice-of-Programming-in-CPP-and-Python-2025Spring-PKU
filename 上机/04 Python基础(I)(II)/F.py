x = input()
y = input()
dict_1 = {}
dict_2 = {}
for i in range(0, len(x)):
    if x[i] not in dict_1:
        dict_1[x[i]] = 1
    else:
        dict_1[x[i]] += 1
for i in range(0, len(y)):
    if y[i] not in dict_2:
        dict_2[y[i]] = 1
    else:
        dict_2[y[i]] += 1
list_1 = []
list_2 = []
for i in dict_1.values():
    list_1.append(i)
for i in dict_2.values():
    list_2.append(i)
list_1.sort()
list_2.sort()
flag = 1
for i in range(0, max(len(list_1), len(list_2))):
    if list_1[i] == list_2[i]:
        continue
    else:
        flag = 0
        break
if flag == 0:
    print("NO")
else:
    print("YES")
