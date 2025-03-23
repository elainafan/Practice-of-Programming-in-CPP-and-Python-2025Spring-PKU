x=input()
l=len(x)
res_1=x.swapcase()
res_2=res_1[::-1]
res_3=[]
for i in range(0,l):
    if res_2[i]=='X':
        res_3.append('A')
    elif res_2[i]=='Y':
        res_3.append('B')
    elif res_2[i]=='Z':
        res_3.append('C')
    elif res_2[i]=='x':
        res_3.append('a')
    elif res_2[i]=='y':
        res_3.append('b')
    elif res_2[i]=='z':
        res_3.append('c')
    else:
        t=ord(res_2[i])
        t+=3
        res_3.append(chr(t)) 
for i in range(0,l):
    print(res_3[i],end='')