#include <bits/stdc++.h>
using namespace std;

int set_father(vector<int>& as, int n){
    if(as[n] == n) return n;
    as[n] = set_father(as, as[n]);
    return as[n];
}

void set_union(vector<int>& as, int n1, int n2){
    int f1 = set_father(as, n1);
    int f2 = set_father(as, n2);
    if(f1!=f2){
        as[f1] = f2;
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    // init find union set
    vector<int> as(n+1,0);
    for(int i=0; i<n; ++i){
        as[i] = i;
    }

    // do job
    int z1,z2,z3;
    for(int i=0; i<m; ++i){
        cin>>z1>>z2>>z3;
        if(z1==1){
            set_union(as, z2, z3);
        }else{
            int f1 = set_father(as, z2);
            int f2 = set_father(as, z3);
            if(f1==f2){
                cout << "Y" << endl;
            }else{
                cout << "N" << endl;
            }
        }
    }

    return 0;
}