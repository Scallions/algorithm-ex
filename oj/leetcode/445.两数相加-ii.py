#
# @lc app=leetcode.cn id=445 lang=python3
#
# [445] 两数相加 II
#
# https://leetcode.cn/problems/add-two-numbers-ii/description/
#
# algorithms
# Medium (60.96%)
# Likes:    664
# Dislikes: 0
# Total Accepted:    137.2K
# Total Submissions: 225.1K
# Testcase Example:  '[7,2,4,3]\n[5,6,4]'
#
# 给你两个 非空 链表来代表两个非负整数。数字最高位位于链表开始位置。它们的每个节点只存储一位数字。将这两数相加会返回一个新的链表。
# 
# 你可以假设除了数字 0 之外，这两个数字都不会以零开头。
# 
# 
# 
# 示例1：
# 
# 
# 
# 
# 输入：l1 = [7,2,4,3], l2 = [5,6,4]
# 输出：[7,8,0,7]
# 
# 
# 示例2：
# 
# 
# 输入：l1 = [2,4,3], l2 = [5,6,4]
# 输出：[8,0,7]
# 
# 
# 示例3：
# 
# 
# 输入：l1 = [0], l2 = [0]
# 输出：[0]
# 
# 
# 
# 
# 提示：
# 
# 
# 链表的长度范围为 [1, 100]
# 0 <= node.val <= 9
# 输入数据保证链表代表的数字无前导 0
# 
# 
# 
# 
# 进阶：如果输入链表不能翻转该如何解决？
# 
#

# @lc code=start
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        p = None
        while l1:
            n = l1.next
            l1.next = p
            p = l1
            l1 = n
        l1 = p
        p = None
        while l2:
            n = l2.next
            l2.next = p
            p = l2
            l2 = n
        l2 = p
        t = 0
        h1 = l1
        while l1.next and l2.next:
            l1.val += l2.val + t
            t = l1.val // 10
            l1.val %= 10
            l1 = l1.next
            l2 = l2.next
        l = l1.next if l1.next else l2.next
        l1.next = l
        l1.val += l2.val
        while l1:
            l1.val += t
            t = l1.val // 10
            l1.val %= 10
            l1 = l1.next
        p = None
        l1 = h1
        while l1:
            n = l1.next
            l1.next = p
            p = l1
            l1 = n
        if t != 0:
            p = ListNode(1, p)
        return p
        

        
# @lc code=end

