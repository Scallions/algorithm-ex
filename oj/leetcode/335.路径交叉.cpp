/*
 * @lc app=leetcode.cn id=335 lang=cpp
 *
 * [335] 路径交叉
 *
 * https://leetcode-cn.com/problems/self-crossing/description/
 *
 * algorithms
 * Hard (37.34%)
 * Likes:    75
 * Dislikes: 0
 * Total Accepted:    4.4K
 * Total Submissions: 10.9K
 * Testcase Example:  '[2,1,1,2]'
 *
 * 给你一个整数数组 distance 。
 * 
 * 从 X-Y 平面上的点 (0,0) 开始，先向北移动 distance[0] 米，然后向西移动 distance[1] 米，向南移动
 * distance[2] 米，向东移动 distance[3] 米，持续移动。也就是说，每次移动后你的方位会发生逆时针变化。
 * 
 * 判断你所经过的路径是否相交。如果相交，返回 true ；否则，返回 false 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：distance = [2,1,1,2]
 * 输出：true
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：distance = [1,2,3,4]
 * 输出：false
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：distance = [1,1,1,1]
 * 输出：true
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= distance.length <= 10^5
 * 1 <= distance[i] <= 10^5
 * 
 * 
 */
#include <bits/stdc++.h>
#include "struct.h"
using namespace std;
// @lc code=start
class Solution {
public:
    bool isSelfCrossing(vector<int>& distance) {
        int n = distance.size();
        if(n<4)return false;
        for(int i=3;i<n;++i){
            // pre 3
            if(distance[i]>=distance[i-2] && distance[i-1]<=distance[i-3]){
                return true;
            }
            // pre 4
            if(i>3 && distance[i-1]==distance[i-3] && distance[i-4]+distance[i]>=distance[i-2]) return true;
            // pre 5
            if(i>4 && distance[i-4]<=distance[i-2]&& distance[i]+distance[i-4]>=distance[i-2] && distance[i-1]<=distance[i-3] && distance[i-1]+distance[i-5]-distance[i-3]>=0){
                return true;
            }
        }
        return false;
    }
};
// @lc code=end

// 分别判断当前线段与之前第三条、第四条、第五条是否相交