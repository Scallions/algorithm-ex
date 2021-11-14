/*
 * @lc app=leetcode.cn id=1130 lang=cpp
 *
 * [1130] 叶值的最小代价生成树
 *
 * https://leetcode-cn.com/problems/minimum-cost-tree-from-leaf-values/description/
 *
 * algorithms
 * Medium (63.00%)
 * Likes:    197
 * Dislikes: 0
 * Total Accepted:    6.1K
 * Total Submissions: 9.6K
 * Testcase Example:  '[6,2,4]'
 *
 * 给你一个正整数数组 arr，考虑所有满足以下条件的二叉树：
 * 
 * 
 * 每个节点都有 0 个或是 2 个子节点。
 * 数组 arr 中的值与树的中序遍历中每个叶节点的值一一对应。（知识回顾：如果一个节点有 0 个子节点，那么该节点为叶节点。）
 * 每个非叶节点的值等于其左子树和右子树中叶节点的最大值的乘积。
 * 
 * 
 * 在所有这样的二叉树中，返回每个非叶节点的值的最小可能总和。这个和的值是一个 32 位整数。
 * 
 * 
 * 
 * 示例：
 * 
 * 输入：arr = [6,2,4]
 * 输出：32
 * 解释：
 * 有两种可能的树，第一种的非叶节点的总和为 36，第二种非叶节点的总和为 32。
 * 
 * ⁠   24            24
 * ⁠  /  \          /  \
 * ⁠ 12   4        6    8
 * ⁠/  \               / \
 * 6    2             2   4
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 2 <= arr.length <= 40
 * 1 <= arr[i] <= 15
 * 答案保证是一个 32 位带符号整数，即小于 2^31。
 * 
 * 
 */
#include <bits/stdc++.h>
#include "struct.h"
using namespace std;
// @lc code=start
class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n));
        vector<vector<int>> mp(n, vector<int>(n));
        for(int i=0; i<n; ++i){
            mp[i][i] = arr[i];
        }
        for(int l=2; l<=n; ++l){
            for(int i=0; i<n+1-l; ++i){
                dp[i][i+l-1] = INT_MAX;
                for(int j=i; j<i+l-1; j+=1){
                    int lm=mp[i][j];
                    int rm=mp[j+1][i+l-1];
                    int ld=dp[i][j];
                    int rd=dp[j+1][i+l-1];
                    mp[i][i+l-1] = max(mp[i][i+l-1], max(lm, rm));
                    dp[i][i+l-1] = min(dp[i][i+l-1], ld+rd+lm*rm);
                }
            }
        }
        return dp[0][n-1];
    }
};
// @lc code=end

// 最快解 贪心
class Solution1 {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int ans=0;
        int pos=0;
        while(arr.size()>1){
            int min=INT_MAX;
            for(int i=0;i<arr.size()-1;i++){
                if(min>arr[i]*arr[i+1]){
                    min=arr[i]*arr[i+1];
                    pos=arr[i]<arr[i+1]?i:i+1;
                }
            }
            ans+=min;
            arr.erase(arr.begin()+pos);
        }
        return ans;
    }
};