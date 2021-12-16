/*
 * @lc app=leetcode.cn id=1034 lang=cpp
 *
 * [1034] 边框着色
 *
 * https://leetcode-cn.com/problems/coloring-a-border/description/
 *
 * algorithms
 * Medium (43.58%)
 * Likes:    47
 * Dislikes: 0
 * Total Accepted:    7.1K
 * Total Submissions: 14.6K
 * Testcase Example:  '[[1,1],[1,2]]\n0\n0\n3'
 *
 * 给你一个大小为 m x n 的整数矩阵 grid ，表示一个网格。另给你三个整数 row、col
 * 和 color 。网格中的每个值表示该位置处的网格块的颜色。
 *
 * 当两个网格块的颜色相同，而且在四个方向中任意一个方向上相邻时，它们属于同一
 * 连通分量 。
 *
 * 连通分量的边界
 * 是指连通分量中的所有与不在分量中的网格块相邻（四个方向上）的所有网格块，或者在网格的边界上（第一行/列或最后一行/列）的所有网格块。
 *
 * 请你使用指定颜色 color 为所有包含网格块 grid[row][col] 的 连通分量的边界
 * 进行着色，并返回最终的网格 grid 。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：grid = [[1,1],[1,2]], row = 0, col = 0, color = 3
 * 输出：[[3,3],[3,2]]
 *
 * 示例 2：
 *
 *
 * 输入：grid = [[1,2,2],[2,3,2]], row = 0, col = 1, color = 3
 * 输出：[[1,3,3],[2,3,3]]
 *
 * 示例 3：
 *
 *
 * 输入：grid = [[1,1,1],[1,1,1],[1,1,1]], row = 1, col = 1, color = 2
 * 输出：[[2,2,2],[2,1,2],[2,2,2]]
 *
 *
 *
 * 提示：
 *
 *
 * m == grid.length
 * n == grid[i].length
 * 1 <= m, n <= 50
 * 1 <= grid[i][j], color <= 1000
 * 0 <= row < m
 * 0 <= col < n
 *
 *
 *
 *
 */
#include "struct.h"
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
  vector<vector<int>> colorBorder(vector<vector<int>> &grid, int row, int col,
                                  int color) {
    int n = grid.size();
    int m = grid[0].size();
    queue<pair<int, int>> q;
    vector<pair<int, int>> dd{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int c = grid[row][col];
    unordered_set<int> vis;
    q.push(make_pair(row, col));
    bool flag;
    while (!q.empty()) {
      auto [x, y] = q.front();
      q.pop();
      flag = false;
      for (auto [dx, dy] : dd) {
        if (x + dx < 0 || x + dx >= n || y + dy < 0 || y + dy >= m) {
          flag = true;
          continue;
        }
        if (vis.find((x + dx) * m + (y + dy)) != vis.end())
          continue;
        if (grid[x + dx][y + dy] == c) {
          q.push(make_pair(x + dx, y + dy));
        } else {
          flag = true;
        }
      }
      if (flag) {
        grid[x][y] = color;
      }
      vis.insert(x * m + y);
    }
    return grid;
  }
};
// @lc code=end
