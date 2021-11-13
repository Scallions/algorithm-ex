/*
 * @lc app=leetcode.cn id=894 lang=cpp
 *
 * [894] 所有可能的满二叉树
 *
 * https://leetcode-cn.com/problems/all-possible-full-binary-trees/description/
 *
 * algorithms
 * Medium (77.53%)
 * Likes:    232
 * Dislikes: 0
 * Total Accepted:    13.5K
 * Total Submissions: 17.4K
 * Testcase Example:  '7'
 *
 * 满二叉树是一类二叉树，其中每个结点恰好有 0 或 2 个子结点。
 * 
 * 返回包含 N 个结点的所有可能满二叉树的列表。 答案的每个元素都是一个可能树的根结点。
 * 
 * 答案中每个树的每个结点都必须有 node.val=0。
 * 
 * 你可以按任何顺序返回树的最终列表。
 * 
 * 
 * 
 * 示例：
 * 
 * 输入：7
 * 
 * 输出：[[0,0,0,null,null,0,0,null,null,0,0],[0,0,0,null,null,0,0,0,0],[0,0,0,0,0,0,0],[0,0,0,0,0,null,null,null,null,0,0],[0,0,0,0,0,null,null,0,0]]
 * 解释：
 * 
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= N <= 20
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
    vector<TreeNode*> allPossibleFBT(int n) {
        if(n%2 == 0) return {};
        int t = n/2+1;
        vector<vector<TreeNode*>> dp(t);
        dp[0].push_back(new TreeNode(0));
        for(int i=0; i<t; ++i){
            for(int j=0; j<i; ++j){
                for(auto left: dp[j]){
                    for(auto right: dp[i-j-1]){
                        TreeNode* root = new TreeNode(0);
                        root->left = left;
                        root->right = right;
                        dp[i].push_back(root);
                    }
                }
            }
        }
        return dp[t-1];
    }
};
// @lc code=end

