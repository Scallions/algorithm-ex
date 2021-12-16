/*
 * @lc app=leetcode.cn id=264 lang=cpp
 *
 * [264] 丑数 II
 *
 * https://leetcode-cn.com/problems/ugly-number-ii/description/
 *
 * algorithms
 * Medium (58.04%)
 * Likes:    786
 * Dislikes: 0
 * Total Accepted:    105.3K
 * Total Submissions: 181.6K
 * Testcase Example:  '10'
 *
 * 给你一个整数 n ，请你找出并返回第 n 个 丑数 。
 *
 * 丑数 就是只包含质因数 2、3 和/或 5 的正整数。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：n = 10
 * 输出：12
 * 解释：[1, 2, 3, 4, 5, 6, 8, 9, 10, 12] 是由前 10 个丑数组成的序列。
 *
 *
 * 示例 2：
 *
 *
 * 输入：n = 1
 * 输出：1
 * 解释：1 通常被视为丑数。
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
#include "struct.h"
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp;
        dp.push_back(1);
        vector<int> idx(3, 0);
        vector<int> dd{2, 3, 5};
        vector<int> mm{2, 3, 5};
        for (int i = 1; i < n; ++i) {
            int m = INT_MAX;
            for (int j = 0; j < 3; ++j) {
                if (mm[j] < m) {
                    m = mm[j];
                }
            }
            dp.push_back(m);
            for (int j = 0; j < 3; ++j) {
                if (mm[j] == m) {
                    ++idx[j];
                    mm[j] = dp[idx[j]] * dd[j];
                }
            }
        }
        return dp[n - 1];
    }
};
// @lc code=end
