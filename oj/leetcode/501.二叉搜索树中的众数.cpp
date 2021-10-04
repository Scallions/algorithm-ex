/*
 * @lc app=leetcode.cn id=501 lang=cpp
 *
 * [501] 二叉搜索树中的众数
 *
 * https://leetcode-cn.com/problems/find-mode-in-binary-search-tree/description/
 *
 * algorithms
 * Easy (51.18%)
 * Likes:    353
 * Dislikes: 0
 * Total Accepted:    65.4K
 * Total Submissions: 127.7K
 * Testcase Example:  '[1,null,2,2]'
 *
 * 给定一个有相同值的二叉搜索树（BST），找出 BST 中的所有众数（出现频率最高的元素）。
 * 
 * 假定 BST 有如下定义：
 * 
 * 
 * 结点左子树中所含结点的值小于等于当前结点的值
 * 结点右子树中所含结点的值大于等于当前结点的值
 * 左子树和右子树都是二叉搜索树
 * 
 * 
 * 例如：
 * 给定 BST [1,null,2,2],
 * 
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  2
 * 
 * 
 * 返回[2].
 * 
 * 提示：如果众数超过1个，不需考虑输出顺序
 * 
 * 进阶：你可以不使用额外的空间吗？（假设由递归产生的隐式调用栈的开销不被计算在内）
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
    vector<int> findMode(TreeNode* root) {
        dfs(root);
        if(c>mc){ // 超过之前数量
            ans.clear();
            ans.push_back(ln);
        }else if(c==mc){
            ans.push_back(ln);
        }
        return ans;
    }
private:
    vector<int> ans;
    int ln = -1;
    int c = 0;
    int mc = 0;
    void dfs(TreeNode* root){
        if(!root) return;
        dfs(root->left);
        if(ln == -1){ // init
            c = 1;
        }else{
            if(ln==root->val){
                ++c;
            }else{// 更新
                if(c>mc){ // 超过之前数量
                    mc = c;
                    ans.clear();
                    ans.push_back(ln);
                }else if(c==mc){
                    ans.push_back(ln);
                }
                c = 1;
            }
        }
        ln = root->val;
        dfs(root->right);
    }
};
// @lc code=end

