/*
 * @lc app=leetcode.cn id=1380 lang=java
 *
 * [1380] 矩阵中的幸运数
 *
 * https://leetcode-cn.com/problems/lucky-numbers-in-a-matrix/description/
 *
 * algorithms
 * Easy (72.69%)
 * Likes:    91
 * Dislikes: 0
 * Total Accepted:    36.3K
 * Total Submissions: 47.2K
 * Testcase Example:  '[[3,7,8],[9,11,13],[15,16,17]]'
 *
 * 给你一个 m * n 的矩阵，矩阵中的数字 各不相同 。请你按 任意 顺序返回矩阵中的所有幸运数。
 *
 * 幸运数是指矩阵中满足同时下列两个条件的元素：
 *
 *
 * 在同一行的所有元素中最小
 * 在同一列的所有元素中最大
 *
 *
 *
 *
 * 示例 1：
 *
 * 输入：matrix = [[3,7,8],[9,11,13],[15,16,17]]
 * 输出：[15]
 * 解释：15 是唯一的幸运数，因为它是其所在行中的最小值，也是所在列中的最大值。
 *
 *
 * 示例 2：
 *
 * 输入：matrix = [[1,10,4,2],[9,3,8,7],[15,16,17,12]]
 * 输出：[12]
 * 解释：12 是唯一的幸运数，因为它是其所在行中的最小值，也是所在列中的最大值。
 *
 *
 * 示例 3：
 *
 * 输入：matrix = [[7,8],[1,2]]
 * 输出：[7]
 *
 *
 *
 *
 * 提示：
 *
 *
 * m == mat.length
 * n == mat[i].length
 * 1 <= n, m <= 50
 * 1 <= matrix[i][j] <= 10^5
 * 矩阵中的所有元素都是不同的
 *
 *
 */

// @lc code=start
class Solution {
    public List<Integer> luckyNumbers (int[][] matrix) {
        int w = matrix[0].length;
        int[] maxCol = new int[w];
        int n = matrix.length;
        int[] minRow = new int[n];
        for(int i=0; i<n; ++i){
            minRow[i] = 100000;
            for(int j=0; j<w; ++j){
                maxCol[j] = Math.max(maxCol[j], matrix[i][j]);
                minRow[i] = Math.min(minRow[i], matrix[i][j]);
            }
        }
        List<Integer> res = new ArrayList<>();
        for(int i=0; i<n; ++i){
            for(int j=0; j<w; ++j){
                if(maxCol[j] == minRow[i]){
                    res.add(maxCol[j]);
                }
            }
        }
        return res;
    }
}
// @lc code=end

