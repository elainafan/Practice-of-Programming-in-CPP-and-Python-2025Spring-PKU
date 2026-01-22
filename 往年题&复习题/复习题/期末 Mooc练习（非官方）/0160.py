n = int(input())
if (n - 1921) % 10 == 0:
    print("Good year")
elif (n - 1949) % 10 == 0:
    print("Lucky year")
elif n % 4 == 0 and n % 100 != 0:
    print("Leap year")
elif n % 4 == 0 and n % 400 == 0:
    print("Leap year")
elif n < 0:
    print("Illegal year")
else:
    print("Common year")
