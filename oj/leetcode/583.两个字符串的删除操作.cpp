/*
 * @lc app=leetcode.cn id=583 lang=cpp
 *
 * [583] 两个字符串的删除操作
 *
 * https://leetcode-cn.com/problems/delete-operation-for-two-strings/description/
 *
 * algorithms
 * Medium (58.67%)
 * Likes:    274
 * Dislikes: 0
 * Total Accepted:    39.4K
 * Total Submissions: 64.9K
 * Testcase Example:  '"sea"\n"eat"'
 *
 * 给定两个单词 word1 和 word2，找到使得 word1 和 word2 相同所需的最小步数，每步可以删除任意一个字符串中的一个字符。
 * 
 * 
 * 
 * 示例：
 * 
 * 输入: "sea", "eat"
 * 输出: 2
 * 解释: 第一步将"sea"变为"ea"，第二步将"eat"变为"ea"
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 给定单词的长度不超过500。
 * 给定单词中的字符只含有小写字母。
 * 
 * 
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> d(n, vector<int>(m, 0));
        int l;
        int u;
        int lu;
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                if(j-1<0) l = 0;
                else l = d[i][j-1];
                if(i-1<0) u = 0;
                else u = d[i-1][j];
                if(i-1<0 || j-1<0) lu = 0;
                else lu = d[i-1][j-1];
                if(word1[i] == word2[j]) ++lu;
                d[i][j] = max(l, max(u, lu));
            }
        }
        return n+m-2*d[n-1][m-1];
    }
};
// @lc code=end

