/*
 * @lc app=leetcode.cn id=500 lang=cpp
 *
 * [500] 键盘行
 *
 * https://leetcode-cn.com/problems/keyboard-row/description/
 *
 * algorithms
 * Easy (70.91%)
 * Likes:    186
 * Dislikes: 0
 * Total Accepted:    49.8K
 * Total Submissions: 66.9K
 * Testcase Example:  '["Hello","Alaska","Dad","Peace"]'
 *
 * 给你一个字符串数组 words ，只返回可以使用在 美式键盘 同一行的字母打印出来的单词。键盘如下图所示。
 * 
 * 美式键盘 中：
 * 
 * 
 * 第一行由字符 "qwertyuiop" 组成。
 * 第二行由字符 "asdfghjkl" 组成。
 * 第三行由字符 "zxcvbnm" 组成。
 * 
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：words = ["Hello","Alaska","Dad","Peace"]
 * 输出：["Alaska","Dad"]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：words = ["omk"]
 * 输出：[]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：words = ["adsdf","sfd"]
 * 输出：["adsdf","sfd"]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * 1 
 * words[i] 由英文字母（小写和大写字母）组成
 * 
 * 
 */
#include <bits/stdc++.h>
#include "struct.h"
using namespace std;
// @lc code=start
class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        map<char, int> mp;
        string line1 = "qwertyuiopQWERTYUIOP";
        string line2 = "asdfghjklASDFGHJKL";
        string line3 = "zxcvbnmZXCVBNM";
        for(auto c: line1){
            mp[c] = 1;
        }
        for(auto c: line2){
            mp[c] = 2;
        }
        for(auto c: line3){
            mp[c] = 3;
        }
        vector<string> res;
        int k;
        bool flag = true;
        for(auto word: words){
            k = mp[word[0]];
            flag =true;
            for(auto c: word){
                if(k!=mp[c]){
                    flag = false;
                    break;
                }
            }
            if(flag) res.push_back(word);
        }
        return res;
    }
};
// @lc code=end

