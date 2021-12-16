/*
 * @lc app=leetcode.cn id=343 lang=cpp
 *
 * [343] 整数拆分
 *
 * https://leetcode-cn.com/problems/integer-break/description/
 *
 * algorithms
 * Medium (60.76%)
 * Likes:    639
 * Dislikes: 0
 * Total Accepted:    120.9K
 * Total Submissions: 198.4K
 * Testcase Example:  '2'
 *
 * 给定一个正整数 n，将其拆分为至少两个正整数的和，并使这些整数的乘积最大化。 返回你可以获得的最大乘积。
 *
 * 示例 1:
 *
 * 输入: 2
 * 输出: 1
 * 解释: 2 = 1 + 1, 1 × 1 = 1。
 *
 * 示例 2:
 *
 * 输入: 10
 * 输出: 36
 * 解释: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36。
 *
 * 说明: 你可以假设 n 不小于 2 且不大于 58。
 *
 */
#include <bits/stdc++.h>
#include "struct.h"
using namespace std;
// @lc code=start
class Solution {
public:
    int integerBreak(int n) {
        if(n<=2) return 1;
        vector<int> dp(n+1);
        dp[1] = 1;
        dp[2] = 2;
        for(int i=3; i<=n; ++i) {
            dp[i-1] = max(i-1, dp[i-1]);
            dp[i] = max(dp[i], dp[i-2]*2);
            dp[i] = max(dp[i], dp[i-3]*3);
        }
        return dp[n];
    }
};
// @lc code=end

