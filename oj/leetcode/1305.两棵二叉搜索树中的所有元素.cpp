/*
 * @lc app=leetcode.cn id=1305 lang=cpp
 *
 * [1305] 两棵二叉搜索树中的所有元素
 *
 * https://leetcode-cn.com/problems/all-elements-in-two-binary-search-trees/description/
 *
 * algorithms
 * Medium (74.67%)
 * Likes:    65
 * Dislikes: 0
 * Total Accepted:    15.1K
 * Total Submissions: 20.2K
 * Testcase Example:  '[2,1,4]\r\n[1,0,3]\r'
 *
 * 给你 root1 和 root2 这两棵二叉搜索树。
 * 
 * 请你返回一个列表，其中包含 两棵树 中的所有整数并按 升序 排序。.
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 输入：root1 = [2,1,4], root2 = [1,0,3]
 * 输出：[0,1,1,2,3,4]
 * 
 * 
 * 示例 2：
 * 
 * 输入：root1 = [0,-10,10], root2 = [5,1,7,0,2]
 * 输出：[-10,0,0,1,2,5,7,10]
 * 
 * 
 * 示例 3：
 * 
 * 输入：root1 = [], root2 = [5,1,7,0,2]
 * 输出：[0,1,2,5,7]
 * 
 * 
 * 示例 4：
 * 
 * 输入：root1 = [0,-10,10], root2 = []
 * 输出：[-10,0,10]
 * 
 * 
 * 示例 5：
 * 
 * 
 * 
 * 输入：root1 = [1,null,8], root2 = [8,1]
 * 输出：[1,1,8,8]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 每棵树最多有 5000 个节点。
 * 每个节点的值在 [-10^5, 10^5] 之间。
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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> res1;
        stack<TreeNode*> stk;
        while(root1 || !stk.empty()){
            while(root1){
                stk.push(root1);
                root1 = root1->left;
            }
            root1 = stk.top();
            stk.pop();
            res1.push_back(root1->val);
            root1 = root1->right;
        }
        stack<TreeNode*> stk1;
        vector<int> res2;
        while(root2 || !stk1.empty()){
            while(root2){
                stk1.push(root2);
                root2 = root2->left;
            }
            root2 = stk1.top();
            stk1.pop();
            res2.push_back(root2->val);
            root2 = root2->right;
        }
        // sort(res.begin(), res.end());
        vector<int> res;
        int i=0,j=0;
        while(i<res1.size() || j<res2.size()){
            if (i < res1.size() && (j == res2.size() || res1[i] <= res2[j])) {
                res.push_back(res1[i++]);
            }
            else {
                res.push_back(res2[j++]);
            }
        }
        return res;
    }
};
// @lc code=end

