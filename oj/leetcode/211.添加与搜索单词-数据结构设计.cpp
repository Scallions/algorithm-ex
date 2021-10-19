/*
 * @lc app=leetcode.cn id=211 lang=cpp
 *
 * [211] 添加与搜索单词 - 数据结构设计
 *
 * https://leetcode-cn.com/problems/design-add-and-search-words-data-structure/description/
 *
 * algorithms
 * Medium (48.18%)
 * Likes:    328
 * Dislikes: 0
 * Total Accepted:    38.6K
 * Total Submissions: 77.3K
 * Testcase Example:  '["WordDictionary","addWord","addWord","addWord","search","search","search","search"]\n' +
  '[[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]'
 *
 * 请你设计一个数据结构，支持 添加新单词 和 查找字符串是否与任何先前添加的字符串匹配 。
 * 
 * 实现词典类 WordDictionary ：
 * 
 * 
 * WordDictionary() 初始化词典对象
 * void addWord(word) 将 word 添加到数据结构中，之后可以对它进行匹配
 * bool search(word) 如果数据结构中存在字符串与 word 匹配，则返回 true ；否则，返回  false 。word 中可能包含一些
 * '.' ，每个 . 都可以表示任何一个字母。
 * 
 * 
 * 
 * 
 * 示例：
 * 
 * 
 * 输入：
 * 
 * ["WordDictionary","addWord","addWord","addWord","search","search","search","search"]
 * [[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]
 * 输出：
 * [null,null,null,null,false,true,true,true]
 * 
 * 解释：
 * WordDictionary wordDictionary = new WordDictionary();
 * wordDictionary.addWord("bad");
 * wordDictionary.addWord("dad");
 * wordDictionary.addWord("mad");
 * wordDictionary.search("pad"); // return False
 * wordDictionary.search("bad"); // return True
 * wordDictionary.search(".ad"); // return True
 * wordDictionary.search("b.."); // return True
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * addWord 中的 word 由小写英文字母组成
 * search 中的 word 由 '.' 或小写英文字母组成
 * 最多调用 50000 次 addWord 和 search
 * 
 * 
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Trie{

public:
    Trie(): children(), isEnd(false){

    }

    void insert(string word){
        Trie* cur = this;
        for(auto c: word){
            if(cur->children[c-'a'] == nullptr){
                cur->children[c-'a'] = new Trie;
            }
            cur = cur->children[c-'a'];
        }
        cur->isEnd = true;
    }

    bool search(string word){
        Trie* cur = this;
        for(auto c: word){
            if(cur->children[c-'a'] == nullptr) return false;
            cur = cur->children[c-'a'];
        }
        return cur->isEnd; // 注意还要是词的结尾
    }

    // 是否有前缀为prefix的词
    bool startsWith(string prefix){
        Trie* cur = this;
        for(auto c: prefix){
            if(cur->children[c-'a'] == nullptr) return false;
            cur = cur->children[c-'a'];
        }
        return true;
    }

    Trie* children[26]; 
    bool isEnd; // 是否存在单词

};

class WordDictionary {
public:
    WordDictionary(): root() {

    }
    
    void addWord(string word) {
        root.insert(word);
    }
    
    bool search(string word) {
        return dfs(&root, word, 0);
    }

private:
    Trie root;
    bool dfs(Trie* cur, string& word, int c){
        if(cur == nullptr) return false;
        if(c==word.size() && cur->isEnd) return true;
        if(c==word.size()) return false;
        if(word[c] == '.'){
            for(int i=0; i<26; ++i){
                if(dfs(cur->children[i], word, c+1)) return true;
            }
            return false;
        }else{
            return dfs(cur->children[word[c]-'a'], word, c+1);
        }
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */



/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
// @lc code=end

