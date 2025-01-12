#
# @lc app=leetcode.cn id=2275 lang=python3
#
# [2275] 按位与结果大于零的最长组合
#

# @lc code=start
class Solution:
    def largestCombination(self, candidates: List[int]) -> int:
        bcnt = [0] * 25
        for c in candidates:
            for j in range(len(bcnt)):
                if c & (1 << j):
                    bcnt[j] += 1
        return max(bcnt)

    def largestCombination2(self, candidates: List[int]) -> int:
        """
        优化点在于根据最大的数选择长度，以及按位来循环，减少空间使用
        """
        ans = 0
        for i in range(max(candidates).bit_length()):
            mask = 1 << i
            res = 0
            for c in candidates:
                if c & mask != 0:
                    res += 1
            ans = max(ans, res)
        return ans  

# @lc code=end

