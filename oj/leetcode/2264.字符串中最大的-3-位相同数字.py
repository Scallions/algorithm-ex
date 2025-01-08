#
# @lc app=leetcode.cn id=2264 lang=python3
#
# [2264] 字符串中最大的 3 位相同数字
#

# @lc code=start
class Solution:
    def largestGoodInteger(self, num: str) -> str:
        last = ""
        cnt = 0
        res = ""
        for s in num:
            if res != "" and s <= res:
                last = ""
                continue
            if s == last:
                cnt += 1
                if cnt == 3:
                    res = s
                continue
            last = s
            cnt = 1
        return res*3 
# @lc code=end

