def deepcopy(a):
    if isinstance(a, list):
        tem = []
        for item in a:
            tem.append(deepcopy(item))
        return tem
    elif isinstance(a, tuple):
        tem = tuple(deepcopy(item) for item in a)
        return tem
    else:
        return a


a = [1, 2, [3, [4], 5], (6, [7, [8], 9])]
b = deepcopy(a)
print(b)
a[2][1].append(400)
a[3][1][1].append(800)
print(a)
print(b)
