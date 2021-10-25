#include <bits/stdc++.h>
using namespace std;

void redirect(){
	freopen("../../data/P3382_1.in", "r", stdin);
}

double func(vector<double>& as, double x){
	double res = 0;
	for(auto a: as){
		res = (res * x + a);
	}
	return res;
}

int main(){
	redirect();

	int n;
	double l, r;
	cin >> n >> l >> r;
	// cout << n << l << r << endl;
	vector<double> as(n+1);
	for(int i=0; i<n+1; ++i){
		cin >> as[i];
	}

	// 三分法
	double m1,m2;
	// double eps=1e-7;
	while(r-l > 1e-6){
		m1 = l + (r-l)/3;
		m2 = r - (r-l)/3;
		// m1 = (r+l)/2 - eps;
		// m2 = m1 + 2*eps;
		// cout << m1 << ": " << func(as, m1) << ", " << m2 << ": " << func(as, m2) << endl;
		if(func(as, m1) > func(as, m2)){
			r = m2;
		}else{
			l = m1;
		}
	}
	cout << (l+r)/2 << endl;
	return 0;
}