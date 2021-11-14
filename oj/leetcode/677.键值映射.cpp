/*
 * @lc app=leetcode.cn id=677 lang=cpp
 *
 * [677] 键值映射
 *
 * https://leetcode-cn.com/problems/map-sum-pairs/description/
 *
 * algorithms
 * Medium (61.86%)
 * Likes:    151
 * Dislikes: 0
 * Total Accepted:    25.4K
 * Total Submissions: 39.2K
 * Testcase Example:  '["MapSum","insert","sum","insert","sum"]\n' +
  '[[],["apple",3],["ap"],["app",2],["ap"]]'
 *
 * 实现一个 MapSum 类，支持两个方法，insert 和 sum：
 * 
 * 
 * MapSum() 初始化 MapSum 对象
 * void insert(String key, int val) 插入 key-val 键值对，字符串表示键 key ，整数表示值 val 。如果键
 * key 已经存在，那么原来的键值对将被替代成新的键值对。
 * int sum(string prefix) 返回所有以该前缀 prefix 开头的键 key 的值的总和。
 * 
 * 
 * 
 * 
 * 示例：
 * 
 * 
 * 输入：
 * ["MapSum", "insert", "sum", "insert", "sum"]
 * [[], ["apple", 3], ["ap"], ["app", 2], ["ap"]]
 * 输出：
 * [null, null, 3, null, 5]
 * 
 * 解释：
 * MapSum mapSum = new MapSum();
 * mapSum.insert("apple", 3);  
 * mapSum.sum("ap");           // return 3 (apple = 3)
 * mapSum.insert("app", 2);    
 * mapSum.sum("ap");           // return 5 (apple + app = 3 + 2 = 5)
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * key 和 prefix 仅由小写英文字母组成
 * 1 
 * 最多调用 50 次 insert 和 sum
 * 
 * 
 */
#include <bits/stdc++.h>
#include "struct.h"
using namespace std;
// @lc code=start

class Trie{
public:
    Trie(): child(26), val(0), sum(0){

    }
    vector<Trie*> child;
    int val;
    int sum;
};

class MapSum {
public:
    MapSum(): root(new Trie()) {

    }
    
    void insert(string key, int val) {
        Trie* cur = root;
        for(auto c: key){
            if(cur->child[c-'a'] == nullptr){
                cur->child[c-'a'] = new Trie();
            }
            cur = cur->child[c-'a'];
        }
        int delta = val - cur->val;
        cur->val  = val;
        cur = root;
        for(auto c: key){
            cur = cur->child[c-'a'];
            cur->sum += delta;
        }
    }
    
    int sum(string prefix) {
        Trie* cur = root;
        for(auto c: prefix){
            if(cur->child[c-'a'] == nullptr){
                return 0;
            }
            cur = cur->child[c-'a'];
        }
        return cur->sum;
    }
private:
    Trie* root;
};
/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
// @lc code=end

