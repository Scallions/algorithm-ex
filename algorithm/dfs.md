# dfs
又叫深度优先遍历，经常用来暴力搜索，使用递归来实现，可以结合回溯实现更多功能。常用于图搜索


```python
def dfs(cur):
    check_ans()
    nexts = get_nexts(cur)
    for next in nexts: # 如果有多个
        # change_state() # 回溯
        dfs(next)
        # recovery_state()
```

对于遍历，不一定需要直接构建dfs来返回结果，可以使用dfs来返回中间结果，同时在dfs中根据要求构建答案。例如[二叉树的坡度](https://leetcode-cn.com/problems/binary-tree-tilt/submissions/)，定义的dfs为求树的所有节点和，而不是直接求坡度，[二叉树的直径](https://leetcode-cn.com/problems/diameter-of-binary-tree/)的dfs为求树的深度，而不是直径。

## refs
[OI Wiki/dfs](https://oi-wiki.org/search/dfs/)