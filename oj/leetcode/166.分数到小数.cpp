/*
 * @lc app=leetcode.cn id=166 lang=cpp
 *
 * [166] 分数到小数
 *
 * https://leetcode-cn.com/problems/fraction-to-recurring-decimal/description/
 *
 * algorithms
 * Medium (29.86%)
 * Likes:    270
 * Dislikes: 0
 * Total Accepted:    28K
 * Total Submissions: 92.4K
 * Testcase Example:  '1\n2'
 *
 * 给定两个整数，分别表示分数的分子 numerator 和分母 denominator，以 字符串形式返回小数 。
 * 
 * 如果小数部分为循环小数，则将循环的部分括在括号内。
 * 
 * 如果存在多个答案，只需返回 任意一个 。
 * 
 * 对于所有给定的输入，保证 答案字符串的长度小于 10^4 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：numerator = 1, denominator = 2
 * 输出："0.5"
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：numerator = 2, denominator = 1
 * 输出："2"
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：numerator = 2, denominator = 3
 * 输出："0.(6)"
 * 
 * 
 * 示例 4：
 * 
 * 
 * 输入：numerator = 4, denominator = 333
 * 输出："0.(012)"
 * 
 * 
 * 示例 5：
 * 
 * 
 * 输入：numerator = 1, denominator = 5
 * 输出："0.2"
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * -2^31 
 * denominator != 0
 * 
 * 
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        string res = "";
        // 判断符号
        if((numerator>0&&denominator<0) || (numerator<0&&denominator>0)) res = '-';
        long long num = abs(numerator);
        long long den = abs(denominator);
        num *= 10;
        den *= 10;
        if(num>den){
            res += to_string(num/den);
            num -= (num/den) * den;
        }else{
            res += "0";
        }
        if(num!=0) res += ".";
        map<int,int> mm;
        vector<int> dd;
        int i = 0;
        int t;
        while(num!=0){
            if(mm.find(num) != mm.end()) break;
            mm[num] = i;
            // cout << num << "," << den << endl;
            t = num*10/den;
            num *= 10;
            num -= t*den;
            dd.push_back(t);
            ++i;
        }
        if(num == 0){
            for(auto d: dd){
                res += char('0'+d);
            }
        }else{
            t = mm[num];
            for(int i=0;i<t; ++i){
                res += char('0'+dd[i]);
            }
            res += '(';
            for(int i=t;i<dd.size(); ++i){
                res += char('0'+dd[i]);
            }
            res += ')';
        }
        return res;
    }
};
// @lc code=end

