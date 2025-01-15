#
# @lc app=leetcode.cn id=3066 lang=python3
#
# [3066] 超过阈值的最少操作数 II
#

# @lc code=start
class Solution:
    def minOperations(self, nums: List[int], k: int) -> int:
        import heapq
        heapq.heapify(nums)
        cnt = 0
        while nums[0] < k:
            a = heapq.heappop(nums)
            b = heapq.heappop(nums)
            t = a * 2 + b
            heapq.heappush(nums, t)
            cnt += 1
        return cnt


# @lc code=end

