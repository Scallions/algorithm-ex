/*
 * @lc app=leetcode.cn id=372 lang=cpp
 *
 * [372] 超级次方
 *
 * https://leetcode-cn.com/problems/super-pow/description/
 *
 * algorithms
 * Medium (51.10%)
 * Likes:    196
 * Dislikes: 0
 * Total Accepted:    24.6K
 * Total Submissions: 44.6K
 * Testcase Example:  '2\n[3]'
 *
 * 你的任务是计算 a^b 对 1337 取模，a 是一个正整数，b 是一个非常大的正整数且会以数组形式给出。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：a = 2, b = [3]
 * 输出：8
 *
 *
 * 示例 2：
 *
 *
 * 输入：a = 2, b = [1,0]
 * 输出：1024
 *
 *
 * 示例 3：
 *
 *
 * 输入：a = 1, b = [4,3,3,8,5,2]
 * 输出：1
 *
 *
 * 示例 4：
 *
 *
 * 输入：a = 2147483647, b = [2,0,0]
 * 输出：1198
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1
 * 1
 * 0
 * b 不含前导 0
 *
 *
 */
#include <bits/stdc++.h>
#include "struct.h"
using namespace std;
// @lc code=start
class Solution {
public:
    int superPow(int a, vector<int>& b) {
        vector<int> vis(1337);
        vector<int> dd;
        a %= 1337;
        if(a==0) return 0;
        int t=a;
        while(vis[t]==0) {
            // cout<<t<<endl;
            vis[t]=1;
            dd.push_back(t);
            t *= a;
            t %= 1337;
        }
        int n = b.size();
        int dl = dd.size();
        int c=-1;
        int cl=1;
        for(int i=n-1; i>-1; --i) {
            c += b[i]*cl;
            c %= dl;
            //next
            cl *= 10;
            cl %= dl;
        }
        return dd[c];
    }
};
// @lc code=end

