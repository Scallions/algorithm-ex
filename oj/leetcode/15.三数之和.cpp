/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 *
 * https://leetcode-cn.com/problems/3sum/description/
 *
 * algorithms
 * Medium (33.22%)
 * Likes:    3680
 * Dislikes: 0
 * Total Accepted:    620.5K
 * Total Submissions: 1.9M
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * 给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有和为 0
 * 且不重复的三元组。
 * 
 * 注意：答案中不可以包含重复的三元组。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [-1,0,1,2,-1,-4]
 * 输出：[[-1,-1,2],[-1,0,1]]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = []
 * 输出：[]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums = [0]
 * 输出：[]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 
 * -10^5 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int l,r;
        for(int i=0; i<n; ++i){
            if(i>0 && nums[i] == nums[i-1]) continue; // 跳过重复
            l = i+1;
            r = n-1;
            while(l<r){
                if(nums[l]+nums[r]==-nums[i]){
                    res.push_back(vector<int>{nums[i], nums[l], nums[r]});
                    if(nums[l]==nums[r]) break;
                    while(l<r&&nums[l]==nums[l+1]){
                        ++l;
                    }
                    ++l;
                }
                if(nums[l]+nums[r] > -nums[i]){
                    --r;
                }else{
                    ++l;
                }
            }
        }
        return res;
    }
};
// @lc code=end

// 注意数组越界问题