#
# @lc app=leetcode.cn id=3097 lang=python3
#
# [3097] 或值至少为 K 的最短子数组 II
#

# @lc code=start
class Solution:
    def minimumSubarrayLength(self, nums: List[int], k: int) -> int:
        mn = 0
        for num in nums:
            mn |= num
        if mn < k:
            return -1
        if mn == 0:
            return 1
        import math
        ll = int(math.log2(mn)) + 1
        cnt = [0] * ll
        res = len(nums)
        l = 0
        win_s = 0
        for r in range(len(nums)):
            # update win cnt
            win_s = 0
            for i in range(ll):
                if nums[r] & (1 << i):
                    cnt[i] += 1
                if cnt[i] > 0:
                    win_s += (1 << i)
            # count win_s
            if win_s < k:
                continue
            # shrink window
            while win_s >= k and l < r:
                res = min(res, r - l + 1)
                win_s = 0
                for i in range(ll):
                    if nums[l] & (1 << i):
                        cnt[i] -= 1
                    if cnt[i] > 0:
                        win_s += (1 << i)
                l += 1
            if win_s >= k:
                res = min(res, r - l + 1)
        return res

    def minimumSubarrayLength1(self, nums: List[int], k: int) -> int:
        """
        左右增长，不用记录数量更快
        """
        ans = inf
        left = bottom = right_or = 0
        for right, x in enumerate(nums):
            right_or |= x
            while left <= right and nums[left] | right_or >= k:
                ans = min(ans, right - left + 1)
                left += 1
                if bottom < left:
                    # 重新构建一个栈
                    for i in range(right - 1, left - 1, -1):
                        nums[i] |= nums[i + 1]
                    bottom = right
                    right_or = 0
        return ans if ans < inf else -1
            

# @lc code=end

