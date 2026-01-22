lst = input().split()
n = int(lst[0])
a = int(lst[1])
b = int(lst[2])
lst_1 = input().split()
lst_2 = input().split()
tem_a = [0]
tem_b = [0]
for i in range(0, a):
    tem_a.append(int(lst_1[i]))
for i in range(0, b):
    tem_b.append(int(lst_2[i]))
ans_1 = 0
ans_2 = 0
for i in range(1, n + 1):
    x = (i - 1) % a + 1
    y = (i - 1) % b + 1
    if tem_a[x] == tem_b[y]:
        continue
    elif tem_a[x] == 0 and tem_b[y] == 2:
        ans_1 += 1
        continue
    elif tem_a[x] == 0 and tem_b[y] == 5:
        ans_2 += 1
        continue
    elif tem_a[x] == 2 and tem_b[y] == 0:
        ans_2 += 1
        continue
    elif tem_a[x] == 2 and tem_b[y] == 5:
        ans_1 += 1
        continue
    elif tem_a[x] == 5 and tem_b[y] == 0:
        ans_1 += 1
        continue
    elif tem_a[x] == 5 and tem_b[y] == 2:
        ans_2 += 1
        continue
if ans_1 == ans_2:
    print("draw")
elif ans_1 > ans_2:
    print("A")
elif ans_2 > ans_1:
    print("B")
