#
# @lc app=leetcode.cn id=2270 lang=python3
#
# [2270] 分割数组的方案数
#

# @lc code=start
class Solution:
    def waysToSplitArray(self, nums: List[int]) -> int:
        s = sum(nums)
        cnt = 0
        t = 0
        for i in range(len(nums) - 1):
            t += nums[i]
            if 2 * t >= s:
                cnt += 1
        return cnt

    def waysToSplitArray2(self, nums: List[int]) -> int:
        # 函数式
        t = (sum(nums) + 1) // 2
        return sum(s >= t for s in accumulate(nums[:-1]))

# @lc code=end

