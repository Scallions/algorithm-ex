/*
 * @lc app=leetcode.cn id=470 lang=cpp
 *
 * [470] 用 Rand7() 实现 Rand10()
 *
 * https://leetcode-cn.com/problems/implement-rand10-using-rand7/description/
 *
 * algorithms
 * Medium (55.61%)
 * Likes:    250
 * Dislikes: 0
 * Total Accepted:    39.1K
 * Total Submissions: 70.9K
 * Testcase Example:  '1'
 *
 * 已有方法 rand7 可生成 1 到 7 范围内的均匀随机整数，试写一个方法 rand10 生成 1 到 10 范围内的均匀随机整数。
 * 
 * 不要使用系统的 Math.random() 方法。
 * 
 * 
 * 
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: 1
 * 输出: [7]
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: 2
 * 输出: [8,4]
 * 
 * 
 * 示例 3:
 * 
 * 
 * 输入: 3
 * 输出: [8,1,10]
 * 
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * rand7 已定义。
 * 传入参数: n 表示 rand10 的调用次数。
 * 
 * 
 * 
 * 
 * 进阶:
 * 
 * 
 * rand7()调用次数的 期望值 是多少 ?
 * 你能否尽量少调用 rand7() ?
 * 
 * 
 */

// @lc code=start
// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        int t=4;
        while(t==4){
            t = rand7();
        }
        int m = 7;
        while(m>5){
            m = rand7();
        }
        return m + (t>4?5:0);
        
    }
};
// @lc code=end

