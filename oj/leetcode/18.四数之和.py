#
# @lc app=leetcode.cn id=18 lang=python3
#
# [18] 四数之和
#
# https://leetcode.cn/problems/4sum/description/
#
# algorithms
# Medium (36.86%)
# Likes:    1654
# Dislikes: 0
# Total Accepted:    478.1K
# Total Submissions: 1.3M
# Testcase Example:  '[1,0,-1,0,-2,2]\n0'
#
# 给你一个由 n 个整数组成的数组 nums ，和一个目标值 target 。请你找出并返回满足下述全部条件且不重复的四元组 [nums[a],
# nums[b], nums[c], nums[d]] （若两个四元组元素一一对应，则认为两个四元组重复）：
# 
# 
# 0 <= a, b, c, d < n
# a、b、c 和 d 互不相同
# nums[a] + nums[b] + nums[c] + nums[d] == target
# 
# 
# 你可以按 任意顺序 返回答案 。
# 
# 
# 
# 示例 1：
# 
# 
# 输入：nums = [1,0,-1,0,-2,2], target = 0
# 输出：[[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
# 
# 
# 示例 2：
# 
# 
# 输入：nums = [2,2,2,2,2], target = 8
# 输出：[[2,2,2,2]]
# 
# 
# 
# 
# 提示：
# 
# 
# 1 <= nums.length <= 200
# -10^9 <= nums[i] <= 10^9
# -10^9 <= target <= 10^9
# 
# 
#

# @lc code=start
class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        res = []
        nums = sorted(nums)
        pi = nums[0] - 1
        for i in range(len(nums)):
            if nums[i] == pi:
                continue
            else:
                pi = nums[i]
            pj = nums[i] - 1
            for j in range(i+1, len(nums)):
                if nums[j] == pj:
                    continue
                else:
                    pj = nums[j]
                rt = nums[i] + nums[j]
                l = j + 1
                r = len(nums) - 1
                while l < r:
                    t = nums[l] + nums[r]
                    if t == target - rt:
                        res.append([nums[i], nums[j], nums[l], nums[r]])
                    if t > target - rt:
                        pr = nums[r]
                        while l < r and pr == nums[r]:
                            r -= 1
                    else:
                        pl = nums[l]
                        while l < len(nums) and pl == nums[l]:
                            l += 1
        return res

# @lc code=end

