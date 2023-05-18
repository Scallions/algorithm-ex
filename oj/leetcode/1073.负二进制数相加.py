#
# @lc app=leetcode.cn id=1073 lang=python3
#
# [1073] 负二进制数相加
#
# https://leetcode.cn/problems/adding-two-negabinary-numbers/description/
#
# algorithms
# Medium (41.45%)
# Likes:    117
# Dislikes: 0
# Total Accepted:    14.4K
# Total Submissions: 34.9K
# Testcase Example:  '[1,1,1,1,1]\n[1,0,1]'
#
# 给出基数为 -2 的两个数 arr1 和 arr2，返回两数相加的结果。
# 
# 数字以 数组形式 给出：数组由若干 0 和 1 组成，按最高有效位到最低有效位的顺序排列。例如，arr = [1,1,0,1] 表示数字 (-2)^3 +
# (-2)^2 + (-2)^0 = -3。数组形式 中的数字 arr 也同样不含前导零：即 arr == [0] 或 arr[0] == 1。
# 
# 返回相同表示形式的 arr1 和 arr2 相加的结果。两数的表示形式为：不含前导零、由若干 0 和 1 组成的数组。
# 
# 
# 
# 示例 1：
# 
# 
# 输入：arr1 = [1,1,1,1,1], arr2 = [1,0,1]
# 输出：[1,0,0,0,0]
# 解释：arr1 表示 11，arr2 表示 5，输出表示 16 。
# 
# 
# 
# 
# 示例 2：
# 
# 
# 输入：arr1 = [0], arr2 = [0]
# 输出：[0]
# 
# 
# 示例 3：
# 
# 
# 输入：arr1 = [0], arr2 = [1]
# 输出：[1]
# 
# 
# 
# 
# 提示：
# 
# 
# 
# 1 <= arr1.length, arr2.length <= 1000
# arr1[i] 和 arr2[i] 都是 0 或 1
# arr1 和 arr2 都没有前导0
# 
# 
#

# @lc code=start
class Solution:
    def addNegabinary(self, arr1: List[int], arr2: List[int]) -> List[int]:
        arr1.reverse()
        arr2.reverse()
        res = []
        p = 0
        l = max(len(arr1), len(arr2))
        i = 0
        while i < l or p != 0:
            n1 = arr1[i] if i < len(arr1) else 0
            n2 = arr2[i] if i < len(arr2) else 0
            t = n1 + n2 + p
            if t < 0:
                t += 2
                p = 1
            elif t >= 2:
                t -= 2
                p = -1
            else:
                p = 0
            res.append(t)
            i += 1
        while res[-1] == 0 and len(res) > 1:
            res.pop()
        res.reverse()
        return res
        

# @lc code=end

