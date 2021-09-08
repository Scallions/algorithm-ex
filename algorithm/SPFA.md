SPFA 可以用来查找单源最短路径，既从一点出发到其他个点的最短路径，可以用来查找负环，但其在某些特殊情况下时间复杂度较差。

如果点过多，可换用其他的图表示方式

伪代码
```python

matrix # 邻接矩阵
dis # 距离数组 初始化为inf
vis # 是否在队列标记
queue # 队列

queue.push(s) # 放入起点
vis[s] = 1
dis[s] = 0

while queue:
    c = queue.pop()
    vis[c] = 0

    for edge in matrix[c]: # 遍历以c为起点的边
        if dis[edge['end']] > dis[edege['start']] + edge['dis'] : # 松弛 或者不存在路径 更新 end 放入队列
            dis[edge['end']] = dis[edege['start']] + edge['dis']
            if dis[edge['end']] not in queue:
                queue.push(edge['end'])

```