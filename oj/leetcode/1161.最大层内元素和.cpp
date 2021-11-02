/*
 * @lc app=leetcode.cn id=1161 lang=cpp
 *
 * [1161] 最大层内元素和
 *
 * https://leetcode-cn.com/problems/maximum-level-sum-of-a-binary-tree/description/
 *
 * algorithms
 * Medium (63.35%)
 * Likes:    47
 * Dislikes: 0
 * Total Accepted:    10.7K
 * Total Submissions: 16.9K
 * Testcase Example:  '[1,7,0,7,-8,null,null]'
 *
 * 给你一个二叉树的根节点 root。设根节点位于二叉树的第 1 层，而根节点的子节点位于第 2 层，依此类推。
 * 
 * 请你找出层内元素之和 最大 的那几层（可能只有一层）的层号，并返回其中 最小 的那个。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 输入：root = [1,7,0,7,-8,null,null]
 * 输出：2
 * 解释：
 * 第 1 层各元素之和为 1，
 * 第 2 层各元素之和为 7 + 0 = 7，
 * 第 3 层各元素之和为 7 + -8 = -1，
 * 所以我们返回第 2 层的层号，它的层内元素之和最大。
 * 
 * 
 * 示例 2：
 * 
 * 输入：root = [989,null,10250,98693,-89388,null,null,null,-32127]
 * 输出：2
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 树中的节点数介于 1 和 10^4 之间
 * -10^5 <= node.val <= 10^5
 * 
 * 
 */
#include <bits/stdc++.h>
#include "struct.h"
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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
            queue<TreeNode*> q;
            q.push(root);
            int ql;
            int max_sum = INT_MIN;
            int max_row;
            int row_sum;
            int row=1;
            while(!q.empty()){
                ql = q.size();
                row_sum = 0;
                while(ql--){
                    root = q.front();
                    q.pop();
                    row_sum += root->val;
                    if(root->left) q.push(root->left);
                    if(root->right) q.push(root->right);
                }
                if(row_sum>max_sum){
                    max_row = row;
                    max_sum = row_sum;
                }
                ++row;
            }
            return max_row;
    }
};
// @lc code=end

