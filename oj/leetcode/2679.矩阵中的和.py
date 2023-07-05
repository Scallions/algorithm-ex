#
# @lc app=leetcode.cn id=2679 lang=python3
#
# [2679] 矩阵中的和
#
# https://leetcode.cn/problems/sum-in-a-matrix/description/
#
# algorithms
# Medium (78.89%)
# Likes:    50
# Dislikes: 0
# Total Accepted:    19.8K
# Total Submissions: 25.1K
# Testcase Example:  '[[7,2,1],[6,4,2],[6,5,3],[3,2,1]]'
#
# 给你一个下标从 0 开始的二维整数数组 nums 。一开始你的分数为 0 。你需要执行以下操作直到矩阵变为空：
# 
# 
# 矩阵中每一行选取最大的一个数，并删除它。如果一行中有多个最大的数，选择任意一个并删除。
# 在步骤 1 删除的所有数字中找到最大的一个数字，将它添加到你的 分数 中。
# 
# 
# 请你返回最后的 分数 。
# 
# 
# 
# 示例 1：
# 
# 
# 输入：nums = [[7,2,1],[6,4,2],[6,5,3],[3,2,1]]
# 输出：15
# 解释：第一步操作中，我们删除 7 ，6 ，6 和 3 ，将分数增加 7 。下一步操作中，删除 2 ，4 ，5 和 2 ，将分数增加 5 。最后删除 1
# ，2 ，3 和 1 ，将分数增加 3 。所以总得分为 7 + 5 + 3 = 15 。
# 
# 
# 示例 2：
# 
# 
# 输入：nums = [[1]]
# 输出：1
# 解释：我们删除 1 并将分数增加 1 ，所以返回 1 。
# 
# 
# 
# 提示：
# 
# 
# 1 <= nums.length <= 300
# 1 <= nums[i].length <= 500
# 0 <= nums[i][j] <= 10^3
# 
# 
#

# @lc code=start
class Solution:
    def matrixSum(self, nums: List[List[int]]) -> int:
        for i in range(len(nums)):
            nums[i] = sorted(nums[i])
        res = 0
        for j in range(len(nums[0])):
            r = 0
            for i in range(len(nums)):
                r = max(nums[i][j], r)
            res += r
        return res
# @lc code=end

