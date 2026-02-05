n = int(input())
di = [
    0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I',
    'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X',
    'Y', 'Z'
]
dict = {
    '0': 0,
    '1': 1,
    '2': 2,
    '3': 3,
    '4': 4,
    '5': 5,
    '6': 6,
    '7': 7,
    '8': 8,
    '9': 9,
    'A': 10,
    'B': 11,
    'C': 12,
    'D': 13,
    'E': 14,
    'F': 15,
    'G': 16,
    'H': 17,
    'I': 18,
    'J': 19,
    'K': 20,
    'L': 21,
    'M': 22,
    'N': 23,
    'O': 24,
    'P': 25,
    'Q': 26,
    'R': 27,
    'S': 28,
    'T': 29,
    'U': 30,
    'V': 31,
    'W': 32,
    'X': 33,
    'Y': 34,
    'Z': 35
}
for i in range(0, n):
    lst = input().split(',')
    p = int(lst[0])
    x = lst[1]
    q = int(lst[2])
    num = 0
    k = 1
    l = []
    t = x[::-1]
    for j in range(0, len(t)):
        num += k * dict[t[j]]
        k *= p
    if num == 0:
        print('0')
        continue
    while num > 0:
        temp = num % q
        l.append(di[temp])
        num //= q
    res = l[::-1]
    for j in res:
        print(j, end='')
    print()
