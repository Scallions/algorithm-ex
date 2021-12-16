/*
 * @lc app=leetcode.cn id=376 lang=cpp
 *
 * [376] 摆动序列
 *
 * https://leetcode-cn.com/problems/wiggle-subsequence/description/
 *
 * algorithms
 * Medium (46.54%)
 * Likes:    549
 * Dislikes: 0
 * Total Accepted:    83.3K
 * Total Submissions: 178.4K
 * Testcase Example:  '[1,7,4,9,2,5]'
 *
 * 如果连续数字之间的差严格地在正数和负数之间交替，则数字序列称为 摆动序列
 * 。第一个差（如果存在的话）可能是正数或负数。仅有一个元素或者含两个不等元素的序列也视作摆动序列。
 *
 *
 *
 * 例如， [1, 7, 4, 9, 2, 5] 是一个 摆动序列 ，因为差值 (6, -3, 5, -7,
 * 3) 是正负交替出现的。
 *
 * 相反，[1, 4, 7, 2, 5] 和 [1, 7, 4, 5, 5]
 * 不是摆动序列，第一个序列是因为它的前两个差值都是正数，第二个序列是因为它的最后一个差值为零。
 *
 *
 * 子序列
 * 可以通过从原始序列中删除一些（也可以不删除）元素来获得，剩下的元素保持其原始顺序。
 *
 * 给你一个整数数组 nums ，返回 nums 中作为 摆动序列 的 最长子序列的长度 。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [1,7,4,9,2,5]
 * 输出：6
 * 解释：整个序列均为摆动序列，各元素之间的差值为 (6, -3, 5, -7, 3) 。
 *
 *
 * 示例 2：
 *
 *
 * 输入：nums = [1,17,5,10,13,15,10,5,16,8]
 * 输出：7
 * 解释：这个序列包含几个长度为 7 摆动序列。
 * 其中一个是 [1, 17, 10, 13, 10, 16, 8] ，各元素之间的差值为 (16, -7, 3, -3, 6,
 * -8) 。
 *
 *
 * 示例 3：
 *
 *
 * 输入：nums = [1,2,3,4,5,6,7,8,9]
 * 输出：2
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1
 * 0
 *
 *
 *
 *
 * 进阶：你能否用 O(n) 时间复杂度完成此题?
 *
 */
#include "struct.h"
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
  int wiggleMaxLength(vector<int> &nums) {
    int n = nums.size();
    if (n == 1)
      return 1;
    int i = 1;
    for (; i < n; ++i) {
      if (nums[i] != nums[i - 1])
        break;
    }
    if (i == n)
      return 1;
    int t = nums[i] - nums[i - 1];
    int t1;
    int c = 2;
    for (; i < n; ++i) {
      t1 = nums[i] - nums[i - 1];
      if (t1 == 0)
        continue;
      if (t1 * t < 0) {
        ++c;
      }
      t = t1;
    }
    return c;
  }
};
// @lc code=end

class Solution1 {
public:
  int wiggleMaxLength(vector<int> &nums) {
    int n = nums.size();
    if (n < 2) {
      return n;
    }
    int up = 1, down = 1;
    for (int i = 1; i < n; i++) {
      if (nums[i] > nums[i - 1]) {
        up = max(up, down + 1);
      } else if (nums[i] < nums[i - 1]) {
        down = max(up + 1, down);
      }
    }
    return max(up, down);
  }
};
