exit = None
class TaggedList:  #元素带标签的列表
    def __init__(self,value,tags):
        self.values=value
        self.tag_index={tag:idx for idx,tag in enumerate(tags)}
    def __len__(self):
        return len(self.values)
    def __contains__(self,item):
        return item in self.values
    def __getitem__(self,key):
        if isinstance(key,int):
            return self.values[key]
        return self.values[self.tag_index[key]]
    def __setitem__(self,key,value):
        if isinstance(key,int):
            self.values[key]=value
        else:
            self.values[self.tag_index[key]]=value
    def __str__(self):
        return ','.join(f"{tag}:{val}" for tag,val in zip(self.tag_index.keys(),self.values))+','
# 在此处补充你的代码
a = TaggedList([70,80,90,100],["语文","数学","英语","物理"])
print(len(a),78 in a, 80 in a) #>>4 False True
print(str(a)) #>>语文:70,数学:80,英语:90,物理:100,
print(a[0],a['数学']) #>>70 80   标签也可以作为下标访问元素
a[1] = a['物理'] = 85
print(a) #>>语文:70,数学:85,英语:90,物理:85,