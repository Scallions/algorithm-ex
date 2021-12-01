/*
 * @lc app=leetcode.cn id=931 lang=cpp
 *
 * [931] 下降路径最小和
 *
 * https://leetcode-cn.com/problems/minimum-falling-path-sum/description/
 *
 * algorithms
 * Medium (66.83%)
 * Likes:    131
 * Dislikes: 0
 * Total Accepted:    24.4K
 * Total Submissions: 36.4K
 * Testcase Example:  '[[2,1,3],[6,5,4],[7,8,9]]'
 *
 * 给你一个 n x n 的 方形 整数数组 matrix ，请你找出并返回通过 matrix 的下降路径 的 最小和 。
 * 
 * 下降路径
 * 可以从第一行中的任何元素开始，并从每一行中选择一个元素。在下一行选择的元素和当前行所选元素最多相隔一列（即位于正下方或者沿对角线向左或者向右的第一个元素）。具体来说，位置
 * (row, col) 的下一个元素应当是 (row + 1, col - 1)、(row + 1, col) 或者 (row + 1, col + 1)
 * 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：matrix = [[2,1,3],[6,5,4],[7,8,9]]
 * 输出：13
 * 解释：下面是两条和最小的下降路径，用加粗+斜体标注：
 * [[2,1,3],      [[2,1,3],
 * ⁠[6,5,4],       [6,5,4],
 * ⁠[7,8,9]]       [7,8,9]]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：matrix = [[-19,57],[-40,-5]]
 * 输出：-59
 * 解释：下面是一条和最小的下降路径，用加粗+斜体标注：
 * [[-19,57],
 * ⁠[-40,-5]]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：matrix = [[-48]]
 * 输出：-48
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * n == matrix.length
 * n == matrix[i].length
 * 1 <= n <= 100
 * -100 <= matrix[i][j] <= 100
 * 
 * 
 */
#include <bits/stdc++.h>
#include "struct.h"
using namespace std;
// @lc code=start
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int t;
        int idx;
        for(int i=1; i<n; ++i){
            for(int j=0; j<n; ++j){
                t = INT_MAX;
                for(int k=-1;k<2;++k){
                    idx = j+k;
                    if(idx>-1&&idx<n){
                        t = min(matrix[i-1][idx], t);
                    }
                }
                matrix[i][j] += t;
            }
        }
        return *min_element(matrix[n-1].begin(), matrix[n-1].end());
    }
};
// @lc code=end

