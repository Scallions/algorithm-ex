/*
 * @lc app=leetcode.cn id=423 lang=cpp
 *
 * [423] 从英文中重建数字
 *
 * https://leetcode-cn.com/problems/reconstruct-original-digits-from-english/description/
 *
 * algorithms
 * Medium (56.83%)
 * Likes:    87
 * Dislikes: 0
 * Total Accepted:    11.8K
 * Total Submissions: 20K
 * Testcase Example:  '"owoztneoer"'
 *
 * 给你一个字符串 s ，其中包含字母顺序打乱的用英文单词表示的若干数字（0-9）。按 升序 返回原始的数字。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "owoztneoer"
 * 输出："012"
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "fviefuro"
 * 输出："45"
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length <= 10^5
 * s[i] 为 ["e","g","f","i","h","o","n","s","r","u","t","w","v","x","z"]
 * 这些字符之一
 * s 保证是一个符合题目要求的字符串
 * 
 * 
 */
#include <bits/stdc++.h>
#include "struct.h"
using namespace std;
// @lc code=start
class Solution {
public:
    string originalDigits(string s) {
        vector<int> mp(26,0);
        for(auto c:s){
            ++mp[c-'a'];
        }
        vector<int> cnt(10,0);
        cnt[8] = mp['g'-'a'];
        cnt[0] = mp['z'-'a'];
        cnt[2] = mp['w'-'a'];
        cnt[4] = mp['u'-'a'];
        cnt[6] = mp['x'-'a'];
        cnt[3] = mp['h'-'a']-cnt[8];
        cnt[5] = mp['f'-'a'] - cnt[4];
        cnt[7] = mp['v'-'a']-cnt[5];
        cnt[1] = mp['o'-'a']-cnt[0]-cnt[2]-cnt[4];
        cnt[9] = mp['n'-'a']-cnt[1]-cnt[7];
        cnt[9] /= 2;
        string res;
        for(int i=0;i<10;++i){
            string t(cnt[i], '0'+i);
            res += t;
        }
        return res;
    }
};

/*
zero
one
two
three
four
five
six
seven
eight
nine

e:0,1,3,5,7,8,9
g:8
f:4,5
i:5,6,8,9
h:3,8
o:0,1,2,4
n:1,7,9
s:6,7
r:0,3,4
u:4
v:5,7
t:2,3,8
w:2
x:6
z:0

0->z
2->w
4->u
6->x
8->g
3->h-8
5->f-4
7->v-5
1->o-0-2-4
9->n-1-7
*/
// @lc code=end

