class Student:

    def __init__(self, name, score):
        self.name = name
        self.score = score

    def __gt__(self, other):
        if isinstance(other, int):
            return self.score > other
        else:
            return self.score > other.score


s1_data = input().split()
s2_data = input().split()
compare_num = int(input().strip())

s1 = Student(s1_data[0], int(s1_data[1]))
s2 = Student(s2_data[0], int(s2_data[1]))

# 创建字典
grade_dict = {s1: "A", s2: "B"}

print(grade_dict[s1])
print(s1 > s2)
print(s1 > compare_num)
