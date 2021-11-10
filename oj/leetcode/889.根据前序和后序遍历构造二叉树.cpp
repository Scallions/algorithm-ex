/*
 * @lc app=leetcode.cn id=889 lang=cpp
 *
 * [889] 根据前序和后序遍历构造二叉树
 *
 * https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/description/
 *
 * algorithms
 * Medium (67.70%)
 * Likes:    194
 * Dislikes: 0
 * Total Accepted:    16K
 * Total Submissions: 23.7K
 * Testcase Example:  '[1,2,4,5,3,6,7]\n[4,5,2,6,7,3,1]'
 *
 * 返回与给定的前序和后序遍历匹配的任何二叉树。
 * 
 * pre 和 post 遍历中的值是不同的正整数。
 * 
 * 
 * 
 * 示例：
 * 
 * 输入：pre = [1,2,4,5,3,6,7], post = [4,5,2,6,7,3,1]
 * 输出：[1,2,3,4,5,6,7]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= pre.length == post.length <= 30
 * pre[] 和 post[] 都是 1, 2, ..., pre.length 的排列
 * 每个输入保证至少有一个答案。如果有多个答案，可以返回其中一个。
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
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n = preorder.size();
        for(int i=0; i<n; ++i){
            mp[postorder[i]] = i;
        }
        return helper(preorder, postorder, 0, n-1, 0, n-1);
    }

private:
    unordered_map<int, int> mp;
    TreeNode* helper(vector<int>& preorder, vector<int>& postorder, int pres, int pree, int poss, int pose){
        if(pres>pree) return nullptr;
        TreeNode* root = new TreeNode(preorder[pres]);
        if(pres == pree) return root;
        int pi = mp[preorder[pres+1]];
        int ll = pi - poss+1;
        root->left = helper(preorder, postorder, pres+1, pres+ll, poss, pi);
        root->right = helper(preorder, postorder, pres+ll+1, pree, pi+1, pose-1);
        return root;
    }
};
// @lc code=end

