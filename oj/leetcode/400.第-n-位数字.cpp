/*
 * @lc app=leetcode.cn id=400 lang=cpp
 *
 * [400] 第 N 位数字
 *
 * https://leetcode-cn.com/problems/nth-digit/description/
 *
 * algorithms
 * Medium (41.86%)
 * Likes:    249
 * Dislikes: 0
 * Total Accepted:    32.5K
 * Total Submissions: 72.4K
 * Testcase Example:  '3'
 *
 * 给你一个整数 n ，请你在无限的整数序列 [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11,
 * ...] 中找出并返回第 n 位数字。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：n = 3
 * 输出：3
 *
 *
 * 示例 2：
 *
 *
 * 输入：n = 11
 * 输出：0
 * 解释：第 11 位数字在序列 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... 里是 0 ，它是
 * 10 的一部分。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= n <= 2^31 - 1
 *
 *
 */

// @lc code=start
class Solution {
public:
    int findNthDigit(int n) {
        int l = 1; // 长度
        int b = 1; // base个数
        long long c = 0;
        long long nc = c + l * (9 * b);
        while (nc < n) {
            c = nc;
            ++l;
            b *= 10;
            nc += (9ll * b) * l;
        }
        int t1 = (n - c - 1) / l + b;
        int t2 = (n - c - 1) % l;
        int t3 = l - t2;
        // cout << c << ", " << l << ", " << b << endl;
        // cout << t1 << ", " << t2 << endl;
        while (--t3) {
            t1 /= 10;
        }
        return t1 % 10;
    }
};
// @lc code=end
