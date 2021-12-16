/*
 * @lc app=leetcode.cn id=740 lang=cpp
 *
 * [740] 删除并获得点数
 *
 * https://leetcode-cn.com/problems/delete-and-earn/description/
 *
 * algorithms
 * Medium (62.80%)
 * Likes:    477
 * Dislikes: 0
 * Total Accepted:    56.8K
 * Total Submissions: 90.4K
 * Testcase Example:  '[3,4,2]'
 *
 * 给你一个整数数组 nums ，你可以对它进行一些操作。
 *
 * 每次操作中，选择任意一个 nums[i] ，删除它并获得 nums[i] 的点数。之后，你必须删除
 * 所有 等于 nums[i] - 1 和 nums[i] + 1 的元素。
 *
 * 开始你拥有 0 个点数。返回你能通过这些操作获得的最大点数。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [3,4,2]
 * 输出：6
 * 解释：
 * 删除 4 获得 4 个点数，因此 3 也被删除。
 * 之后，删除 2 获得 2 个点数。总共获得 6 个点数。
 *
 *
 * 示例 2：
 *
 *
 * 输入：nums = [2,2,3,3,3,4]
 * 输出：9
 * 解释：
 * 删除 3 获得 3 个点数，接着要删除两个 2 和 4 。
 * 之后，再次删除 3 获得 3 个点数，再次删除 3 获得 3 个点数。
 * 总共获得 9 个点数。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1
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
    int deleteAndEarn(vector<int> &nums) {
        map<int, int> mp;
        for (auto num : nums) {
            mp[num] += num;
        }
        int p = -1;
        int a = 0, b = 0;
        int t;
        for (auto &[k, v] : mp) {
            if (k > p + 1) {
                b = max(a, b);
                a = b + v;
            } else {
                t = a;
                a = max(b + v, a);
                b = max(t, b);
            }
            p = k;
        }
        return max(a, b);
    }
};
// @lc code=end

class Solution {
public:
    int deleteAndEarn(vector<int> &nums) {
        // 最简单 可以优化dp数组大小
        vector<int> dp(1e4, 0);
        for (auto num : nums) {
            dp[num - 1] += num;
        }
        int a = 0, b = 0;
        int t;
        for (int i = 0; i < 1e4; ++i) {
            t = a;
            a = max(b + dp[i], a);
            b = max(t, b);
        }
        return max(a, b);
    }
};
