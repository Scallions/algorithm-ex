/*
 * @lc app=leetcode.cn id=913 lang=cpp
 *
 * [913] 猫和老鼠
 *
 * https://leetcode-cn.com/problems/cat-and-mouse/description/
 *
 * algorithms
 * Hard (39.82%)
 * Likes:    138
 * Dislikes: 0
 * Total Accepted:    4K
 * Total Submissions: 7.6K
 * Testcase Example:  '[[2,5],[3],[0,4,5],[1,4,5],[2,3],[0,2,3]]'
 *
 * 两位玩家分别扮演猫和老鼠，在一张 无向 图上进行游戏，两人轮流行动。
 * 
 * 图的形式是：graph[a] 是一个列表，由满足 ab 是图中的一条边的所有节点 b 组成。
 * 
 * 老鼠从节点 1 开始，第一个出发；猫从节点 2 开始，第二个出发。在节点 0 处有一个洞。
 * 
 * 在每个玩家的行动中，他们 必须 沿着图中与所在当前位置连通的一条边移动。例如，如果老鼠在节点 1 ，那么它必须移动到 graph[1] 中的任一节点。
 * 
 * 此外，猫无法移动到洞中（节点 0）。
 * 
 * 然后，游戏在出现以下三种情形之一时结束：
 * 
 * 
 * 如果猫和老鼠出现在同一个节点，猫获胜。
 * 如果老鼠到达洞中，老鼠获胜。
 * 如果某一位置重复出现（即，玩家的位置和移动顺序都与上一次行动相同），游戏平局。
 * 
 * 
 * 给你一张图 graph ，并假设两位玩家都都以最佳状态参与游戏：
 * 
 * 
 * 如果老鼠获胜，则返回 1；
 * 如果猫获胜，则返回 2；
 * 如果平局，则返回 0 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：graph = [[2,5],[3],[0,4,5],[1,4,5],[2,3],[0,2,3]]
 * 输出：0
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：graph = [[1,3],[0],[3],[0,2]]
 * 输出：1
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 3 <= graph.length <= 50
 * 1 <= graph[i].length < graph.length
 * 0 <= graph[i][j] < graph.length
 * graph[i][j] != i
 * graph[i] 互不相同
 * 猫和老鼠在游戏中总是移动
 * 
 * 
 */
#include <bits/stdc++.h>
#include "struct.h"
using namespace std;
// @lc code=start
// 自己重写了一遍
class Solution {
public:
    int n;
    int dp[51][51][51*2];
    vector<vector<int>> graph;
    int catMouseGame(vector<vector<int>>& graph) {
        n = graph.size();
        this->graph = graph;
        memset(dp, -1, sizeof dp);
        return result(1, 2, 0);
    }

    int result(int m, int c, int turn){
        if(turn == 2*n) return 0;
        // 没有结果
        if(dp[m][c][turn] == -1){
            if(m==0){
                dp[m][c][turn] = 1;
            }else if(m == c){
                dp[m][c][turn] = 2;
            }else{
                nextResult(m, c, turn);
            }
        }
        return dp[m][c][turn];
    }

    void nextResult(int m, int c, int turn){
        int cur = turn % 2 == 0 ? m : c;
        int defres = cur == c ? 1 : 2;
        int res = defres;
        for(int ni: graph[cur]){
            if(cur == c && ni == 0) continue;
            int nm = cur == m ? ni : m;
            int nc = cur == c ? ni : c;
            int nr = result(nm, nc, turn+1);
            if(nr != defres){
                res = nr;
                if(nr != 0){
                    break;
                }
            }
        }
        dp[m][c][turn] = res;
    }
};
// @lc code=end

