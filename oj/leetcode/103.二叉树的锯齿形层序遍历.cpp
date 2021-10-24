/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层序遍历
 *
 * https://leetcode-cn.com/problems/binary-tree-zigzag-level-order-traversal/description/
 *
 * algorithms
 * Medium (57.16%)
 * Likes:    534
 * Dislikes: 0
 * Total Accepted:    178.9K
 * Total Submissions: 312.8K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定一个二叉树，返回其节点值的锯齿形层序遍历。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。
 * 
 * 例如：
 * 给定二叉树 [3,9,20,null,null,15,7],
 * 
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 
 * 返回锯齿形层序遍历如下：
 * 
 * 
 * [
 * ⁠ [3],
 * ⁠ [20,9],
 * ⁠ [15,7]
 * ]
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==nullptr) return {};
        vector<vector<int>> res;
        stack<TreeNode*> stk;
        stk.push(root);
        int sl;
        int c = 0;
        while(!stk.empty()){
            sl = stk.size();
            vector<int> tmp;
            stack<TreeNode*> nxt;
            for(int i=0; i<sl; ++i){
                root = stk.top(); stk.pop();
                if(c%2==0){
                    if(root->left) nxt.push(root->left);
                    if(root->right) nxt.push(root->right);
                }else{
                    if(root->right) nxt.push(root->right);
                    if(root->left) nxt.push(root->left);
                }
                tmp.push_back(root->val);
            }
            stk = nxt;
            ++c;
            res.push_back(tmp);
        }
        return res;
    }
};
// @lc code=end

