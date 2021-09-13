/*
 * @lc app=leetcode.cn id=447 lang=cpp
 *
 * [447] 回旋镖的数量
 *
 * https://leetcode-cn.com/problems/number-of-boomerangs/description/
 *
 * algorithms
 * Medium (61.89%)
 * Likes:    158
 * Dislikes: 0
 * Total Accepted:    24.3K
 * Total Submissions: 39.2K
 * Testcase Example:  '[[0,0],[1,0],[2,0]]'
 *
 * 给定平面上 n 对 互不相同 的点 points ，其中 points[i] = [xi, yi] 。回旋镖 是由点 (i, j, k) 表示的元组
 * ，其中 i 和 j 之间的距离和 i 和 k 之间的距离相等（需要考虑元组的顺序）。
 * 
 * 返回平面上所有回旋镖的数量。
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：points = [[0,0],[1,0],[2,0]]
 * 输出：2
 * 解释：两个回旋镖为 [[1,0],[0,0],[2,0]] 和 [[1,0],[2,0],[0,0]]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：points = [[1,1],[2,2],[3,3]]
 * 输出：2
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：points = [[1,1]]
 * 输出：0
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * n == points.length
 * 1 
 * points[i].length == 2
 * -10^4 i, yi 
 * 所有点都 互不相同
 * 
 * 
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int n = points.size();
        if(n<3) return 0;
        vector<vector<int>> dis(n, vector<int>(n,0));
        for(int i=0; i<n; ++i){
            for(int j=i+1;j<n;++j){
                dis[i][j] = (points[i][0]-points[j][0])*(points[i][0]-points[j][0]) + (points[i][1]-points[j][1])*(points[i][1]-points[j][1]);
                dis[j][i] = dis[i][j];
            }
        }
        int res = 0;
        for(int i=0; i<n; ++i){
            unordered_map<int,int> ps;
            for(int j=0; j<n; ++j){
                if(i==j) continue;
                if(ps.find(dis[i][j]) != ps.end()){
                    // 有相同距离点
                    res += (2*ps[dis[i][j]]);
                }
                ++ps[dis[i][j]];
            }
        }
        return res;
    }
};
// @lc code=end

