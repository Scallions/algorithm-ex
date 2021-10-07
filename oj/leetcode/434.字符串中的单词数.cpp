/*
 * @lc app=leetcode.cn id=434 lang=cpp
 *
 * [434] 字符串中的单词数
 *
 * https://leetcode-cn.com/problems/number-of-segments-in-a-string/description/
 *
 * algorithms
 * Easy (37.40%)
 * Likes:    107
 * Dislikes: 0
 * Total Accepted:    41.4K
 * Total Submissions: 108.9K
 * Testcase Example:  '"Hello, my name is John"'
 *
 * 统计字符串中的单词个数，这里的单词指的是连续的不是空格的字符。
 * 
 * 请注意，你可以假定字符串里不包括任何不可打印的字符。
 * 
 * 示例:
 * 
 * 输入: "Hello, my name is John"
 * 输出: 5
 * 解释: 这里的单词是指连续的不是空格的字符，所以 "Hello," 算作 1 个单词。
 * 
 * 
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int countSegments(string s) {
        int c1 = 0;
        s = " " + s +" ";
        for(int i=1; i<s.size(); ++i){
            if(s[i-1] == ' ' && s[i] != ' '){
                ++c1;
            }
        }
        return c1;
    }
};
// @lc code=end

