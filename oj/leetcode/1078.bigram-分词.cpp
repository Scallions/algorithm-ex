/*
 * @lc app=leetcode.cn id=1078 lang=cpp
 *
 * [1078] Bigram 分词
 *
 * https://leetcode-cn.com/problems/occurrences-after-bigram/description/
 *
 * algorithms
 * Easy (62.14%)
 * Likes:    62
 * Dislikes: 0
 * Total Accepted:    28K
 * Total Submissions: 42.8K
 * Testcase Example:  '"alice is a good girl she is a good student"\n"a"\n"good"'
 *
 * 给出第一个词 first 和第二个词 second，考虑在某些文本 text 中可能以 "first second third" 形式出现的情况，其中
 * second 紧随 first 出现，third 紧随 second 出现。
 * 
 * 对于每种这样的情况，将第三个词 "third" 添加到答案中，并返回答案。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：text = "alice is a good girl she is a good student", first = "a", second
 * = "good"
 * 输出：["girl","student"]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：text = "we will we will rock you", first = "we", second = "will"
 * 输出：["we","rock"]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= text.length <= 1000
 * text 由小写英文字母和空格组成
 * text 中的所有单词之间都由 单个空格字符 分隔
 * 1 <= first.length, second.length <= 10
 * first 和 second 由小写英文字母组成
 * 
 * 
 */
#include <bits/stdc++.h>
#include "struct.h"
using namespace std;
// @lc code=start
class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        vector<string> res;
        string p1, p2, c;
        int p = 0;
        int n = text.size();
        for(int i=0; i<n; ++i){
            if(text[i] == ' '){
                c = text.substr(p, i-p);
                if(p1==first && p2 == second){
                    res.push_back(c);
                }
                p1 = p2;
                p2 = c;
                p = i+1;
            }
        }
        if(p<n){
            c = text.substr(p, n-p);
            if(p1==first && p2 == second){
                res.push_back(c);
            }
        }
        return res;
    }
};
// @lc code=end

