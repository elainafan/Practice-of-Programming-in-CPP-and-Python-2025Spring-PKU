import math

s = int(input())
mi = float("inf")
for i in range(1, int(math.sqrt(s)) + 1):
    if s % i == 0:
        l = s // i
        c = 2 * (l + i)
        mi = min(c, mi)
print(mi)
