class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        if(n>m) return false;
        vector<int> cnt(26,0);
        for(auto &s: s1){
            --cnt[s-'a'];
        }
		// 保持left和right之间的都等于0，如果left和right的长度等于n就是s1的排列
        for(int left=0,right=0; right<m; ++right){
            int x = s2[right]-'a';
            ++cnt[x];
            while(cnt[x]>0){
                --cnt[s2[left]-'a'];
                ++left;
            }
            if(right-left+1 == n) return true; 
        }
        return false;
    }
};