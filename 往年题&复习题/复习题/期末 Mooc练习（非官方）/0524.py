n = int(input())
for i in range(2, n + 1):
    for j in range(2, i):
        for k in range(j, i):
            for v in range(k, i):
                if i**3 == j**3 + k**3 + v**3:
                    print(f"Cube = {i}, Triple = ({j},{k},{v})")
