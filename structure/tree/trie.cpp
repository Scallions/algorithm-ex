#include <bits/stdc++.h>
using namespace std;


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


private:
    Trie* children[26]; 
    bool isEnd; // 是否存在单词

};