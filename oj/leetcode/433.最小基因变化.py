#
# @lc app=leetcode.cn id=433 lang=python3
#
# [433] 最小基因变化
#
# https://leetcode-cn.com/problems/minimum-genetic-mutation/description/
#
# algorithms
# Medium (53.21%)
# Likes:    151
# Dislikes: 0
# Total Accepted:    26.2K
# Total Submissions: 48.2K
# Testcase Example:  '"AACCGGTT"\n"AACCGGTA"\n["AACCGGTA"]'
#
# 基因序列可以表示为一条由 8 个字符组成的字符串，其中每个字符都是 'A'、'C'、'G' 和 'T' 之一。
#
# 假设我们需要调查从基因序列 start 变为 end 所发生的基因变化。一次基因变化就意味着这个基因序列中的一个字符发生了变化。
#
#
# 例如，"AACCGGTT" --> "AACCGGTA" 就是一次基因变化。
#
#
# 另有一个基因库 bank 记录了所有有效的基因变化，只有基因库中的基因才是有效的基因序列。
#
# 给你两个基因序列 start 和 end ，以及一个基因库 bank ，请你找出并返回能够使 start 变化为 end
# 所需的最少变化次数。如果无法完成此基因变化，返回 -1 。
#
# 注意：起始基因序列 start 默认是有效的，但是它并不一定会出现在基因库中。
#
#
#
# 示例 1：
#
#
# 输入：start = "AACCGGTT", end = "AACCGGTA", bank = ["AACCGGTA"]
# 输出：1
#
#
# 示例 2：
#
#
# 输入：start = "AACCGGTT", end = "AAACGGTA", bank =
# ["AACCGGTA","AACCGCTA","AAACGGTA"]
# 输出：2
#
#
# 示例 3：
#
#
# 输入：start = "AAAAACCC", end = "AACCCCCC", bank =
# ["AAAACCCC","AAACCCCC","AACCCCCC"]
# 输出：3
#
#
#
#
# 提示：
#
#
# start.length == 8
# end.length == 8
# 0 <= bank.length <= 10
# bank[i].length == 8
# start、end 和 bank[i] 仅由字符 ['A', 'C', 'G', 'T'] 组成
#
#
#
from typing import List

# @lc code=start
class Solution:
    def minMutation(self, start: str, end: str, bank: List[str]) -> int:
        # bps
        l = 1
        q = [start]
        ll = len(bank) + 1
        vis = set()
        vis.add(start)
        bs = set(bank)
        # bs.add(end)
        while l < ll and len(q) != 0:
            lq = len(q)
            qn = []
            for qq in q:
                for b in bs:
                    c = 0
                    for i in range(8):
                        if qq[i] != b[i]:
                            c += 1
                    if c == 1 and b not in vis:
                        if b == end:
                            return l
                        qn.append(b)
                        vis.append(b)
            q = qn
            l += 1
        return -1
# @lc code=end

start = "AACCGGTT"
end = "AACCGGTA"
bank = ["AACCGGTA"]

print(Solution().minMutation(start, end, bank))