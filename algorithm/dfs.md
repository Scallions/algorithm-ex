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


## refs
[OI Wiki/dfs](https://oi-wiki.org/search/dfs/)