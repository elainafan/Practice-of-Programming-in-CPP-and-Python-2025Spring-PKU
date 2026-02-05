dict = {
    "pop": 1,
    "no": 2,
    "zip": 3,
    "zotz": 4,
    "tzec": 5,
    "xul": 6,
    "yoxkin": 7,
    "mol": 8,
    "chen": 9,
    "yax": 10,
    "zac": 11,
    "ceh": 12,
    "mac": 13,
    "kankin": 14,
    "muan": 15,
    "pax": 16,
    "koyab": 17,
    "cumhu": 18,
    "uayet": 19
}
day = [
    0, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20,
    5
]
reday = [
    0, "imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", "lamat",
    "muluk", "ok", "chuen", "eb", "ben", "ix", "mem", "cib", "caban", "eznab",
    "canac", "ahau"
]
n = int(input())
print(n)
for i in range(0, n):
    tem = 0
    lst = input().split()
    x = lst[0]
    l = len(x)
    d = int(x[:(l - 1)])
    k = lst[1]
    z = lst[2]
    y = int(z)
    m = dict[k]
    tem += y * 365
    for j in range(1, m):
        tem += day[j]
    tem += d + 1
    if tem % 260 == 0:
        ry = tem // 260 - 1
        tem = 260
    else:
        ry = tem // 260
        tem %= 260
    temp = tem % 13
    if temp == 0:
        temp = 13
    rd = temp
    tt = tem % 20
    if tt == 0:
        tt = 20
    rm = reday[tt]
    print(rd, rm, ry)
