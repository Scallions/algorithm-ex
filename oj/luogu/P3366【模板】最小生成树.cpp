#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,m;
    cin >> n >> m;
    // read line
    vector<vector<int>> dis(n, vector<int>(n,-1));
    int x,y,z;
    set<int> vis;
    
    for(int i=0; i<m; ++i){
        cin>>x>>y>>z;
        dis[x-1][y-1] = z;
    }

    return 0;
}