#
# @lc app=leetcode.cn id=1079 lang=python3
#
# [1079] 活字印刷
#
# https://leetcode.cn/problems/letter-tile-possibilities/description/
#
# algorithms
# Medium (78.65%)
# Likes:    242
# Dislikes: 0
# Total Accepted:    30.2K
# Total Submissions: 38.4K
# Testcase Example:  '"AAB"'
#
# 你有一套活字字模 tiles，其中每个字模上都刻有一个字母 tiles[i]。返回你可以印出的非空字母序列的数目。
# 
# 注意：本题中，每个活字字模只能使用一次。
# 
# 
# 
# 示例 1：
# 
# 
# 输入："AAB"
# 输出：8
# 解释：可能的序列为 "A", "B", "AA", "AB", "BA", "AAB", "ABA", "BAA"。
# 
# 
# 示例 2：
# 
# 
# 输入："AAABBC"
# 输出：188
# 
# 
# 示例 3：
# 
# 
# 输入："V"
# 输出：1
# 
# 
# 
# 提示：
# 
# 
# 1 <= tiles.length <= 7
# tiles 由大写英文字母组成
# 
# 
#

# @lc code=start
class Solution:
    def numTilePossibilities(self, tiles: str) -> int:
        cnt = Counter(tiles)
        tile = set(tiles)

        def dfs(i):
            if i == 0:
                return 1
            res = 1
            for t in tile:
                if cnt[t] > 0:
                    cnt[t] -= 1
                    res += dfs(i-1)
                    cnt[t] += 1
            return res
        return dfs(len(tiles)) - 1
# @lc code=end

