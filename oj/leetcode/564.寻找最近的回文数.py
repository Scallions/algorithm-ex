#
# @lc app=leetcode.cn id=564 lang=python3
#
# [564] 寻找最近的回文数
#
# https://leetcode-cn.com/problems/find-the-closest-palindrome/description/
#
# algorithms
# Hard (17.93%)
# Likes:    130
# Dislikes: 0
# Total Accepted:    6.8K
# Total Submissions: 31K
# Testcase Example:  '"123"'
#
# 给定一个表示整数的字符串 n ，返回与它最近的回文整数（不包括自身）。如果不止一个，返回较小的那个。
#
# “最近的”定义为两个整数差的绝对值最小。
#
#
#
# 示例 1:
#
#
# 输入: n = "123"
# 输出: "121"
#
#
# 示例 2:
#
#
# 输入: n = "1"
# 输出: "0"
# 解释: 0 和 2是最近的回文，但我们返回最小的，也就是 0。
#
#
#
#
# 提示:
#
#
# 1 <= n.length <= 18
# n 只由数字组成
# n 不含前导 0
# n 代表在 [1, 10^18 - 1] 范围内的整数
#
#
#

# @lc code=start
class Solution:
    def nearestPalindromic(self, n: str) -> str:
        l = len(n)
        if l == 1:
            return str(int(n)-1)
        if l % 2 == 0:
            pre = int(n[:l//2])
            t = [pre-1, pre, pre+1]
            gap = -1
            res = ""
            for tt in t:
                if str(tt)+str(tt)[::-1] == n:
                    continue
                if tt == 0:
                    ttt = '9'
                elif len(str(tt)) == l//2 - 1:
                    ttt = str(tt)+'9'+str(tt)[::-1]
                elif len(str(tt)) == l//2 + 1:
                    ttt = str(tt)[:-1]+str(tt)[::-1]
                else:
                    ttt = str(tt)+str(tt)[::-1]
                gg = abs(int(ttt) - int(n))
                if gap == -1:
                    res = ttt
                    gap = gg
                elif gg < gap:
                    gap = gg
                    res = ttt
                elif gg == gap:
                    res = str(min(int(res), int(ttt)))
            return res
        else:
            pre = int(n[:l//2+1])
            t = [pre-1, pre, pre+1]
            gap = -1
            res = ""
            for tt in t:
                if str(tt)[:-1]+str(tt)[::-1] == n:
                    continue
                if len(str(tt)) == l//2:
                    ttt = str(tt)+str(tt)[::-1]
                elif len(str(tt)) == l//2 + 2:
                    ttt = str(tt)[:-1]+str(tt)[:-1][::-1]
                else:
                    ttt = str(tt)[:-1]+str(tt)[::-1]
                gg = abs(int(ttt) - int(n))
                if gap == -1:
                    res = ttt
                    gap = gg
                elif gg < gap:
                    gap = gg
                    res = ttt
                elif gg == gap:
                    res = str(min(int(res), int(ttt)))
            return res
# @lc code=end

