#
# @lc app=leetcode.cn id=553 lang=python3
#
# [553] 最优除法
#
# https://leetcode-cn.com/problems/optimal-division/description/
#
# algorithms
# Medium (60.43%)
# Likes:    124
# Dislikes: 0
# Total Accepted:    13.4K
# Total Submissions: 21.1K
# Testcase Example:  '[1000,100,10,2]'
#
# 给定一组正整数，相邻的整数之间将会进行浮点除法操作。例如， [2,3,4] -> 2 / 3 / 4 。
#
#
# 但是，你可以在任意位置添加任意数目的括号，来改变算数的优先级。你需要找出怎么添加括号，才能得到最大的结果，并且返回相应的字符串格式的表达式。你的表达式不应该含有冗余的括号。
#
# 示例：
#
#
# 输入: [1000,100,10,2]
# 输出: "1000/(100/10/2)"
# 解释:
# 1000/(100/10/2) = 1000/((100/10)/2) = 200
# 但是，以下加粗的括号 "1000/((100/10)/2)" 是冗余的，
# 因为他们并不影响操作的优先级，所以你需要返回 "1000/(100/10/2)"。
#
# 其他用例:
# 1000/(100/10)/2 = 50
# 1000/(100/(10/2)) = 50
# 1000/100/10/2 = 0.5
# 1000/100/(10/2) = 2
#
#
# 说明:
#
#
# 输入数组的长度在 [1, 10] 之间。
# 数组中每个元素的大小都在 [2, 1000] 之间。
# 每个测试用例只有一个最优除法解。
#
#
#

# @lc code=start
class Solution:
    def optimalDivision(self, nums: List[int]) -> str:
        l = len(nums)
        res = [["" for j in range(l)] for i in range(l)]
        dp = [[0 for j in range(l)] for i in range(l)]
        # 初始化长度0
        for i in range(l):
            res[i][i] = str(nums[i])
            dp[i][i] = nums[i]
        # 遍历长度
        for i in range(1,l):
            # 最i
            # 起点
            # print(f"i:{i}")
            for j in range(l-i):
                # 遍历划分 第一部分长度
                for k in range(i):
                    fz = dp[j][j+k]
                    fm = dp[j+i][j+k+1]
                    # print(f"{j}:{j+k},{j+i}:{j+k+1}")
                    dd = fz / fm
                    fzs = res[j][j+k]
                    fms = res[j+i][j+k+1]
                    fs = f"{fzs}/({fms})" if k!=i-1 else f"{fzs}/{fms}"
                    if dp[j][j+i]== 0:
                        dp[j][j+i] = dd
                        res[j][j+i] = fs
                    elif dd > dp[j][j+i]:
                        dp[j][j+i] = dd
                        res[j][j+i] = fs
                # print(dp[j][j+i])
            # 最小
            for j in range(l-i):
                # 遍历划分 第一部分长度
                for k in range(i):
                    fz = dp[j+k][j]
                    fm = dp[j+k+1][j+i]
                    # print(f"{j+k}:{j},{j+k+1}:{j+i}")
                    dd = fz / fm
                    fzs = res[j+k][j]
                    fms = res[j+k+1][j+i]
                    fs = f"{fzs}/({fms})" if k!=i-1 else f"{fzs}/{fms}"
                    if dp[j+i][j] == 0:
                        dp[j+i][j] = dd
                        res[j+i][j] = fs
                    elif dd < dp[j+i][j]:
                        dp[j+i][j] = dd
                        res[j+i][j] = fs
                # print(dp[j+i][j])
        return res[0][l-1]

# @lc code=end

# 法2 数学法，开始只想着遍历所有情况了= =没仔细分析