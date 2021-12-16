/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 *
 * https://leetcode-cn.com/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (35.68%)
 * Likes:    4433
 * Dislikes: 0
 * Total Accepted:    805.7K
 * Total Submissions: 2.2M
 * Testcase Example:  '"babad"'
 *
 * 给你一个字符串 s，找到 s 中最长的回文子串。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：s = "babad"
 * 输出："bab"
 * 解释："aba" 同样是符合题意的答案。
 *
 *
 * 示例 2：
 *
 *
 * 输入：s = "cbbd"
 * 输出："bb"
 *
 *
 * 示例 3：
 *
 *
 * 输入：s = "a"
 * 输出："a"
 *
 *
 * 示例 4：
 *
 *
 * 输入：s = "ac"
 * 输出："a"
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1
 * s 仅由数字和英文字母（大写和/或小写）组成
 *
 *
 */
#include "struct.h"
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
  string longestPalindrome(string s) {
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
      dp[i][i] = true;
    }
    int begin = 0;
    int maxLen = 1;
    string res;
    for (int i = 1; i < n; ++i) {
      for (int j = 0; j < n - i; ++j) {
        if (s[j] != s[i + j])
          continue;
        if (j + 1 <= j + i - 1) {
          dp[j][i + j] = dp[j + 1][i + j - 1];
        } else {
          dp[j][i + j] = true;
        }
        if (dp[j][i + j] && i + 1 > maxLen) {
          maxLen = i + 1;
          begin = j;
        }
      }
    }
    return s.substr(begin, maxLen);
    ;
  }
};
// @lc code=end
