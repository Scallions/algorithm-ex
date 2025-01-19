#
# @lc app=leetcode.cn id=2266 lang=python3
#
# [2266] 统计打字方案数
#

# @lc code=start
class Solution:
    def countTexts(self, pressedKeys: str) -> int:
        """
        懒得写dp了，实时缓存的速度
        """
        from functools import lru_cache

        @lru_cache
        def ccnt(n, k):
            if n < 0:
                return 0
            if n == 1 or n == 0:
                return 1
            if k == 3:
                return ccnt(n-1,k) + ccnt(n-2,k) + ccnt(n-3, k)
            if k == 4:
                return ccnt(n-1,k) + ccnt(n-2,k) + ccnt(n-3, k) + ccnt(n-4, k)
        l = ""
        res = 1
        cnt = 0
        for c in pressedKeys+"0":
            if l != c:
                res *= ccnt(cnt, 4 if l == '7' or l == '9' else 3)
                res %= (10**9+7)
                l = c
                cnt = 0
            cnt += 1
        return res
 
# @lc code=end

