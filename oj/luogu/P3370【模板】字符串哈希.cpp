#include <bits/stdc++.h>
using namespace std;


void redirect(){
    freopen("../../data/P3370_0.in", "r", stdin);
}

using ull = unsigned long long;

ull base = 131;
int prime = 233317;
ull mod = 212370440130137957ll;

ull hashe(string s){
    int len = s.size();
    ull ans = 0;
    for(int i=0; i<len; ++i){
        ans = (ans*base + (ull)s[i])%mod + prime;
    }
    return ans;
}

int main(){
    redirect();

    int n;
    cin >> n;
    string a;
    vector<ull> as;
    for(int i=0; i<n; ++i){
        cin >> a;
        as.push_back(hashe(a));
    }
    sort(as.begin(), as.end());
    int ans = 1;
    for(int i=1; i<n; ++i){
        if(as[i] != as[i-1]) ++ans;
    }
    cout << ans << endl;
    return 0;
}