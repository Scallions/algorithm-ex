/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
 *
 * https://leetcode-cn.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/
 *
 * algorithms
 * Medium (72.16%)
 * Likes:    614
 * Dislikes: 0
 * Total Accepted:    140.3K
 * Total Submissions: 194.6K
 * Testcase Example:  '[9,3,15,20,7]\n[9,15,7,20,3]'
 *
 * 根据一棵树的中序遍历与后序遍历构造二叉树。
 * 
 * 注意:
 * 你可以假设树中没有重复的元素。
 * 
 * 例如，给出
 * 
 * 中序遍历 inorder = [9,3,15,20,7]
 * 后序遍历 postorder = [9,15,7,20,3]
 * 
 * 返回如下的二叉树：
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        for(int i=0; i<n; ++i){
            mp[inorder[i]] = i;
        }
        return helper(inorder, postorder, 0, n-1, 0 , n-1);
    }

private:
    unordered_map<int, int> mp;
    TreeNode* helper(vector<int>& inorder, vector<int>& postorder, int is, int ie, int ps, int pe) {
        if(is>ie) return nullptr;
        TreeNode* root = new TreeNode(postorder[pe]);
        int ii = mp[postorder[pe]];
        int ll = ii - is;
        root->left = helper(inorder,postorder,is,ii-1,ps,ps+ll-1);
        root->right = helper(inorder,postorder,ii+1,ie,ps+ll,pe-1);
        return root;
    }
};
// @lc code=end

