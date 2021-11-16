/*
 * @lc app=leetcode.cn id=391 lang=cpp
 *
 * [391] 完美矩形
 *
 * https://leetcode-cn.com/problems/perfect-rectangle/description/
 *
 * algorithms
 * Hard (36.08%)
 * Likes:    114
 * Dislikes: 0
 * Total Accepted:    6.5K
 * Total Submissions: 16.2K
 * Testcase Example:  '[[1,1,3,3],[3,1,4,2],[3,2,4,4],[1,3,2,4],[2,3,3,4]]'
 *
 * 给你一个数组 rectangles ，其中 rectangles[i] = [xi, yi, ai, bi]
 * 表示一个坐标轴平行的矩形。这个矩形的左下顶点是 (xi, yi) ，右上顶点是 (ai, bi) 。
 * 
 * 如果所有矩形一起精确覆盖了某个矩形区域，则返回 true ；否则，返回 false 。
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：rectangles = [[1,1,3,3],[3,1,4,2],[3,2,4,4],[1,3,2,4],[2,3,3,4]]
 * 输出：true
 * 解释：5 个矩形一起可以精确地覆盖一个矩形区域。 
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：rectangles = [[1,1,2,3],[1,3,2,4],[3,1,4,2],[3,2,4,4]]
 * 输出：false
 * 解释：两个矩形之间有间隔，无法覆盖成一个矩形。
 * 
 * 示例 3：
 * 
 * 
 * 输入：rectangles = [[1,1,3,3],[3,1,4,2],[1,3,2,4],[3,2,4,4]]
 * 输出：false
 * 解释：图形顶端留有空缺，无法覆盖成一个矩形。
 * 
 * 示例 4：
 * 
 * 
 * 输入：rectangles = [[1,1,3,3],[3,1,4,2],[1,3,2,4],[2,2,4,4]]
 * 输出：false
 * 解释：因为中间有相交区域，虽然形成了矩形，但不是精确覆盖。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= rectangles.length <= 2 * 10^4
 * rectangles[i].length == 4
 * -10^5 <= xi, yi, ai, bi <= 10^5
 * 
 * 
 */
#include <bits/stdc++.h>
#include "struct.h"
using namespace std;
// @lc code=start
typedef pair<int, int> Point;

class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        long area = 0;
        int minX = rectangles[0][0], minY = rectangles[0][1], maxX = rectangles[0][2], maxY = rectangles[0][3];
        map<Point, int> cnt;
        for (auto & rect : rectangles) {
            int x = rect[0], y = rect[1], a = rect[2], b = rect[3];
            area += (long) (a - x) * (b - y);

            minX = min(minX, x);
            minY = min(minY, y);
            maxX = max(maxX, a);
            maxY = max(maxY, b);

            Point point1({x, y});
            Point point2({x, b});
            Point point3({a, y});
            Point point4({a, b});

            cnt[point1] += 1;
            cnt[point2] += 1;
            cnt[point3] += 1;
            cnt[point4] += 1;
        }

        Point pointMinMin({minX, minY});
        Point pointMinMax({minX, maxY});
        Point pointMaxMin({maxX, minY});
        Point pointMaxMax({maxX, maxY});
        if (area != (long long) (maxX - minX) * (maxY - minY) || !cnt.count(pointMinMin) || !cnt.count(pointMinMax) || !cnt.count(pointMaxMin) || !cnt.count(pointMaxMax)) {
            return false;
        }

        cnt.erase(pointMinMin);
        cnt.erase(pointMinMax);
        cnt.erase(pointMaxMin);
        cnt.erase(pointMaxMax);

        for (auto & entry : cnt) {
            int value = entry.second;
            if (value != 2 && value != 4) {
                return false;
            }
        }
        return true;
    }
};

// @lc code=end

// 瞎写扫描线 超时
class Solution1 {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        map<int, vector<tuple<int,int>>> mp; // 行对应编号
        int n = rectangles.size();
        // 统计每行信息
        for(int i=0; i<n; ++i){
            for(int j=rectangles[i][1]; j<rectangles[i][3]; ++j){
                mp[j].push_back(make_tuple(rectangles[i][0], rectangles[i][2]));
            }
        }
        // 对每行就行处理
        int s = 1e6,e=1e6;
        int st,et;
        int pre = -1e6;
        for(auto it=mp.begin(); it!=mp.end(); ++it){
            cout << it->first << endl;
            if(pre != -1e6 && it->first != pre+1){
                return false;
            }
            pre = it->first;
            vector<tuple<int,int>>& t = it->second;
            sort(t.begin(), t.end());
            int ps=1e6;
            int ss=1e6;
            for(auto T: t){
                st = get<0>(T);
                et = get<1>(T);
                // 判断是否有空隙 或者 重复
                if(ps!=1e6 && et!=ps){
                    return false;
                }
                ps = st;
                if(s == 1e6){
                    s = st;
                }
                if(ss == 1e6){
                    ss = st;
                }
            }
            if(e == 1e6){
                e = et;
            }
            // 判断开始结尾是否一致
            if(e != et || s != ss){
                return false;
            }
        }
        return true;
    }
};