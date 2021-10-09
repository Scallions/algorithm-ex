/*
 * @lc app=leetcode.cn id=352 lang=cpp
 *
 * [352] 将数据流变为多个不相交区间
 *
 * https://leetcode-cn.com/problems/data-stream-as-disjoint-intervals/description/
 *
 * algorithms
 * Hard (59.20%)
 * Likes:    127
 * Dislikes: 0
 * Total Accepted:    15K
 * Total Submissions: 22.7K
 * Testcase Example:  '["SummaryRanges","addNum","getIntervals","addNum","getIntervals","addNum","getIntervals","addNum","getIntervals","addNum","getIntervals"]\n' +
  '[[],[1],[],[3],[],[7],[],[2],[],[6],[]]'
 *
 *  给你一个由非负整数 a1, a2, ..., an 组成的数据流输入，请你将到目前为止看到的数字总结为不相交的区间列表。
 * 
 * 实现 SummaryRanges 类：
 * 
 * 
 * 
 * 
 * SummaryRanges() 使用一个空数据流初始化对象。
 * void addNum(int val) 向数据流中加入整数 val 。
 * int[][] getIntervals() 以不相交区间 [starti, endi] 的列表形式返回对数据流中整数的总结。
 * 
 * 
 * 
 * 
 * 示例：
 * 
 * 
 * 输入：
 * ["SummaryRanges", "addNum", "getIntervals", "addNum", "getIntervals",
 * "addNum", "getIntervals", "addNum", "getIntervals", "addNum",
 * "getIntervals"]
 * [[], [1], [], [3], [], [7], [], [2], [], [6], []]
 * 输出：
 * [null, null, [[1, 1]], null, [[1, 1], [3, 3]], null, [[1, 1], [3, 3], [7,
 * 7]], null, [[1, 3], [7, 7]], null, [[1, 3], [6, 7]]]
 * 
 * 解释：
 * SummaryRanges summaryRanges = new SummaryRanges();
 * summaryRanges.addNum(1);      // arr = [1]
 * summaryRanges.getIntervals(); // 返回 [[1, 1]]
 * summaryRanges.addNum(3);      // arr = [1, 3]
 * summaryRanges.getIntervals(); // 返回 [[1, 1], [3, 3]]
 * summaryRanges.addNum(7);      // arr = [1, 3, 7]
 * summaryRanges.getIntervals(); // 返回 [[1, 1], [3, 3], [7, 7]]
 * summaryRanges.addNum(2);      // arr = [1, 2, 3, 7]
 * summaryRanges.getIntervals(); // 返回 [[1, 3], [7, 7]]
 * summaryRanges.addNum(6);      // arr = [1, 2, 3, 6, 7]
 * summaryRanges.getIntervals(); // 返回 [[1, 3], [6, 7]]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 <= val <= 10^4
 * 最多调用 addNum 和 getIntervals 方法 3 * 10^4 次
 * 
 * 
 * 
 * 
 * 
 * 
 * 进阶：如果存在大量合并，并且与数据流的大小相比，不相交区间的数量很小，该怎么办?
 * 
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class SummaryRanges {
public:
    SummaryRanges(): s(10001, -1), e(10001, -1) {
    
    }
    
    void addNum(int val) {
        if(s[val] == -1){
            s[val] = val;
            e[val] = val;
            int s1 = find(s, val-1);
            int s2 = find(s, val+1);
            if(s2 != -1){
                s[val+1] = val;
                ss.erase(val+1);
            }
            if(s1 != -1){
                s[val] = s1;
            }else{
                ss.insert(val);
            }
            s1 = find(e, val-1);
            s2 = find(e, val+1);
            if(s1 != -1){
                e[val-1] = val;
            }
            if(s2 != -1){
                e[val] = e[val+1];
            }
        }
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> res;
        for(auto c:  ss){
            res.push_back(vector<int>{c, find(e,c)});
        }
        return res;
    }

private:
    vector<int> s;
    vector<int> e;
    set<int> ss;
    int find(vector<int> &t, int a){
        // 查询开始或结尾
        if(a<0 || a>=10001) return -1;
        if(t[a] == -1)return -1;
        if(t[a] == a) return t[a];
        cout << "f1: " << a << "," << t[a] << endl;
        t[a] = find(t, t[a]);
        cout << "f2: " << a << "," << t[a] << endl;
        return t[a];
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */// @lc code=end

