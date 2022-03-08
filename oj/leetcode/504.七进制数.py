#
# @lc app=leetcode.cn id=504 lang=python3
#
# [504] 七进制数
#
# https://leetcode-cn.com/problems/base-7/description/
#
# algorithms
# Easy (50.43%)
# Likes:    129
# Dislikes: 0
# Total Accepted:    40.5K
# Total Submissions: 79.4K
# Testcase Example:  '100'
#
# 给定一个整数 num，将其转化为 7 进制，并以字符串形式输出。
#
#
#
# 示例 1:
#
#
# 输入: num = 100
# 输出: "202"
#
#
# 示例 2:
#
#
# 输入: num = -7
# 输出: "-10"
#
#
#
#
# 提示：
#
#
# -10^7 <= num <= 10^7
#
#
#

# @lc code=start
class Solution:
    def convertToBase7(self, num: int) -> str:
        """将num转为7进制
        划分：
        1. num%7 == 0
        2. num > 0
        3. |num| > 7

        Args:
            num (int): 需要转换的数

        Returns:
            str: 7进制的字符串
        """
        flag = True
        if num < 0:
            flag = False
            num = -num
        res = ""
        while num != 0:
            res = str(num%7) + res
            num = num // 7
        if len(res) == 0:
            res = "0"
        if not flag:
            res = "-"+res
        return res 
# @lc code=end

