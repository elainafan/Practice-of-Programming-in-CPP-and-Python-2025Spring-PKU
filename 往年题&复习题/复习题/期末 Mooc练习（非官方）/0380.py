def check(x):
    if x == 1:
        return
    if x % 2 == 1:
        res = x * 3 + 1
        print(f"{x}*3+1={res}")
        check(res)
    if x % 2 == 0:
        res = x // 2
        print(f"{x}/2={res}")
        check(res)


n = int(input())
check(n)
print("End")
