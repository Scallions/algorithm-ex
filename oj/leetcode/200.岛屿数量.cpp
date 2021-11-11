/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 *
 * https://leetcode-cn.com/problems/number-of-islands/description/
 *
 * algorithms
 * Medium (55.87%)
 * Likes:    1403
 * Dislikes: 0
 * Total Accepted:    349.3K
 * Total Submissions: 623.4K
 * Testcase Example:  '[["1","1","1","1","0"],["1","1","0","1","0"],["1","1","0","0","0"],["0","0","0","0","0"]]'
 *
 * 给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。
 * 
 * 岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。
 * 
 * 此外，你可以假设该网格的四条边均被水包围。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：grid = [
 * ⁠ ["1","1","1","1","0"],
 * ⁠ ["1","1","0","1","0"],
 * ⁠ ["1","1","0","0","0"],
 * ⁠ ["0","0","0","0","0"]
 * ]
 * 输出：1
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：grid = [
 * ⁠ ["1","1","0","0","0"],
 * ⁠ ["1","1","0","0","0"],
 * ⁠ ["0","0","1","0","0"],
 * ⁠ ["0","0","0","1","1"]
 * ]
 * 输出：3
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * m == grid.length
 * n == grid[i].length
 * 1 
 * grid[i][j] 的值为 '0' 或 '1'
 * 
 * 
 */
#include <bits/stdc++.h>
#include "struct.h"
using namespace std;
// @lc code=start
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                if(grid[i][j] == '1'){
                    ++cnt;
                    dfs(grid, i, j);
                }
            }
        }
        return cnt;
    }
private:
    vector<int> dxx{1,-1,0,0}; // 移到外面减少不必要的初始化
    vector<int> dyy{0,0,1,-1};
    void dfs(vector<vector<char>>& grid, int x, int y){
        int n = grid.size();
        int m = grid[0].size();
        grid[x][y] = '0';
        for(int i=0; i<4; ++i){
            int nx = x + dxx[i]; // 先计算避免判断的时候多次计算
            int ny = y + dyy[i];
            if(nx >=0 && nx < n && ny >=0 && ny < m && grid[nx][ny] == '1'){
                dfs(grid, nx, ny);
            }
        }
    }
};
// @lc code=end

