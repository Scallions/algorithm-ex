#include <bits/stdc++.h>
using namespace std;

int main() {
    //code here
    ios::sync_with_stdio(0);
    int n, q;
    cin >> n >> q;
    vector<bool> vs(n+1,true); // 1 是合数 0 是素数
    vs[1] = false;
    vector<int> res;
    // init 素数矩阵
    for(int i=2; i<n; ++i){
        if(vs[i] == true) res.push_back(i);
        for(auto r: res){
            if(i*r > n) break;
            vs[i*r] = false;
            if(i%r==0) break;
        }
    }
    int k;
    while(q--){
        cin >> k;
        cout << res[k-1] << endl;
    }
    return 0;
}