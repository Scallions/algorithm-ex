#
# @lc app=leetcode.cn id=1281 lang=python3
#
# [1281] 整数的各位积和之差
#
# https://leetcode.cn/problems/subtract-the-product-and-sum-of-digits-of-an-integer/description/
#
# algorithms
# Easy (83.75%)
# Likes:    146
# Dislikes: 0
# Total Accepted:    94K
# Total Submissions: 112.2K
# Testcase Example:  '234'
#
# 给你一个整数 n，请你帮忙计算并返回该整数「各位数字之积」与「各位数字之和」的差。
# 
# 
# 
# 示例 1：
# 
# 输入：n = 234
# 输出：15 
# 解释：
# 各位数之积 = 2 * 3 * 4 = 24 
# 各位数之和 = 2 + 3 + 4 = 9 
# 结果 = 24 - 9 = 15
# 
# 
# 示例 2：
# 
# 输入：n = 4421
# 输出：21
# 解释： 
# 各位数之积 = 4 * 4 * 2 * 1 = 32 
# 各位数之和 = 4 + 4 + 2 + 1 = 11 
# 结果 = 32 - 11 = 21
# 
# 
# 
# 
# 提示：
# 
# 
# 1 <= n <= 10^5
# 
# 
#

# @lc code=start
class Solution:
    def subtractProductAndSum(self, n: int) -> int:
        c = 1
        s = 0
        while n:
            t = n % 10
            c *= t
            s += t
            n = n // 10
        return c - s
# @lc code=end

