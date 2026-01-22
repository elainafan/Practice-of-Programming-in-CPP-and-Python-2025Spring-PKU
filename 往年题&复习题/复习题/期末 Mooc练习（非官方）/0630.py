dict = {}
ans = 0
while True:
    try:
        a = input()
        if a not in dict:
            ans += 1
            dict[a] = 1
        else:
            continue
    except EOFError:
        break
print(ans)
