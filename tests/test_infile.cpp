#include <bits/stdc++.h>
using namespace std;

void redirect(){
    freopen("../data/test_cpp.in", "r", stdin);
    // ifstream in("../data/test_cpp.in");
    // cin.rdbuf(in.rdbuf());
    // 性能优化
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);

    // ofstream out("data/test_outcpp.txt");
    // cout.rdbuf(out.rdbuf());
}

int main(){
    redirect();

    int n, m;
    cin >> n >> m;
    cout << n << m << endl;
    int s,e,w;
    for(int i=0; i<m; ++i){
        cin >> s >> e >> w;
        cout << s << e << w;
    }

    return 0;
}