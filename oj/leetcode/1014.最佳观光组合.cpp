/*
 * @lc app=leetcode.cn id=1014 lang=cpp
 *
 * [1014] 最佳观光组合
 *
 * https://leetcode-cn.com/problems/best-sightseeing-pair/description/
 *
 * algorithms
 * Medium (55.31%)
 * Likes:    250
 * Dislikes: 0
 * Total Accepted:    41.5K
 * Total Submissions: 74.9K
 * Testcase Example:  '[8,1,5,2,6]'
 *
 * 给你一个正整数数组 values，其中 values[i] 表示第 i
 * 个观光景点的评分，并且两个景点 i 和 j 之间的 距离 为 j - i。
 *
 * 一对景点（i < j）组成的观光组合的得分为 values[i] + values[j] + i - j
 * ，也就是景点的评分之和 减去 它们两者之间的距离。
 *
 * 返回一对观光景点能取得的最高分。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：values = [8,1,5,2,6]
 * 输出：11
 * 解释：i = 0, j = 2, values[i] + values[j] + i - j = 8 + 5 + 0 - 2 = 11
 *
 *
 * 示例 2：
 *
 *
 * 输入：values = [1,2]
 * 输出：2
 *
 *
 *
 *
 * 提示：
 *
 *
 * 2
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
  int maxScoreSightseeingPair(vector<int> &values) {
    int pm = values[0];
    int n = values.size();
    int res = 0;
    for (int i = 1; i < n; ++i) {
      res = max(res, pm + values[i] - i);
      pm = max(pm, values[i] + i);
    }
    return res;
  }
};
// @lc code=end
