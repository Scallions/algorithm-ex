/*
 * @lc app=leetcode.cn id=152 lang=cpp
 *
 * [152] 乘积最大子数组
 *
 * https://leetcode-cn.com/problems/maximum-product-subarray/description/
 *
 * algorithms
 * Medium (42.18%)
 * Likes:    1369
 * Dislikes: 0
 * Total Accepted:    197.8K
 * Total Submissions: 468.6K
 * Testcase Example:  '[2,3,-2,4]'
 *
 * 给你一个整数数组
 * nums ，请你找出数组中乘积最大的连续子数组（该子数组中至少包含一个数字），并返回该子数组所对应的乘积。
 *
 *
 *
 * 示例 1:
 *
 * 输入: [2,3,-2,4]
 * 输出: 6
 * 解释: 子数组 [2,3] 有最大乘积 6。
 *
 *
 * 示例 2:
 *
 * 输入: [-2,0,-1]
 * 输出: 0
 * 解释: 结果不能为 2, 因为 [-2,-1] 不是子数组。
 *
 */
#include "struct.h"
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
  int maxProduct(vector<int> &nums) {
    int neg = 0;
    int pos = 0;
    int res = nums[0];
    int n = nums.size();
    int t;
    for (int i = 0; i < n; ++i) {
      if (nums[i] == 0) {
        pos = 0;
        neg = 0;
        res = max(res, 0);
      } else if (nums[i] > 0) {
        pos = max(nums[i], pos * nums[i]);
        neg = neg * nums[i];
        res = max(res, pos);
      } else {
        t = pos;
        pos = neg * nums[i];
        neg = min(nums[i], t * nums[i]);
        if (pos != 0)
          res = max(res, pos);
      }
    }
    return res;
  }
};
// @lc code=end
