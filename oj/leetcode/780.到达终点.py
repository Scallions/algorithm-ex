#
# @lc app=leetcode.cn id=780 lang=python3
#
# [780] 到达终点
#
# https://leetcode-cn.com/problems/reaching-points/description/
#
# algorithms
# Hard (28.69%)
# Likes:    228
# Dislikes: 0
# Total Accepted:    20.7K
# Total Submissions: 55.4K
# Testcase Example:  '1\n1\n3\n5'
#
# 给定四个整数 sx , sy ，tx 和 ty，如果通过一系列的转换可以从起点 (sx, sy) 到达终点 (tx, ty)，则返回 true，否则返回
# false。
#
# 从点 (x, y) 可以转换到 (x, x+y)  或者 (x+y, y)。
#
#
#
# 示例 1:
#
#
# 输入: sx = 1, sy = 1, tx = 3, ty = 5
# 输出: true
# 解释:
# 可以通过以下一系列转换从起点转换到终点：
# (1, 1) -> (1, 2)
# (1, 2) -> (3, 2)
# (3, 2) -> (3, 5)
#
#
# 示例 2:
#
#
# 输入: sx = 1, sy = 1, tx = 2, ty = 2
# 输出: false
#
#
# 示例 3:
#
#
# 输入: sx = 1, sy = 1, tx = 1, ty = 1
# 输出: true
#
#
#
#
# 提示:
#
#
# 1 <= sx, sy, tx, ty <= 10^9
#
#
#

# @lc code=start
class Solution:
    def reachingPoints(self, sx: int, sy: int, tx: int, ty: int) -> bool:
        while tx > sx or ty > sy:
            if tx > ty:
                tx = tx - max((tx-sx)//ty,1)*ty
            elif ty > tx:
                ty = ty - max((ty-sy)//tx,1)*tx
            # print(tx, ty)
            if tx == ty:
                break
        return tx == sx and ty == sy

# @lc code=end

