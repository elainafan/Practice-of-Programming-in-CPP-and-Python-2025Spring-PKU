def hanoi_generator(n, source, target, auxiliary):
    if n == 1:
        yield (source, target)  # 直接移动盘子
    else:
        yield from hanoi_generator(n - 1, source, auxiliary, target)
        yield (source, target)
        yield from hanoi_generator(n - 1, auxiliary, target, source)


n, k = map(int, input().split())
for move in hanoi_generator(n, 'A', 'C', 'B'):
    print(f"{move[0]}->{move[1]}")
    k -= 1
    if k == 0:
        break
