/*
 * @lc app=leetcode.cn id=1315 lang=cpp
 *
 * [1315] 祖父节点值为偶数的节点和
 *
 * https://leetcode-cn.com/problems/sum-of-nodes-with-even-valued-grandparent/description/
 *
 * algorithms
 * Medium (81.00%)
 * Likes:    64
 * Dislikes: 0
 * Total Accepted:    13.1K
 * Total Submissions: 16.2K
 * Testcase Example:  '[6,7,8,2,7,1,3,9,null,1,4,null,null,null,5]'
 *
 * 给你一棵二叉树，请你返回满足以下条件的所有节点的值之和：
 *
 *
 * 该节点的祖父节点的值为偶数。（一个节点的祖父节点是指该节点的父节点的父节点。）
 *
 *
 * 如果不存在祖父节点值为偶数的节点，那么返回 0 。
 *
 *
 *
 * 示例：
 *
 *
 *
 * 输入：root = [6,7,8,2,7,1,3,9,null,1,4,null,null,null,5]
 * 输出：18
 * 解释：图中红色节点的祖父节点的值为偶数，蓝色节点为这些红色节点的祖父节点。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 树中节点的数目在 1 到 10^4 之间。
 * 每个节点的值在 1 到 100 之间。
 *
 *
 */
#include "struct.h"
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
  int sumEvenGrandparent(TreeNode *root) {
    if (root == nullptr)
      return 0;
    if (root->left) {
      mp[root->left] = root;
    }
    if (root->right) {
      mp[root->right] = root;
    }
    int t = 0;
    if (mp.find(root) != mp.end() && mp.find(mp[root]) != mp.end() &&
        mp[mp[root]]->val % 2 == 0) {
      t = root->val;
    }
    int l = sumEvenGrandparent(root->left);
    int r = sumEvenGrandparent(root->right);
    return l + r + t;
  }
  map<TreeNode *, TreeNode *> mp;
};
// @lc code=end

// 官方题解直接记录
class Solution1 {
private:
  int ans = 0;

public:
  void dfs(int gp_val, int p_val, TreeNode *node) {
    if (!node) {
      return;
    }
    if (gp_val % 2 == 0) {
      ans += node->val;
    }
    dfs(p_val, node->val, node->left);
    dfs(p_val, node->val, node->right);
  }

  int sumEvenGrandparent(TreeNode *root) {
    dfs(1, 1, root);
    return ans;
  }
};
