/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
 *
 * https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
 *
 * algorithms
 * Medium (70.49%)
 * Likes:    1285
 * Dislikes: 0
 * Total Accepted:    261.6K
 * Total Submissions: 371K
 * Testcase Example:  '[3,9,20,15,7]\n[9,3,15,20,7]'
 *
 * 给定一棵树的前序遍历 preorder 与中序遍历  inorder。请构造二叉树并返回其根节点。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
 * Output: [3,9,20,null,null,15,7]
 * 
 * 
 * 示例 2:
 * 
 * 
 * Input: preorder = [-1], inorder = [-1]
 * Output: [-1]
 * 
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 1 
 * inorder.length == preorder.length
 * -3000 
 * preorder 和 inorder 均无重复元素
 * inorder 均出现在 preorder
 * preorder 保证为二叉树的前序遍历序列
 * inorder 保证为二叉树的中序遍历序列
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // 使用map查找位置, inorder位置
        int n = preorder.size();
        for(int i=0; i<n; ++i){
            mp[inorder[i]] = i;
        }
        return helper(preorder, inorder, 0, n-1, 0, n-1);
    }

private:
    unordered_map<int, int> mp;
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int ps, int pe, int is, int ie){
        if(ps>pe) return nullptr;
        TreeNode* root = new TreeNode(preorder[ps]);
        int ii = mp[preorder[ps]];
        int ll = ii - is;
        root->left = helper(preorder, inorder, ps+1, ps+ll, is, ii-1);
        root->right = helper(preorder, inorder, ps+ll+1, pe, ii+1, ie);
        return root;
    }
};
// @lc code=end

