s=input()
dict={}
for i in range(0,len(s)):
    if s[i] in dict:
        dict[s[i]]+=1
    else:
        dict[s[i]]=1
lst=sorted(dict.items(),key=lambda x:(-x[1],x[0]))
print(lst[0][0],lst[0][1])