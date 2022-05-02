#
# @lc app=leetcode.cn id=417 lang=python3
#
# [417] 太平洋大西洋水流问题
#
# https://leetcode-cn.com/problems/pacific-atlantic-water-flow/description/
#
# algorithms
# Medium (48.00%)
# Likes:    472
# Dislikes: 0
# Total Accepted:    61.2K
# Total Submissions: 111.7K
# Testcase Example:  '[[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]'
#
# 有一个 m × n 的矩形岛屿，与 太平洋 和 大西洋 相邻。 “太平洋” 处于大陆的左边界和上边界，而 “大西洋” 处于大陆的右边界和下边界。
#
# 这个岛被分割成一个由若干方形单元格组成的网格。给定一个 m x n 的整数矩阵 heights ， heights[r][c] 表示坐标 (r, c)
# 上单元格 高于海平面的高度 。
#
# 岛上雨水较多，如果相邻单元格的高度 小于或等于 当前单元格的高度，雨水可以直接向北、南、东、西流向相邻单元格。水可以从海洋附近的任何单元格流入海洋。
#
# 返回网格坐标 result 的 2D 列表 ，其中 result[i] = [ri, ci] 表示雨水从单元格 (ri, ci) 流动
# 既可流向太平洋也可流向大西洋 。
#
#
#
# 示例 1：
#
#
#
#
# 输入: heights = [[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]
# 输出: [[0,4],[1,3],[1,4],[2,2],[3,0],[3,1],[4,0]]
#
#
# 示例 2：
#
#
# 输入: heights = [[2,1],[1,2]]
# 输出: [[0,0],[0,1],[1,0],[1,1]]
#
#
#
#
# 提示：
#
#
# m == heights.length
# n == heights[r].length
# 1 <= m, n <= 200
# 0 <= heights[r][c] <= 10^5
#
#
#

# @lc code=start
class Solution:
    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        n = len(heights)
        m = len(heights[0])
        stats = [[0 for _ in range(m)] for _ in range(n)]

        # 初始化临海点
        que = []
        que.append([0,m-1])
        stats[0][m-1] |= 3
        que.append([n-1,0])
        stats[n-1][0] |= 3
        for i in range(m-1):
            que.append([0,i])
            stats[0][i] |= 1
            que.append([n-1,i+1])
            stats[n-1][i+1] |= 2
        for i in range(n-1):
            que.append([i,0])
            stats[i][0] |= 1
            que.append([i+1,m-1])
            stats[i+1][m-1] |= 2
        # print(stats)
        # 广遍
        while len(que) != 0:
            l = len(que)
            nq = []
            for i in range(l):
                px = que[i][0]
                py = que[i][1]
                for dx, dy in [(-1,0),(1,0),(0,-1),(0,1)]:
                    x = px + dx
                    y = py + dy
                    if x >= 0 and x < n and y>= 0 and y < m and heights[x][y] >= heights[px][py]:
                        if stats[px][py] & 1 == 1 and stats[x][y] & 1 == 0:
                            stats[x][y] |= 1
                            nq.append([x, y])
                        if stats[px][py] & 2 == 2 and stats[x][y] & 2 == 0:
                            stats[x][y] |= 2
                            nq.append([x, y])
            que = nq
        # print(stats)
        res = []
        for i in range(n):
            for j in range(m):
                if stats[i][j] & 3 == 3:
                    res.append([i, j])
        return res
# @lc code=end

