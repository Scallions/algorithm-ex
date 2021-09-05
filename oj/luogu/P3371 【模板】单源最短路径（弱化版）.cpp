#include <bits/stdc++.h>
using namespace std;

int main() {
    //code here
    int n,m,s;
    cin>>n>>m>>s;
    vector<vector<int>> matrix(n, vector<int>(n,-1));
    vector<int> dis(n,-1);
    vector<int> vis(n,-1);
    int s,e,w;
    for(int i=0; i<m; ++i){
        cin>>s>>e>>w;
        matrix[s][e] = w;
    }
    queue<int> qs;
    qs.push(s);
    dis[s] = 0;
    vis[s] = 1;
    int c;
    while(!qs.empty()){
        c = qs.front();
        qs.pop();
        vis[c] = 0;
        for(int i=0; i<n; ++i){
            if(matrix[c][i] !=0){
                
            }
        }
    }
    return 0;
}