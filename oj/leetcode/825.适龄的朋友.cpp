/*
 * @lc app=leetcode.cn id=825 lang=cpp
 *
 * [825] 适龄的朋友
 *
 * https://leetcode-cn.com/problems/friends-of-appropriate-ages/description/
 *
 * algorithms
 * Medium (39.39%)
 * Likes:    105
 * Dislikes: 0
 * Total Accepted:    12.8K
 * Total Submissions: 29.9K
 * Testcase Example:  '[16,16]'
 *
 * 在社交媒体网站上有 n 个用户。给你一个整数数组 ages ，其中 ages[i] 是第 i 个用户的年龄。
 * 
 * 如果下述任意一个条件为真，那么用户 x 将不会向用户 y（x != y）发送好友请求：
 * 
 * 
 * age[y] <= 0.5 * age[x] + 7
 * age[y] > age[x]
 * age[y] > 100 && age[x] < 100
 * 
 * 
 * 否则，x 将会向 y 发送一条好友请求。
 * 
 * 注意，如果 x 向 y 发送一条好友请求，y 不必也向 x 发送一条好友请求。另外，用户不会向自己发送好友请求。
 * 
 * 返回在该社交媒体网站上产生的好友请求总数。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：ages = [16,16]
 * 输出：2
 * 解释：2 人互发好友请求。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：ages = [16,17,18]
 * 输出：2
 * 解释：产生的好友请求为 17 -> 16 ，18 -> 17 。
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：ages = [20,30,100,110,120]
 * 输出：3
 * 解释：产生的好友请求为 110 -> 100 ，120 -> 110 ，120 -> 100 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * n == ages.length
 * 1 <= n <= 2 * 10^4
 * 1 <= ages[i] <= 120
 * 
 * 
 */
#include <bits/stdc++.h>
#include "struct.h"
using namespace std;
// @lc code=start
class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        vector<int> cnt(121,0);
        for(auto age: ages){
            ++cnt[age];
        }
        int res = 0;
        for(int i=1; i<121; ++i){
            if(cnt[i]==0)continue;
            int j = 0.5*i+8;
            if(j>i)continue;
            for(; j<i; ++j){
                if(cnt[j]==0)continue;
                res += cnt[i]*cnt[j];       
            }
            res += cnt[i]*cnt[i]-cnt[i];
        }
        return res;
    }
};
// @lc code=end

// 官方题解进一步优化计算，采用的是前缀和
class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        vector<int> cnt(121);
        for (int age: ages) {
            ++cnt[age];
        }
        vector<int> pre(121);
        for (int i = 1; i <= 120; ++i) {
            pre[i] = pre[i - 1] + cnt[i];
        }
        int ans = 0;
        for (int i = 15; i <= 120; ++i) {
            if (cnt[i]) {
                int bound = i * 0.5 + 8;
                ans += cnt[i] * (pre[i] - pre[bound - 1] - 1);
            }
        }
        return ans;
    }
};