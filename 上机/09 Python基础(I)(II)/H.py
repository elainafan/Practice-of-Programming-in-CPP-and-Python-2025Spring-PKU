lst = [
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O',
    'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'
]
cnt = [0] * 26
for i in range(1, 5):
    k = input()
    for j in range(0, len(k)):
        if ord(k[j]) - ord('A') >= 0 and ord(k[j]) - ord('A') <= 25:
            cnt[ord(k[j]) - ord('A')] += 1
ans = 0
for i in range(0, 26):
    ans = max(ans, cnt[i])
for i in range(0, ans):
    for j in range(0, 26):
        if cnt[j] < ans:
            print(' ', end=' ')
        else:
            print('*', end=' ')
    print()
    ans -= 1
for i in range(0, 26):
    print(lst[i], end=' ')
