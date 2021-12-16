/*
 * @lc app=leetcode.cn id=1314 lang=cpp
 *
 * [1314] 矩阵区域和
 *
 * https://leetcode-cn.com/problems/matrix-block-sum/description/
 *
 * algorithms
 * Medium (74.34%)
 * Likes:    116
 * Dislikes: 0
 * Total Accepted:    13.2K
 * Total Submissions: 17.7K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]\n1'
 *
 * 给你一个 m x n 的矩阵 mat 和一个整数 k ，请你返回一个矩阵 answer ，其中每个 answer[i][j] 是所有满足下述条件的元素
 * mat[r][c] 的和： 
 *
 *
 * i - k
 * j - k  且
 * (r, c) 在矩阵内。
 *
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：mat = [[1,2,3],[4,5,6],[7,8,9]], k = 1
 * 输出：[[12,21,16],[27,45,33],[24,39,28]]
 *
 *
 * 示例 2：
 *
 *
 * 输入：mat = [[1,2,3],[4,5,6],[7,8,9]], k = 2
 * 输出：[[45,45,45],[45,45,45],[45,45,45]]
 *
 *
 *
 *
 * 提示：
 *
 *
 * m == mat.length
 * n == mat[i].length
 * 1
 * 1
 *
 *
 */
#include <bits/stdc++.h>
#include "struct.h"
using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> res(m, vector<int>(n, 0));
        // compute pre sum
        for(int i=1; i<n; ++i) {
            mat[0][i] += mat[0][i-1];
        }
        for(int i=1; i<m; ++i) {
            mat[i][0] += mat[i-1][0];
            for(int j=1; j<n; ++j) {
                mat[i][j] += mat[i-1][j] + mat[i][j-1] - mat[i-1][j-1];
            }
        }
        int l;
        int t;
        int r;
        int b;
        int lt;
        int rt;
        int lb;
        int rb;
        for(int i=0; i<m; ++i) {
            for(int j=0; j<n; ++j) {
                l = max(0, j-k);
                t = max(0, i-k);
                r = min(n-1, j+k);
                b = min(m-1, i+k);
                rb = mat[b][r];
                if(l == 0) {
                    lt = 0;
                    lb = 0;
                    if( t== 0) {
                        rt = 0;
                    } else {
                        rt = mat[t-1][r];
                    }
                } else {
                    if(t == 0) {
                        lt = 0;
                        rt = 0;
                        lb = mat[b][l-1];
                    } else {
                        rt = mat[t-1][r];
                        lb = mat[b][l-1];
                        lt = mat[t-1][l-1];
                    }
                }
                res[i][j] = rb - lb - rt + lt;
            }
        }
        return res;
    }
};
// @lc code=end

