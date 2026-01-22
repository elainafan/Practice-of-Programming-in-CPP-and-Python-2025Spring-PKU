ma = -999999
while True:
    try:
        line = input()
        if not line:
            break
        nums = [int(x) for x in line.split()]
        for num in nums:
            if num > ma:
                ma = num
    except:
        break
print(ma)
