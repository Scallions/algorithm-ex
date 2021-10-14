<!--
 * @Author       : Scallions
 * @Date         : 2020-03-20 11:19:53
 * @LastEditors  : Scallions
 * @LastEditTime : 2020-03-20 11:19:53
 * @FilePath     : /algorithm-ex/structure/graph/graph.md
 * @Description  : 
 -->

# 图

图与网络是运筹学（Operations Research）中的一个经典和重要的分支，所研究的 问题涉及经济管理、工业工程、交通运输、计算机科学与信息技术、通讯与网络技术等 诸多领域。下面将要讨论的**最短路问题、最大流问题、最小费用流问题和匹配问题**等都 是图与网络的基本问题。

## 分类
- 无向图
- 有向图

## concept
- 顶点
  - 度
  - 奇顶点
  - 偶顶点
  - 出度
  - 入度
- 边
- 完全图
- 二分图
- 子图

## 表示方法
- 邻接矩阵
- 关联矩阵
- 弧表
- 邻接表
- 星形表

### 邻接矩阵
以矩阵的方式来存储，图$G=(V,A)$的邻接矩阵定义如下
$$
C = (c_{ij})\in R^{n\times n} \\
c_{ij} = 
$$

重边

### 链式前向星

```c++
struct Edge{
  int to;
  int next;
  int weight;
}

vector<Edge> edges(n_edge);
vector<int> head(n_node, -1);

void add(int u, int v, int cost){
  // 设置第cnt条边
  edges[++cnt].to = v;
  edges[cnt].weight = cost;
  edges[cnt].next = head[u];
  // 更新第一条边编号
  head[u] = cnt;
}

// 遍历起点为u的边
for(int k=head[u]; k!=1; k=edges[k].next){
  
}
```

## 参考资料
《第05章 图与网络》. 收入 数学建模.

