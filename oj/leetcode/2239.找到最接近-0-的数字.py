#
# @lc app=leetcode.cn id=2239 lang=python3
#
# [2239] 找到最接近 0 的数字
#

# @lc code=start
class Solution:
    def findClosestNumber(self, nums: List[int]) -> int:
        zero_neighbor = nums[0]
        for num in nums[1:]:
            if abs(num) < abs(zero_neighbor):
                zero_neighbor = num
            if abs(num) == abs(zero_neighbor):
                zero_neighbor = max(num, zero_neighbor)
        return zero_neighbor
        
# @lc code=end

