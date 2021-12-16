/*
 * @lc app=leetcode.cn id=397 lang=cpp
 *
 * [397] 整数替换
 *
 * https://leetcode-cn.com/problems/integer-replacement/description/
 *
 * algorithms
 * Medium (37.61%)
 * Likes:    130
 * Dislikes: 0
 * Total Accepted:    20.7K
 * Total Submissions: 52.4K
 * Testcase Example:  '8'
 *
 * 给定一个正整数 n ，你可以做如下操作：
 *
 *
 * 如果 n 是偶数，则用 n / 2替换 n 。
 * 如果 n 是奇数，则可以用 n + 1或n - 1替换 n 。
 *
 *
 * n 变为 1 所需的最小替换次数是多少？
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：n = 8
 * 输出：3
 * 解释：8 -> 4 -> 2 -> 1
 *
 *
 * 示例 2：
 *
 *
 * 输入：n = 7
 * 输出：4
 * 解释：7 -> 8 -> 4 -> 2 -> 1
 * 或 7 -> 6 -> 3 -> 2 -> 1
 *
 *
 * 示例 3：
 *
 *
 * 输入：n = 4
 * 输出：2
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
    int integerReplacement(int n) {
        int c = 0;
        long long t = n;
        while (t != 0) {
            while ((t & 1) != 1) {
                t >>= 1;
                ++c;
            }
            if ((t & 3) == 3) {
                if (t == 3)
                    return c + 2;
                ++t;
            } else {
                t -= 1;
            }
            ++c;
        }
        return c - 1;
    }
};
// @lc code=end

class Solution {
public:
    int integerReplacement(int n) {
        int c = 0;
        queue<long long> q;
        long long t;
        q.push(n);
        int ql;
        while (!q.empty()) {
            ql = q.size();
            for (int i = 0; i < ql; ++i) {
                t = q.front();
                q.pop();
                if (t == 1)
                    return c;
                if (t % 2 == 0) {
                    q.push(t >> 1);
                } else {
                    q.push(t + 1);
                    q.push(t - 1);
                }
            }
            ++c;
        }
        return c;
    }
};
