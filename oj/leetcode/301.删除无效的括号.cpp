/*
 * @lc app=leetcode.cn id=301 lang=cpp
 *
 * [301] 删除无效的括号
 *
 * https://leetcode-cn.com/problems/remove-invalid-parentheses/description/
 *
 * algorithms
 * Hard (52.45%)
 * Likes:    532
 * Dislikes: 0
 * Total Accepted:    36.1K
 * Total Submissions: 68.1K
 * Testcase Example:  '"()())()"'
 *
 * 给你一个由若干括号和字母组成的字符串 s ，删除最小数量的无效括号，使得输入的字符串有效。
 * 
 * 返回所有可能的结果。答案可以按 任意顺序 返回。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "()())()"
 * 输出：["(())()","()()()"]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "(a)())()"
 * 输出：["(a())()","(a)()()"]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：s = ")("
 * 输出：[""]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * s 由小写英文字母以及括号 '(' 和 ')' 组成
 * s 中至多含 20 个括号
 * 
 * 
 */
#include <bits/stdc++.h>
#include "struct.h"
using namespace std;
// @lc code=start
class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        int l=0,r=0;
        for(auto c: s){
            if(c=='(') ++l;
            else if(c==')'){
                if(l>0) --l;
                else ++r;
            }
        }
        set<tuple<string, int, int>> q; // s, lr, rr set去重
        q.insert(tuple<string, int, int>{s, l, r});
        vector<string> res;
        int sl, lt, rt, lr, rr;
        while(!q.empty()){
            set<tuple<string, int, int>> qn;
            for(auto qc: q){
                tie(s, lr, rr) = qc;
                sl = s.size();
                lt = 0;rt=0;
                for(int i=0; i<sl; ++i){
                    if(s[i]=='('){
                        ++lt;
                        if(i>0 && s[i] == s[i-1]) continue; // 连续剪枝
                        if(lr>0) qn.insert(tuple<string, int, int>{s.substr(0, i) + s.substr(i + 1), lr-1, rr});
                    }
                    else if(s[i]==')'){
                        if(lt>0) --lt;
                        else ++rt;
                        if(i>0 && s[i] == s[i-1]) continue;
                        if(rr>0) qn.insert(tuple<string, int, int>{s.substr(0, i) + s.substr(i + 1), lr-1, rr});
                    }
                }
                if(lt == 0 && rt == 0) res.push_back(s);
            }
            if(res.size() != 0) return res;
            q = qn;
        }
        return {};
    }
};
// @lc code=end

/*
官方答案，值得学习的点，去重操作，求出删除个数，广搜改成深搜
*/
class Solution2 {
public:
    vector<string> ans;//此时不会重复搜索 无重复方案 直接存即可
    void dfs(string &s, int u, string res, int cnt, int l, int r){//cnt为当前左-右的值 l为需要删除的左括号数量 r为右
        //cout<<res<<endl;
        if(u==s.size()){
            if(!cnt) ans.push_back(res);
            return;
        }
        if(s[u]=='('){//在合法的条件下考虑删除 对于连续的k个'(' 只需考虑一次性 删 i个(0<=i<=k) 则可从2^k降到 k
            int k = u;
            while (k < s.size() && s[k] == '(') k ++;//找到最后一个连续的'('的右边
            l -= k - u;//假设将这些连续的'('全部删除
            for (int i = k - u; i >= 0; i -- ) {//i为删除后的位置
                if (l >= 0) dfs(s, k, res, cnt, l, r);//可删时
                res += '(', cnt ++, l ++ ;
            }
        }
        else if(s[u]==')'){//在合法的条件下考虑删除
            int k = u;
            while (k < s.size() && s[k] == ')') k ++;//找到最后一个连续的'('的右边
            r -= k - u;//假设将这些连续的'('全部删除
            for (int i = k - u; i >= 0; i -- ) {//i为删除后的位置
                if (cnt >= 0 && r >= 0) dfs(s, k, res, cnt, l, r);//可删时
                res += ')', cnt--, r++;
            }
        }
        else dfs(s,u+1,res + s[u],cnt,l,r);
    }
    vector<string> removeInvalidParentheses(string s) {
        int l = 0, r = 0;//l为当前左括号-右括号的值 r为需要删掉的右括号的值
        for(auto v : s){
            if(v=='(') l++;
            else if(v==')'){
                if(l <= 0) r++;//此时无效 右括号 必删
                else l--;//右括号+1 则左-右的值需要--   
            }  
        }
        //此时的l为需要删除的左括号数量 r为需要删除的右括号数量
        dfs(s,0,"",0,l,r);
        return ans;
    }
};