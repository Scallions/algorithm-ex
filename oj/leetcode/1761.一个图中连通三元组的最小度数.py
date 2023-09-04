#
# @lc app=leetcode.cn id=1761 lang=python3
#
# [1761] 一个图中连通三元组的最小度数
#
# https://leetcode.cn/problems/minimum-degree-of-a-connected-trio-in-a-graph/description/
#
# algorithms
# Hard (55.31%)
# Likes:    87
# Dislikes: 0
# Total Accepted:    14.6K
# Total Submissions: 26.4K
# Testcase Example:  '6\n[[1,2],[1,3],[3,2],[4,1],[5,2],[3,6]]'
#
# 给你一个无向图，整数 n 表示图中节点的数目，edges 数组表示图中的边，其中 edges[i] = [ui, vi] ，表示 ui 和 vi
# 之间有一条无向边。
# 
# 一个 连通三元组 指的是 三个 节点组成的集合且这三个点之间 两两 有边。
# 
# 连通三元组的度数 是所有满足此条件的边的数目：一个顶点在这个三元组内，而另一个顶点不在这个三元组内。
# 
# 请你返回所有连通三元组中度数的 最小值 ，如果图中没有连通三元组，那么返回 -1 。
# 
# 
# 
# 示例 1：
# 
# 
# 输入：n = 6, edges = [[1,2],[1,3],[3,2],[4,1],[5,2],[3,6]]
# 输出：3
# 解释：只有一个三元组 [1,2,3] 。构成度数的边在上图中已被加粗。
# 
# 
# 示例 2：
# 
# 
# 输入：n = 7, edges = [[1,3],[4,1],[4,3],[2,5],[5,6],[6,7],[7,5],[2,6]]
# 输出：0
# 解释：有 3 个三元组：
# 1) [1,4,3]，度数为 0 。
# 2) [2,5,6]，度数为 2 。
# 3) [5,6,7]，度数为 2 。
# 
# 
# 
# 
# 提示：
# 
# 
# 2 
# edges[i].length == 2
# 1 
# 1 i, vi 
# ui != vi
# 图中没有重复的边。
# 
# 
#

from collections import defaultdict

# @lc code=start
class Solution:
    def minTrioDegree(self, n: int, edges: List[List[int]]) -> int:
        cnt = defaultdict(set)
        for edge in edges:
            s = edge[0]
            e = edge[1]
            cnt[s].add(e)
            cnt[e].add(s)
        
        res = [(k, len(v)) for k, v in cnt.items() if len(v) >= 2]
        res = sorted(res, key=lambda x: x[1])
        vis = set()
        if not res:
            return -1
        r = 3*(n-3)
        flag = False
        for k, l in res:
            if l-2>=r:
                continue
            ss = list(cnt[k])
            vis.add(k)
            for i in range(l):
                s = ss[i]
                if s in vis:
                    continue
                for j in range(i+1, l):
                    e = ss[j]
                    if e in vis:
                        continueg
                    if not s in cnt[e]:
                        continue
                    flag = True
                    c = len(cnt[s]) + len(cnt[e]) + len(cnt[k]) - 6
                    r = min(r, c)
        return r if flag else -1


# @lc code=end

