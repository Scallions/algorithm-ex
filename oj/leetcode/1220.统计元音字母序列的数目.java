/*
 * @lc app=leetcode.cn id=1220 lang=java
 *
 * [1220] 统计元音字母序列的数目
 *
 * https://leetcode-cn.com/problems/count-vowels-permutation/description/
 *
 * algorithms
 * Hard (53.37%)
 * Likes:    101
 * Dislikes: 0
 * Total Accepted:    15.5K
 * Total Submissions: 25.7K
 * Testcase Example:  '1'
 *
 * 给你一个整数 n，请你帮忙统计一下我们可以按下述规则形成多少个长度为 n 的字符串：
 * 
 * 
 * 字符串中的每个字符都应当是小写元音字母（'a', 'e', 'i', 'o', 'u'）
 * 每个元音 'a' 后面都只能跟着 'e'
 * 每个元音 'e' 后面只能跟着 'a' 或者是 'i'
 * 每个元音 'i' 后面 不能 再跟着另一个 'i'
 * 每个元音 'o' 后面只能跟着 'i' 或者是 'u'
 * 每个元音 'u' 后面只能跟着 'a'
 * 
 * 
 * 由于答案可能会很大，所以请你返回 模 10^9 + 7 之后的结果。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：n = 1
 * 输出：5
 * 解释：所有可能的字符串分别是："a", "e", "i" , "o" 和 "u"。
 * 
 * 
 * 示例 2：
 * 
 * 输入：n = 2
 * 输出：10
 * 解释：所有可能的字符串分别是："ae", "ea", "ei", "ia", "ie", "io", "iu", "oi", "ou" 和
 * "ua"。
 * 
 * 
 * 示例 3：
 * 
 * 输入：n = 5
 * 输出：68
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= n <= 2 * 10^4
 * 
 * 
 */

// @lc code=start
class Solution {
    public int countVowelPermutation(int n) {
        long[] cnt = {1,1,1,1,1};
        long c = 1000_000_007;
        for(int i=1; i<n; ++i){
            long[] tmp = new long[5];
            tmp[0] = cnt[1];
            tmp[1] = (cnt[0] + cnt[2])%c;
            tmp[2] = ((cnt[0] + cnt[1])%c + (cnt[3] + cnt[4])%c)%c;
            tmp[3] = (cnt[2] + cnt[4])%c;
            tmp[4] = cnt[0];
            cnt = tmp;
        }
        int res = 0;
        for(int i=0; i<5; ++i){
            res += cnt[i];
            res %= c;
        }
        return res;
    }
}
// @lc code=end

