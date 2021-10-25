/*
 * @lc app=leetcode.cn id=515 lang=cpp
 *
 * [515] 在每个树行中找最大值
 *
 * https://leetcode-cn.com/problems/find-largest-value-in-each-tree-row/description/
 *
 * algorithms
 * Medium (64.52%)
 * Likes:    154
 * Dislikes: 0
 * Total Accepted:    39.9K
 * Total Submissions: 61.8K
 * Testcase Example:  '[1,3,2,5,3,null,9]'
 *
 * 给定一棵二叉树的根节点 root ，请找出该二叉树中每一层的最大值。
 * 
 * 
 * 
 * 示例1：
 * 
 * 
 * 输入: root = [1,3,2,5,3,null,9]
 * 输出: [1,3,9]
 * 解释:
 * ⁠         1
 * ⁠        / \
 * ⁠       3   2
 * ⁠      / \   \  
 * ⁠     5   3   9 
 * 
 * 
 * 示例2：
 * 
 * 
 * 输入: root = [1,2,3]
 * 输出: [1,3]
 * 解释:
 * ⁠         1
 * ⁠        / \
 * ⁠       2   3
 * 
 * 
 * 示例3：
 * 
 * 
 * 输入: root = [1]
 * 输出: [1]
 * 
 * 
 * 示例4：
 * 
 * 
 * 输入: root = [1,null,2]
 * 输出: [1,2]
 * 解释:      
 * 1 
 * \
 * 2     
 * 
 * 
 * 示例5：
 * 
 * 
 * 输入: root = []
 * 输出: []
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 二叉树的节点个数的范围是 [0,10^4]
 * -2^31 
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
    vector<int> largestValues(TreeNode* root) {
        if(root == nullptr) return {};
        vector<int> res;
        int ql, m;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            ql = q.size();
            m = q.front()->val;
            for(int i=0; i<ql; ++i){
                root = q.front();
                q.pop();
                m = max(m, root->val);
                if(root->left) q.push(root->left);
                if(root->right) q.push(root->right);
            }
            res.push_back(m);
        }
        return res;
    }
};
// @lc code=end

