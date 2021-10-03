/*
 * @lc app=leetcode.cn id=653 lang=cpp
 *
 * [653] 两数之和 IV - 输入 BST
 *
 * https://leetcode-cn.com/problems/two-sum-iv-input-is-a-bst/description/
 *
 * algorithms
 * Easy (59.63%)
 * Likes:    282
 * Dislikes: 0
 * Total Accepted:    41K
 * Total Submissions: 68.6K
 * Testcase Example:  '[5,3,6,2,4,null,7]\n9'
 *
 * 给定一个二叉搜索树 root 和一个目标结果 k，如果 BST 中存在两个元素且它们的和等于给定的目标结果，则返回 true。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入: root = [5,3,6,2,4,null,7], k = 9
 * 输出: true
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入: root = [5,3,6,2,4,null,7], k = 28
 * 输出: false
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入: root = [2,1,3], k = 4
 * 输出: true
 * 
 * 
 * 示例 4：
 * 
 * 
 * 输入: root = [2,1,3], k = 1
 * 输出: false
 * 
 * 
 * 示例 5：
 * 
 * 
 * 输入: root = [2,1,3], k = 3
 * 输出: true
 * 
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 二叉树的节点个数的范围是  [1, 10^4].
 * -10^4 
 * root 为二叉搜索树
 * -10^5 
 * 
 * 
 */
#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        t = k;
        return dfs(root);
    }
private:
    set<int> ss;
    int t;
    bool dfs(TreeNode* root){
        if(root==nullptr) return false;
        if(ss.find(t-root->val) != ss.end()) return true;
        ss.insert(root->val);
        return dfs(root->left) || dfs(root->right);
    }
};
// @lc code=end

