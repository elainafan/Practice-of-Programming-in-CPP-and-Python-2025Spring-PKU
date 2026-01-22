def combine(f, g):

    def k(x):
        return f(g(x))

    return k


# 在此处补充你的代码
def square(x):
    return x * x


def double(x):
    return x + x


n = int(input())
f = combine(square, double)
#提示： f(x) = square(double(x))
print(f(n))
g = combine(f, double)
#提示: g(x) = f(double(x))
print(g(n))
