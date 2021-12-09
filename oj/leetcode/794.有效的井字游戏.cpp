/*
 * @lc app=leetcode.cn id=794 lang=cpp
 *
 * [794] 有效的井字游戏
 *
 * https://leetcode-cn.com/problems/valid-tic-tac-toe-state/description/
 *
 * algorithms
 * Medium (34.18%)
 * Likes:    57
 * Dislikes: 0
 * Total Accepted:    11.1K
 * Total Submissions: 30.4K
 * Testcase Example:  '["O  ","   ","   "]'
 *
 * 给你一个字符串数组 board 表示井字游戏的棋盘。当且仅当在井字游戏过程中，棋盘有可能达到 board 所显示的状态时，才返回 true 。
 * 
 * 井字游戏的棋盘是一个 3 x 3 数组，由字符 ' '，'X' 和 'O' 组成。字符 ' ' 代表一个空位。
 * 
 * 以下是井字游戏的规则：
 * 
 * 
 * 玩家轮流将字符放入空位（' '）中。
 * 玩家 1 总是放字符 'X' ，而玩家 2 总是放字符 'O' 。
 * 'X' 和 'O' 只允许放置在空位中，不允许对已放有字符的位置进行填充。
 * 当有 3 个相同（且非空）的字符填充任何行、列或对角线时，游戏结束。
 * 当所有位置非空时，也算为游戏结束。
 * 如果游戏结束，玩家不允许再放置字符。
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：board = ["O  ","   ","   "]
 * 输出：false
 * 解释：玩家 1 总是放字符 "X" 。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：board = ["XOX"," X ","   "]
 * 输出：false
 * 解释：玩家应该轮流放字符。
 * 
 * 示例 3：
 * 
 * 
 * 输入：board = ["XXX","   ","OOO"]
 * 输出：false
 * 
 * 
 * Example 4:
 * 
 * 
 * 输入：board = ["XOX","O O","XOX"]
 * 输出：true
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * board.length == 3
 * board[i].length == 3
 * board[i][j] 为 'X'、'O' 或 ' '
 * 
 * 
 */
#include <bits/stdc++.h>
#include "struct.h"
using namespace std;
// @lc code=start
class Solution {
public:
    bool validTicTacToe(vector<string>& board) {
        vector<int> c(6,0);
        int o = 0;
        int x = 0;
        int o1;
        int x1;
        bool oflag = false;
        bool xflag = false;
        for(int i=0;i<3;++i){
            o1 = 0;
            x1 = 0;
            for(int j=0;j<3;++j){
                if(board[i][j] == 'O'){
                    ++o;
                    ++o1;
                    ++c[2*j];
                }else if(board[i][j]=='X'){
                    ++x;
                    ++x1;
                    ++c[2*j+1];
                }
            }
            if(o1==3){
                oflag = true;
            }
            if(x1==3){
                xflag = true;
            }
        }
        if(o>x) return false;
        if(x-o>1) return false;
        for(int i=0; i<5; ++i){
            if(c[i] == 3){
                if(i%2==0){
                    oflag = true;
                }else{
                    xflag = true;
                }
            }
        }
        // 判断中心
        if(board[1][1] == 'O'){
            if(board[0][0]=='O'&&board[2][2]=='O') oflag=true;
            if(board[0][2]=='O'&&board[2][0]=='O') oflag=true;
        }else if(board[1][1]=='X'){
            if(board[0][0]=='X'&&board[2][2]=='X') xflag=true;
            if(board[0][2]=='X'&&board[2][0]=='X') xflag=true;
        }
        if(xflag && oflag) return false;
        if(xflag && x-o!=1) return false;
        if(oflag && x-o!=0) return false;
        return true;
    }
};
// @lc code=end

