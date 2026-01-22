n = float(input())
if n >= 0 and n < 5:
    res = 2.5 - n
elif n >= 5 and n < 10:
    res = 2 - (n - 3) * (n - 3) * 1.5
elif n >= 10 and n < 20:
    res = n / 2 - 1.5
print(f"{res:.3f}")
