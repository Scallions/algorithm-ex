/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 *
 * https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
 *
 * algorithms
 * Medium (42.48%)
 * Likes:    1174
 * Dislikes: 0
 * Total Accepted:    319.3K
 * Total Submissions: 751.8K
 * Testcase Example:  '[5,7,7,8,8,10]\n8'
 *
 * 给定一个按照升序排列的整数数组 nums，和一个目标值
 * target。找出给定目标值在数组中的开始位置和结束位置。
 *
 * 如果数组中不存在目标值 target，返回 [-1, -1]。
 *
 * 进阶：
 *
 *
 * 你可以设计并实现时间复杂度为 O(log n) 的算法解决此问题吗？
 *
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [5,7,7,8,8,10], target = 8
 * 输出：[3,4]
 *
 * 示例 2：
 *
 *
 * 输入：nums = [5,7,7,8,8,10], target = 6
 * 输出：[-1,-1]
 *
 * 示例 3：
 *
 *
 * 输入：nums = [], target = 0
 * 输出：[-1,-1]
 *
 *
 *
 * 提示：
 *
 *
 * 0
 * -10^9
 * nums 是一个非递减数组
 * -10^9
 *
 *
 */
#include "struct.h"
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
  vector<int> searchRange(vector<int> &nums, int target) {
    vector<int> idx(2, -1);
    int n = nums.size();
    int l = 0;
    int r = n - 1;
    int m;
    if (n == 0 || target < nums[0] || target > nums[r])
      return idx;
    // start
    while (l < r) {
      m = l + (r - l) / 2;
      if (nums[m] == target) {
        r = m;
      }
      if (nums[m] < target) {
        l = m + 1;
      }
      if (nums[m] > target) {
        r = m - 1;
      }
    }
    if (nums[l] != target)
      return idx;
    idx[0] = l;
    // end
    l = 0;
    r = n - 1;
    while (l < r) {
      m = r - (r - l) / 2;
      if (nums[m] == target) {
        l = m;
      }
      if (nums[m] < target) {
        l = m + 1;
      }
      if (nums[m] > target) {
        r = m - 1;
      }
    }
    idx[1] = r;
    return idx;
  }
};
// @lc code=end
