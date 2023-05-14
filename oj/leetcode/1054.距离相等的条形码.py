from typing import List
from collections import defaultdict

#
# @lc app=leetcode.cn id=1054 lang=python3
#
# [1054] 距离相等的条形码
#

# @lc code=start
class Solution:
    def rearrangeBarcodes(self, barcodes: List[int]) -> List[int]:
        counts = defaultdict(int)
        max_cnt = 0
        for b in barcodes:
            counts[b] += 1
            max_cnt = max(max_cnt, counts[b])
        odd_idx = 1
        event_idx = 0
        half_len = len(barcodes) // 2
        res = [0] * len(barcodes)
        for b, count in counts.items():
            while count > 0 and count <= half_len and odd_idx < len(barcodes):
                res[odd_idx] = b
                odd_idx += 2
                count -= 1
            while count > 0:
                res[event_idx] = b
                event_idx += 2
                count -= 1
        return res
# @lc code=end


Solution().rearrangeBarcodes([1,1,3,2,2,2,3])