#include <bits/stdc++.h>
using namespace std;

void redirect(){
    freopen("../../data/P3366_1.in", "r", stdin);
    // ifstream in("../data/test_cpp.in");
    // cin.rdbuf(in.rdbuf());
    // 性能优化
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);

    // ofstream out("data/test_outcpp.txt");
    // cout.rdbuf(out.rdbuf());
}

struct Edge{
    int to,next,weight;
};

struct Eg{
    int u;
    int v;
    int w;
};

bool cmp(Eg a, Eg b){
    return a.w < b.w;
}

int find(vector<int>& fa, int x){
    if(fa[x] == x) return x;
    else{
        fa[x] = find(fa, fa[x]);
        return fa[x];
    }
}


int main() {
    redirect();

    int n,m;
    cin >> n >> m; // 点数 边数
    // prim
    // vector<int> head(n, -1);
    // vector<Edge> edges(2*m);
    // read line
    // int x,y,z;
    // for(int i=0; i<m; ++i){
    //     cin>>x>>y>>z;
    //     // 手动更新
    //     edges[2*i].to = y-1;
    //     edges[2*i].weight = z;
    //     edges[2*i].next = head[x-1];
    //     head[x-1] = 2*i;
    //     edges[2*i+1].to = x-1;
    //     edges[2*i+1].weight = z;
    //     edges[2*i+1].next = head[y-1];
    //     head[y-1] = 2*i+1;
    // }

    // 从 1 开始
    // vector<bool> vis(n, false);
    // vector<int> dis(n, INT_MAX);
    // int now = 0;
    // dis[0] = 0;
    // for(int i=head[0]; i!=-1; i=edges[i].next){
    //     // 可能用重边所以要min 否则可以直接=号
    //     dis[edges[i].to] = min(dis[edges[i].to], edges[i].weight);
    // }
    // int tot = 1;
    // int ans = 0;
    // while(tot<n){
    //     int minn = INT_MAX;
    //     vis[now] = true; // 标记走过
    //     // 枚举没走过的点，找出最小边
    //     for(int i=0; i<n; ++i){
    //         if(!vis[i] && minn>dis[i]){
    //             minn=dis[i];
    //             now = i;
    //         }
    //     }
    //     if(minn == INT_MAX){
    //         cout << "orz" << endl;
    //         return 0;
    //     }
    //     ans += minn;
    //     // 更新连接到now的所有边，更新dis数组
    //     for(int i=head[now]; i!=-1; i=edges[i].next){
    //         if(dis[edges[i].to]>edges[i].weight && !vis[edges[i].to]){
    //             dis[edges[i].to] = edges[i].weight;
    //         }
    //     }
    //     ++tot;
    // }
    // cout << ans << endl;

    // kruskal
    vector<Eg> edges(m);
    int u, v, w;
    for(int i=0; i<m; ++i){
        cin>>u>>v>>w;
        edges[i].u = u-1;
        edges[i].v = v-1;
        edges[i].w = w;
    }
    vector<int> fa(n);
    for(int i=0; i<n; ++i){
        fa[i] = i;
    }

    sort(edges.begin(), edges.end(), cmp);
    int fu, fv;
    int ans = 0;
    int cnt = 0;
    for(int i=0; i<m; ++i){
        fu = find(fa, edges[i].u);
        fv = find(fa, edges[i].v);
        if(fu == fv){
            // 会形成环
            continue;
        }
        ans += edges[i].w;
        fa[fu] = fv;
        if(++cnt == n-1){
            // 添加所有点
            break;
        }
    }
    if(cnt == n-1){
        cout << ans << endl;
    }else{
        cout << "orz" << endl;
    }

    return 0;
}