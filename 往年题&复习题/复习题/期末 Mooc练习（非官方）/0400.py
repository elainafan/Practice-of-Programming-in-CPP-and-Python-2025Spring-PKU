n = int(input())
ans = 0
aver = 0
for i in range(1, n + 1):
    x = int(input())
    ans += x
aver = ans / n
print(ans, end=' ')
print(f"{aver:.5f}")
