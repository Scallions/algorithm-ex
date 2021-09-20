/*
 * @lc app=leetcode.cn id=673 lang=cpp
 *
 * [673] 最长递增子序列的个数
 *
 * https://leetcode-cn.com/problems/number-of-longest-increasing-subsequence/description/
 *
 * algorithms
 * Medium (39.19%)
 * Likes:    411
 * Dislikes: 0
 * Total Accepted:    32.9K
 * Total Submissions: 81.3K
 * Testcase Example:  '[1,3,5,4,7]'
 *
 * 给定一个未排序的整数数组，找到最长递增子序列的个数。
 * 
 * 示例 1:
 * 
 * 
 * 输入: [1,3,5,4,7]
 * 输出: 2
 * 解释: 有两个最长递增子序列，分别是 [1, 3, 4, 7] 和[1, 3, 5, 7]。
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: [2,2,2,2,2]
 * 输出: 5
 * 解释: 最长递增子序列的长度是1，并且存在5个子序列的长度为1，因此输出5。
 * 
 * 
 * 注意: 给定的数组长度不超过 2000 并且结果一定是32位有符号整数。
 * 
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int m=0;
        int mc=0;
        int n = nums.size();
        vector<int> d(n, 1); // 长度
        vector<int> dc(n, 1); // 个数
        for(int i=0; i<n; ++i){
            for(int j=0; j<i; ++j){
                if(nums[i] > nums[j]){
                    if(d[j]+1 > d[i]){
                        // update
                        d[i] = d[j]+1;
                        dc[i] = dc[j];
                        continue;
                    }
                    if(d[j]+1 == d[i]){
                        dc[i] += dc[j];
                    }
                }
            }
            if(d[i]>m){
                m = d[i];
                mc = dc[i];
                continue;
            }
            if(d[i] == m){
                mc += dc[i];
            }
        }
        return mc;
    }
};
// @lc code=end

