import copy


def unwrap_single(x):
    if isinstance(x, int):
        return x
    elif isinstance(x, list):
        if len(x) == 1:
            return unwrap_single(x[0])
        else:
            lst = []
            for tem in x:
                lst.append(unwrap_single(tem))
            return lst
    elif isinstance(x, tuple):
        if len(x) == 1:
            return unwrap_single(x[0])
        else:
            lst = []
            for tem in x:
                lst.append(unwrap_single(tem))
            return tuple(lst)


T = int(input())
for _ in range(T):
    obj = eval(input())
    backup = copy.deepcopy(obj)
    result = unwrap_single(obj)
    assert obj == backup, "输入对象被修改"
    print(result)
