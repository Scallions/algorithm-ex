/*
 * @lc app=leetcode.cn id=118 lang=cpp
 *
 * [118] 杨辉三角
 *
 * https://leetcode-cn.com/problems/pascals-triangle/description/
 *
 * algorithms
 * Easy (73.37%)
 * Likes:    638
 * Dislikes: 0
 * Total Accepted:    236.4K
 * Total Submissions: 321.5K
 * Testcase Example:  '5'
 *
 * 给定一个非负整数 numRows，生成「杨辉三角」的前 numRows 行。
 * 
 * 在「杨辉三角」中，每个数是它左上方和右上方的数的和。
 * 
 * 
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: numRows = 5
 * 输出: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: numRows = 1
 * 输出: [[1]]
 * 
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 1 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> rows;
        vector<int> row{1};
        rows.push_back(row);
        for(int i=1;i<numRows;++i){
            row.push_back(1);
            for(int j=0;j<i-1;++j){
                row[i-j-1] += row[i-j-2]; 
            }
            rows.push_back(row);
        }
        return rows;
    }
};
// @lc code=end

