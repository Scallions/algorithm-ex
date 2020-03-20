
# 创建set

set1 = {1,2,3}
set2 = set((1,2,3,4))

# 添加
set1.add(4)
set1.update(5)

# 删除
set1.remove(4)
set1.discard(5)

# 交集
set1 & set2

# 并集
set1 | set2 

# 差集
set1 - set2 

# 
set1 ^ set2
