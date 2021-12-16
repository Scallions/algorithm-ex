/*
 * @lc app=leetcode.cn id=96 lang=cpp
 *
 * [96] 不同的二叉搜索树
 *
 * https://leetcode-cn.com/problems/unique-binary-search-trees/description/
 *
 * algorithms
 * Medium (69.97%)
 * Likes:    1426
 * Dislikes: 0
 * Total Accepted:    178.2K
 * Total Submissions: 254.8K
 * Testcase Example:  '3'
 *
 * 给你一个整数 n ，求恰由 n 个节点组成且节点值从 1 到 n 互不相同的 二叉搜索树 有多少种？返回满足题意的二叉搜索树的种数。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：n = 3
 * 输出：5
 *
 *
 * 示例 2：
 *
 *
 * 输入：n = 1
 * 输出：1
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1
 *
 *
 */
#include <bits/stdc++.h>
#include "struct.h"
using namespace std;
// @lc code=start
class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1,1);
        for(int i=2; i<=n; ++i) {
            int res = 0;
            for(int j=0; j<i; ++j) {
                res += dp[j] * dp[i-1-j];
            }
            dp[i] = res;
        }
        return dp[n];
    }
};
// @lc code=end

class Solution1 {
public:
    int numTrees(int n) {
        vector<int> res{1
                        ,2
                        ,5
                        ,14
                        ,42
                        ,132
                        ,429
                        ,1430
                        ,4862
                        ,16796
                        ,58786
                        ,208012
                        ,742900
                        ,2674440
                        ,9694845
                        ,35357670
                        ,129644790
                        ,477638700
                        ,1767263190};
        return res[n-1];
    }
};