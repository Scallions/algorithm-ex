#include <bits/stdc++.h>
using namespace std;

// ListNode
struct Edge{
    int to, dis;
    Edge* next;
};

int main() {
    //code here
    int n,m,s;
    cin>>n>>m>>s;
    // vector<vector<int>> matrix(n+1, vector<int>(n+1,-1));
    vector<Edge*> head(n+1);
    vector<Edge*> tail(n+1, nullptr);
    for(int i=1;i<=n;++i){
        head[i] = new Edge{-1,-1,nullptr};
        tail[i] = head[i];
    }
    vector<int> dis(n+1,-1);
    vector<int> vis(n+1,-1);
    int s1,e,w;
    for(int i=0; i<m; ++i){
        cin>>s1>>e>>w;
        Edge* t = new Edge;
        t->to = e;
        t->dis = w;
        t->next = nullptr;
        tail[s1]->next = t;
        tail[s1] = t;
    }
    queue<int> qs;
    qs.push(s);
    dis[s] = 0;
    vis[s] = 1;
    int c;

    while(!qs.empty()){
        c = qs.front();
        qs.pop();
        vis[c] = -1;
        Edge* h = head[c]->next;
        while(h!=nullptr){
            int w = h->dis;
            int to = h->to;
            if(dis[to] == -1 || dis[c] + w < dis[to]){
                dis[to] = dis[c] + w;
                if(vis[to]==-1){
                    qs.push(to);
                    vis[to] = 1;
                }
            }
            h = h->next;
        }
    }
    for(int i=1; i<=n; ++i){
        if(dis[i] == -1){
            cout << 2147483647 << " ";
            continue;
        }
        cout << dis[i] << " ";
    }
    return 0;
}