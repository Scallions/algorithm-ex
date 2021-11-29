/*
 * @lc app=leetcode.cn id=413 lang=cpp
 *
 * [413] 等差数列划分
 *
 * https://leetcode-cn.com/problems/arithmetic-slices/description/
 *
 * algorithms
 * Medium (68.85%)
 * Likes:    382
 * Dislikes: 0
 * Total Accepted:    77K
 * Total Submissions: 111.7K
 * Testcase Example:  '[1,2,3,4]'
 *
 * 如果一个数列 至少有三个元素 ，并且任意两个相邻元素之差相同，则称该数列为等差数列。
 * 
 * 
 * 例如，[1,3,5,7,9]、[7,7,7,7] 和 [3,-1,-5,-9] 都是等差数列。
 * 
 * 
 * 
 * 
 * 给你一个整数数组 nums ，返回数组 nums 中所有为等差数组的 子数组 个数。
 * 
 * 子数组 是数组中的一个连续序列。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,2,3,4]
 * 输出：3
 * 解释：nums 中有三个子等差数组：[1, 2, 3]、[2, 3, 4] 和 [1,2,3,4] 自身。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [1]
 * 输出：0
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * -1000 
 * 
 * 
 * 
 * 
 */
#include <bits/stdc++.h>
#include "struct.h"
using namespace std;
// @lc code=start
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int res = 0;
        int n = nums.size();
        if(n<3) return res;
        int l = 0;
        int ld = 0;
        ld = nums[1]-nums[0];
        for(int i=2; i<n; ++i){
            if(nums[i]-nums[i-1] != ld){
                if(i-l > 2){
                    res += (i-l-1)*(i-l-2)/2;
                }
                l = i-1;
                ld = nums[i]-nums[i-1];
            }
        }
        if(n-l > 2){
            res += (n-l-1)*(n-l-2)/2;
        }
        return res;
    }
};
// @lc code=end

