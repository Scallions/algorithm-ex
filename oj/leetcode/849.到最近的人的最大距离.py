#
# @lc app=leetcode.cn id=849 lang=python3
#
# [849] 到最近的人的最大距离
#
# https://leetcode.cn/problems/maximize-distance-to-closest-person/description/
#
# algorithms
# Medium (51.09%)
# Likes:    262
# Dislikes: 0
# Total Accepted:    41.7K
# Total Submissions: 81.7K
# Testcase Example:  '[1,0,0,0,1,0,1]'
#
# 给你一个数组 seats 表示一排座位，其中 seats[i] = 1 代表有人坐在第 i 个座位上，seats[i] = 0 代表座位 i
# 上是空的（下标从 0 开始）。
# 
# 至少有一个空座位，且至少有一人已经坐在座位上。
# 
# 亚历克斯希望坐在一个能够使他与离他最近的人之间的距离达到最大化的座位上。
# 
# 返回他到离他最近的人的最大距离。
# 
# 
# 
# 示例 1：
# 
# 
# 输入：seats = [1,0,0,0,1,0,1]
# 输出：2
# 解释：
# 如果亚历克斯坐在第二个空位（seats[2]）上，他到离他最近的人的距离为 2 。
# 如果亚历克斯坐在其它任何一个空位上，他到离他最近的人的距离为 1 。
# 因此，他到离他最近的人的最大距离是 2 。 
# 
# 
# 示例 2：
# 
# 
# 输入：seats = [1,0,0,0]
# 输出：3
# 解释：
# 如果亚历克斯坐在最后一个座位上，他离最近的人有 3 个座位远。
# 这是可能的最大距离，所以答案是 3 。
# 
# 
# 示例 3：
# 
# 
# 输入：seats = [0,1]
# 输出：1
# 
# 
# 
# 
# 提示：
# 
# 
# 2 
# seats[i] 为 0 或 1
# 至少有一个 空座位
# 至少有一个 座位上有人
# 
# 
#

# @lc code=start
class Solution:
    def maxDistToClosest(self, seats: List[int]) -> int:
        ld = [0 for _ in seats]
        ll = len(seats)
        l = -ll
        for i in range(ll):
            if seats[i] == 1:
                l = i
                ld[i] = 0
            else:
                ld[i] = i - l
        r = ll*2
        mi = ll
        md = 0
        for i in range(ll):
            j = ll - i - 1
            if seats[j] == 1:
                r = j
            else:
                d = r - j
                d = min(d, ld[j])
                if d > md:
                    mi = j
                    md = d
        return md

# @lc code=end

# 官方双指针

class Solution:
    def maxDistToClosest(self, seats: List[int]) -> int:
        res, l = 0, 0
        while l < len(seats) and seats[l] == 0:
            l += 1
        res = max(res, l)
        while l < len(seats):
            r = l + 1
            while r < len(seats) and seats[r] == 0:
                r += 1
            if r == len(seats):
                res = max(res, r - l - 1)
            else:
                res = max(res, (r - l) // 2)
            l = r
        return res
