n = int(input())
for i in range(0, 105):
    if n % (3**i) == 0 and n % (3**(i + 1)) != 0:
        n = n // (3**i)
        break
for i in range(0, 105):
    if n % (2**i) == 0 and n % (2**(i + 1)) != 0:
        n = n // (2**i)
        break
if n == 1:
    print("yes")
else:
    print("no")
