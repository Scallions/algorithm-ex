/*
 * @lc app=leetcode.cn id=630 lang=cpp
 *
 * [630] 课程表 III
 *
 * https://leetcode-cn.com/problems/course-schedule-iii/description/
 *
 * algorithms
 * Hard (37.08%)
 * Likes:    270
 * Dislikes: 0
 * Total Accepted:    19.1K
 * Total Submissions: 43.1K
 * Testcase Example:  '[[100,200],[200,1300],[1000,1250],[2000,3200]]'
 *
 * 这里有 n 门不同的在线课程，按从 1 到 n 编号。给你一个数组 courses ，其中
 * courses[i] = [durationi, lastDayi] 表示第 i 门课将会 持续 上 durationi
 * 天课，并且必须在不晚于 lastDayi 的时候完成。
 *
 * 你的学期从第 1 天开始。且不能同时修读两门及两门以上的课程。
 *
 * 返回你最多可以修读的课程数目。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：courses = [[100, 200], [200, 1300], [1000, 1250], [2000, 3200]]
 * 输出：3
 * 解释：
 * 这里一共有 4 门课程，但是你最多可以修 3 门：
 * 首先，修第 1 门课，耗费 100 天，在第 100 天完成，在第 101 天开始下门课。
 * 第二，修第 3 门课，耗费 1000 天，在第 1100 天完成，在第 1101 天开始下门课程。
 * 第三，修第 2 门课，耗时 200 天，在第 1300 天完成。
 * 第 4 门课现在不能修，因为将会在第 3300 天完成它，这已经超出了关闭日期。
 *
 * 示例 2：
 *
 *
 * 输入：courses = [[1,2]]
 * 输出：1
 *
 *
 * 示例 3：
 *
 *
 * 输入：courses = [[3,2],[4,3]]
 * 输出：0
 *
 *
 *
 *
 * 提示:
 *
 *
 * 1 <= courses.length <= 10^4
 * 1 <= durationi, lastDayi <= 10^4
 *
 *
 */
#include "struct.h"
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int scheduleCourse(vector<vector<int>> &courses) {
        sort(courses.begin(), courses.end(),
        [](const auto &c0, const auto &c1) {
            return c0[1] < c1[1];
        });
        priority_queue<int> q;
        int total = 0;
        int ti, di;
        for (const auto &course : courses) {
            ti = course[0];
            di = course[1];
            if (total + ti <= di) {
                total += ti;
                q.push(ti);
            } else if (!q.empty() && q.top() > ti) {
                total -= q.top() - ti;
                q.pop();
                q.push(ti);
            }
        }
        return q.size();
    }
};
// @lc code=end

// 超时
class Solution1 {
public:
    int scheduleCourse(vector<vector<int>> &courses) {
        vector<int> dp(20001, -1);
        dp[0] = 0;
        int d, l;
        auto cmp = [&](const vector<int> &x, const vector<int> &y) {
            // return x[0] != y[0]?x[0]<y[0]:x[1]<y[1];
            return x[1] != y[1] ? x[1] < y[1] : x[0] < y[0];
        };
        sort(courses.begin(), courses.end(), cmp);
        for (auto c : courses) {
            // cout << c[0] <<"," << c[1] << endl;
            d = c[0];
            l = min(c[1], 10000);
            for (int i = l; i >= d; --i) {
                if (dp[i - d] != -1) {
                    dp[i] = max(dp[i], dp[i - d] + 1);
                }
            }
        }
        int res = 0;
        for (int i = 0; i <= 20000; ++i) {
            res = max(res, dp[i]);
        }
        return res;
    }
};
