#include <bits/stdc++.h>
using namespace std;

int main() {
    int a,b,p;
    cin>>a>>b>>p;
    long long s = 1%p; // 越界
    int t = b;
    long long c= a % p;
    while(b){
        if(b%2==1){
            s = ((c%p) * s)%p;
        }
        c = (c * c) % p;
        b >>= 1;
    }
    cout<<a<<"^"<<t<<" mod "<<p<<"="<<s;    
    return 0;
}
