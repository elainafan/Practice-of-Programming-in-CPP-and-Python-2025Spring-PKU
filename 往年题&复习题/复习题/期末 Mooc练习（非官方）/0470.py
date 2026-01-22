def seven(x):
    tem = []
    m = x
    while m > 0:
        temp = m % 7
        tem.append(temp)
        m //= 7
    return tem


def nine(x):
    tem = []
    m = x
    while m > 0:
        temp = m % 9
        tem.append(temp)
        m //= 9
    return tem


for i in range(49, 729):
    if seven(i) == nine(i)[::-1]:
        print(i)
        lst_1 = seven(i)[::-1]
        lst_2 = nine(i)[::-1]
        l_1 = len(lst_1)
        l_2 = len(lst_2)
        for j in range(0, l_1):
            print(lst_1[j], end='')
        print()
        for j in range(0, l_2):
            print(lst_2[j], end='')
