#
# @lc app=leetcode.cn id=2337 lang=python3
#
# [2337] 移动片段得到字符串
#
# https://leetcode.cn/problems/move-pieces-to-obtain-a-string/description/
#
# algorithms
# Medium (47.29%)
# Likes:    126
# Dislikes: 0
# Total Accepted:    24.5K
# Total Submissions: 51.9K
# Testcase Example:  '"_L__R__R_"\n"L______RR"'
#
# 给你两个字符串 start 和 target ，长度均为 n 。每个字符串 仅 由字符 'L'、'R' 和 '_' 组成，其中：
# 
# 
# 字符 'L' 和 'R' 表示片段，其中片段 'L' 只有在其左侧直接存在一个 空位 时才能向 左 移动，而片段 'R' 只有在其右侧直接存在一个 空位
# 时才能向 右 移动。
# 字符 '_' 表示可以被 任意 'L' 或 'R' 片段占据的空位。
# 
# 
# 如果在移动字符串 start 中的片段任意次之后可以得到字符串 target ，返回 true ；否则，返回 false 。
# 
# 
# 
# 示例 1：
# 
# 
# 输入：start = "_L__R__R_", target = "L______RR"
# 输出：true
# 解释：可以从字符串 start 获得 target ，需要进行下面的移动：
# - 将第一个片段向左移动一步，字符串现在变为 "L___R__R_" 。
# - 将最后一个片段向右移动一步，字符串现在变为 "L___R___R" 。
# - 将第二个片段向右移动三步，字符串现在变为 "L______RR" 。
# 可以从字符串 start 得到 target ，所以返回 true 。
# 
# 
# 示例 2：
# 
# 
# 输入：start = "R_L_", target = "__LR"
# 输出：false
# 解释：字符串 start 中的 'R' 片段可以向右移动一步得到 "_RL_" 。
# 但是，在这一步之后，不存在可以移动的片段，所以无法从字符串 start 得到 target 。
# 
# 
# 示例 3：
# 
# 
# 输入：start = "_R", target = "R_"
# 输出：false
# 解释：字符串 start 中的片段只能向右移动，所以无法从字符串 start 得到 target 。
# 
# 
# 
# 提示：
# 
# 
# n == start.length == target.length
# 1 <= n <= 10^5
# start 和 target 由字符 'L'、'R' 和 '_' 组成
# 
# 
#

# @lc code=start
class Solution:
    def canChange(self, start: str, target: str) -> bool:
        start += "_"
        target += "_"
        s_l = 0
        t_l = 0
        l = len(start)
        while s_l < l and t_l < l:
            while s_l < l and start[s_l] == '_':
                s_l += 1
            while t_l < l and target[t_l] == '_':
                t_l += 1
            if s_l >= l and t_l >= l:
                return True
            if s_l >= l or t_l >= l:
                return False
            if start[s_l] != target[t_l]:
                return False
            if start[s_l] == 'L' and t_l > s_l:
                return False
            if start[s_l] == 'R' and t_l < s_l:
                return False
            s_l += 1
            t_l += 1
        if s_l >= l or t_l >= l:
            return False
        return True

            
# @lc code=end 

