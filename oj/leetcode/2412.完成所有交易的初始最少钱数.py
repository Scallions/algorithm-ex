#
# @lc app=leetcode.cn id=2412 lang=python3
#
# [2412] 完成所有交易的初始最少钱数
#

# @lc code=start
class Solution:
    def minimumMoney(self, transactions: List[List[int]]) -> int:
        pos = []
        neg = []
        for transaction in transactions:
            if transaction[1] - transaction[0] >= 0:
                pos.append(transaction)
            else:
                neg.append(transaction)
        mp = 0
        for transaction in pos:
            mp = max(mp, transaction[0])
        if not neg:
            return mp
        neg = sorted(neg, key=lambda x: -x[1])
        mn = 0
        for n in neg:
            mn = max(mn + n[0] - n[1], n[0])
        return max(0, mp - neg[0][1]) + mn
        


# @lc code=end

