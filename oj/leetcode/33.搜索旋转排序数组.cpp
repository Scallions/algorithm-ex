/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 *
 * https://leetcode-cn.com/problems/search-in-rotated-sorted-array/description/
 *
 * algorithms
 * Medium (42.51%)
 * Likes:    1536
 * Dislikes: 0
 * Total Accepted:    343.7K
 * Total Submissions: 807.8K
 * Testcase Example:  '[4,5,6,7,0,1,2]\n0'
 *
 * 整数数组 nums 按升序排列，数组中的值 互不相同 。
 *
 * 在传递给函数之前，nums 在预先未知的某个下标 k（0 ）上进行了 旋转，使数组变为 [nums[k], nums[k+1], ...,
 * nums[n-1], nums[0], nums[1], ..., nums[k-1]]（下标 从 0 开始 计数）。例如，
 * [0,1,2,4,5,6,7] 在下标 3 处经旋转后可能变为 [4,5,6,7,0,1,2] 。
 *
 * 给你 旋转后 的数组 nums 和一个整数 target ，如果 nums 中存在这个目标值 target ，则返回它的下标，否则返回 -1 。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [4,5,6,7,0,1,2], target = 0
 * 输出：4
 *
 *
 * 示例 2：
 *
 *
 * 输入：nums = [4,5,6,7,0,1,2], target = 3
 * 输出：-1
 *
 * 示例 3：
 *
 *
 * 输入：nums = [1], target = 0
 * 输出：-1
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1
 * -10^4
 * nums 中的每个值都 独一无二
 * 题目数据保证 nums 在预先未知的某个下标上进行了旋转
 * -10^4
 *
 *
 *
 *
 * 进阶：你可以设计一个时间复杂度为 O(log n) 的解决方案吗？
 *
 */
#include <bits/stdc++.h>
#include "struct.h"
using namespace std;
// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        // 升序排列， 互不相同， 进行过旋转（任意位置）
        // 判断target 是否存在

        // 候选算法 暴力遍历， 二分， 数组= =

        // 1
        // int n = nums.size();
        // for(int i=0; i<n; ++i){
        //     if(nums[i] == target) return i;
        // }
        // return -1;

        // 2 split
        // 可以先二分找到旋转位置，再查找
        // int n = nums.size();
        // if(n==1){
        //     return nums[0]==target?0:-1;
        // }
        // int l = 0;
        // int r = n-2;
        // int m=-1;
        // while(l<=r){
        //     m = l + (r-l)/2;
        //     if(nums[m]==target) return m;
        //     if(nums[m]>nums[m+1]) break;
        //     if(nums[m]>=nums[l]){
        //         l = m+1;
        //     }else{
        //         r = m-1;
        //     }
        // }
        // if(m!=-1&&nums[m]<nums[m+1]){
        //     m=-1;
        // }
        // // find
        // if(m!=-1&&(target>nums[m]||target<nums[m+1])) return -1;
        // if(m!=-1){
        //     if(target>=nums[0]){
        //         l = 0;
        //         r = m;
        //     }else{
        //         l = m+1;
        //         r = n-1;
        //     }
        // } else{
        //     l = 0;
        //     r = n-1;
        // }
        // while(l<=r){
        //     m = l + (r-l)/2;
        //     if(nums[m] == target) return m;
        //     if(nums[m]<target){
        //         l=m+1;
        //     }else{
        //         r=m-1;
        //     }
        // }
        // return -1;

        // 参考2分
        int n = (int)nums.size();
        if (!n) {
            return -1;
        }
        if (n == 1) {
            return nums[0] == target ? 0 : -1;
        }
        int l = 0, r = n - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] == target) return mid;
            if (nums[0] <= nums[mid]) {
                if (nums[0] <= target && target < nums[mid]) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            } else {
                if (nums[mid] < target && target <= nums[n - 1]) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
        }
        return -1;
    }
};
// @lc code=end

