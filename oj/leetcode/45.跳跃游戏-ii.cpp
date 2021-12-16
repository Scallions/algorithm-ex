/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 *
 * https://leetcode-cn.com/problems/jump-game-ii/description/
 *
 * algorithms
 * Medium (43.21%)
 * Likes:    1282
 * Dislikes: 0
 * Total Accepted:    225.4K
 * Total Submissions: 520.7K
 * Testcase Example:  '[2,3,1,1,4]'
 *
 * 给你一个非负整数数组 nums ，你最初位于数组的第一个位置。
 *
 * 数组中的每个元素代表你在该位置可以跳跃的最大长度。
 *
 * 你的目标是使用最少的跳跃次数到达数组的最后一个位置。
 *
 * 假设你总是可以到达数组的最后一个位置。
 *
 *
 *
 * 示例 1:
 *
 *
 * 输入: nums = [2,3,1,1,4]
 * 输出: 2
 * 解释: 跳到最后一个位置的最小跳跃数是 2。
 * 从下标为 0 跳到下标为 1 的位置，跳 1 步，然后跳 3 步到达数组的最后一个位置。
 *
 *
 * 示例 2:
 *
 *
 * 输入: nums = [2,3,0,1,4]
 * 输出: 2
 *
 *
 *
 *
 * 提示:
 *
 *
 * 1
 * 0
 *
 *
 */
#include "struct.h"
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
  int jump(vector<int> &nums) {
    int c = 0;
    int l = 0;
    int nl;
    int cnt = 0;
    int n = nums.size() - 1;
    while (c < n) {
      nl = l;
      for (int i = c; i <= l; ++i) {
        nl = max(nl, i + nums[i]);
        if (nl >= n)
          return cnt + 1;
      }
      c = l + 1;
      l = nl;
      ++cnt;
    }
    return cnt;
  }
};
// @lc code=end
// 优化过一点的官方题解
class Solution1 {
public:
  int jump(vector<int> &nums) {
    int maxPos = 0, n = nums.size() - 1, end = 0, step = 0;
    for (int i = 0; i < n; ++i) {
      if (maxPos >= i) {
        maxPos = max(maxPos, i + nums[i]);
        if (i == end) {
          end = maxPos;
          ++step;
        }
      }
    }
    return step;
  }
};