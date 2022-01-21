'''
@Author       : Scallions
@Date         : 2020-03-20 12:46:50
LastEditors  : Scallions
LastEditTime : 2022-01-21 14:22:37
FilePath     : /algorithm-ex/structure/array/array.py
@Description  : 
'''

# 初始化
arr1 = [1,2,3]
arr2 = list()
# 增删改查
arr1.append(4)
print(arr1)
del arr1[0]
print(arr1)
arr1[0] = 1
print(arr1)
print(arr1[1])

# 遍历
# 1. for each
for i in arr1:
    print(i)
# 2. enumerate
for i, el in enumerate(arr1):
    print(i, el)
    