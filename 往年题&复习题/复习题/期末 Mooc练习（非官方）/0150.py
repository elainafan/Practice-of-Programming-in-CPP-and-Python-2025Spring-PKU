lst = input()
num = 0
if lst[len(lst) - 1] == 'F' or lst[len(lst) - 1] == 'f':
    num = float(lst[:len(lst) - 1])
    res = (num - 32) * 1.0 / 1.8
    if abs(round(res) - res) <= 1e-4:
        print(round(res), end='')
        print('C')
    else:
        print(f"{res:.2f}", end='')
        print('C')
else:
    num = float(lst[:len(lst) - 1])
    res = num * 1.8 + 32
    tem = int(res)
    if res == tem:
        print(tem, end='')
        print('F')
    else:
        print(f"{res:.2f}", end='')
        print('F')
