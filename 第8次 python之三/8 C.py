def cons(x,y):
	s = a = b = None 
	def f(n):
		if n==0:
			return x
		elif n==1:
			return y
		else:
			return "error"
	return f
# 在此处补充你的代码
s = input().split()
a,b = s[0],s[1]
pair = cons(a,b)
print(pair(int(input())))