n = int(input())
ans = []
you = []
res = 0
youres = 0
for i in range(0, n):
    k = input().split()
    age = int(k[1])
    if age >= 60:
        ans.append([])
        ans[res].append(k[0])
        ans[res].append(age)
        ans[res].append(i)
        res += 1
    else:
        you.append([])
        you[youres].append(k[0])
        you[youres].append(age)
        you[youres].append(i)
        youres += 1
ans.sort(key=lambda x: (-x[1], x[2]))
you.sort(key=lambda x: x[2])
x = len(ans)
y = len(you)
for i in range(0, x):
    print(ans[i][0])
for i in range(0, y):
    print(you[i][0])
