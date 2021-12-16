/*
 * @lc app=leetcode.cn id=918 lang=cpp
 *
 * [918] 环形子数组的最大和
 *
 * https://leetcode-cn.com/problems/maximum-sum-circular-subarray/description/
 *
 * algorithms
 * Medium (35.76%)
 * Likes:    242
 * Dislikes: 0
 * Total Accepted:    24.6K
 * Total Submissions: 68.9K
 * Testcase Example:  '[1,-2,3,-2]'
 *
 * 给定一个由整数数组 A 表示的环形数组 C，求 C 的非空子数组的最大可能和。
 *
 * 在此处，环形数组意味着数组的末端将会与开头相连呈环状。（形式上，当0 <= i <
 * A.length 时 C[i] = A[i]，且当 i >= 0 时 C[i+A.length] = C[i]）
 *
 * 此外，子数组最多只能包含固定缓冲区
 * A 中的每个元素一次。（形式上，对于子数组 C[i], C[i+1], ..., C[j]，不存在 i <=
 * k1, k2 <= j 其中 k1 % A.length = k2 % A.length）
 *
 *
 *
 * 示例 1：
 *
 * 输入：[1,-2,3,-2]
 * 输出：3
 * 解释：从子数组 [3] 得到最大和 3
 *
 *
 * 示例 2：
 *
 * 输入：[5,-3,5]
 * 输出：10
 * 解释：从子数组 [5,5] 得到最大和 5 + 5 = 10
 *
 *
 * 示例 3：
 *
 * 输入：[3,-1,2,-1]
 * 输出：4
 * 解释：从子数组 [2,-1,3] 得到最大和 2 + (-1) + 3 = 4
 *
 *
 * 示例 4：
 *
 * 输入：[3,-2,2,-3]
 * 输出：3
 * 解释：从子数组 [3] 和 [3,-2,2] 都可以得到最大和 3
 *
 *
 * 示例 5：
 *
 * 输入：[-2,-3,-1]
 * 输出：-1
 * 解释：从子数组 [-1] 得到最大和 -1
 *
 *
 *
 *
 * 提示：
 *
 *
 * -30000 <= A[i] <= 30000
 * 1 <= A.length <= 30000
 *
 *
 */
#include "struct.h"
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
  int maxSubarraySumCircular(vector<int> &nums) {
    int res = nums[0];
    int p = 0;
    int n = nums.size();
    vector<int> mm(n, 0);
    int ps = 0;
    int pm = nums[0];
    for (int i = 0; i < n; ++i) {
      int num = nums[i];
      p = max(p + num, num);
      res = max(p, res);
      ps += nums[i];
      pm = max(ps, pm);
      mm[i] = pm;
    }
    // 2nd
    int ps = 0;
    int pm = nums[n - 1];
    for (int i = n - 1; i > 0; --i) {
      ps += nums[i];
      pm = max(pm, ps);
      res = max(res, pm + mm[i - 1]);
    }
    return res;
  }
};
// @lc code=end
// 转换为求最小子数组和
class Solution1 {
public:
  int maxSubarraySumCircular(vector<int> &nums) {
    int maxCur, maxSum, minCur, minSum, total;
    maxCur = maxSum = minCur = minSum = total = nums[0];
    for (int i = 1; i < nums.size(); ++i) {
      maxCur = maxCur < 0 ? nums[i] : maxCur + nums[i];
      maxSum = max(maxSum, maxCur);
      minCur = minCur > 0 ? nums[i] : minCur + nums[i];
      minSum = min(minSum, minCur);
      total += nums[i];
    }
    if (maxSum < 0)
      return maxSum;
    return max(maxSum, total - minSum);
  }
};