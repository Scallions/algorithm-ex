#
# @lc app=leetcode.cn id=1305 lang=python3
#
# [1305] 两棵二叉搜索树中的所有元素
#
# https://leetcode-cn.com/problems/all-elements-in-two-binary-search-trees/description/
#
# algorithms
# Medium (74.67%)
# Likes:    138
# Dislikes: 0
# Total Accepted:    42K
# Total Submissions: 53.6K
# Testcase Example:  '[2,1,4]\r\n[1,0,3]\r'
#
# 给你 root1 和 root2 这两棵二叉搜索树。请你返回一个列表，其中包含 两棵树 中的所有整数并按 升序 排序。.
#
#
#
# 示例 1：
#
#
#
#
# 输入：root1 = [2,1,4], root2 = [1,0,3]
# 输出：[0,1,1,2,3,4]
#
#
# 示例 2：
#
#
#
#
# 输入：root1 = [1,null,8], root2 = [8,1]
# 输出：[1,1,8,8]
#
#
#
#
# 提示：
#
#
# 每棵树的节点数在 [0, 5000] 范围内
# -10^5 <= Node.val <= 10^5
#
#
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def getAllElements(self, root1: TreeNode, root2: TreeNode) -> List[int]:
        q1 = []
        q2 = []

        while root1:
            q1.append(root1)
            root1 = root1.left

        while root2:
            q2.append(root2)
            root2 = root2.left
        res = []
        while len(q1) != 0 and len(q2) != 0:
            if q1[-1].val > q2[-1].val:
                res.append(q2[-1].val)
                cur = q2.pop().right
                while cur:
                    q2.append(cur)
                    cur = cur.left
            else:
                res.append(q1[-1].val)
                cur = q1.pop().right
                while cur:
                    q1.append(cur)
                    cur = cur.left

        q = q1 if len(q1) != 0 else q2
        while len(q) != 0:
            res.append(q[-1].val)
            cur = q.pop().right
            while cur:
                q.append(cur)
                cur = cur.left

        return res
# @lc code=end

