"""
标准库没有栈，可以用list模拟栈
"""


stack = [2]
# 入栈
stack.append(1)
print(stack)

# 出栈
stack.pop()
print(stack)

# 栈顶元素
# 注意判空
print(stack[-1])

# 清空栈
stack.clear()
print(stack)