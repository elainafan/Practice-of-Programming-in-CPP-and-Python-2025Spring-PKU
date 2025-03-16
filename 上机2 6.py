x=int(input())
if x%4==0 and x%100!=0:
    print('Y')
elif x%4==0 and x%400==0:
    print('Y')
else:
    print('N')
