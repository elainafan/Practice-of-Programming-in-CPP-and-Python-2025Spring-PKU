lst = input().split()
n = int(lst[0])
ans = [
    0,
]
if n == 1:
    print("Jolly")
    exit()
for i in range(1, n):
    ans.append(abs(int(lst[i]) - int(lst[i + 1])))
ans.sort()
for i in range(1, n):
    if ans[i] != i:
        print("Not jolly")
        exit()
print("Jolly")
