#pylint: disable = no-value-for-parameter
def accfunc(f):

    def inner(g=None):
        if g is None:
            return f
        else:
            return accfunc(lambda x: g(f(x)))

    return inner


def f1(x):
    return x + 1


def f2(x):
    return x * x


def f3(x):
    return x + x


def f4(x):
    return x * 3


def f5(x):
    return x - 4


while True:
    try:
        s = input().strip()
        n = int(input())
        funcs = s.split()
        k = accfunc  # 初始化为accfunc函数
        for func_name in funcs:
            func = eval(func_name)  # 获取对应的函数对象
            k = k(func)  # 将当前函数添加到组合链
        # 获取最终的组合函数并调用
        composed_func = k()
        print(composed_func(n))
    except:
        break
