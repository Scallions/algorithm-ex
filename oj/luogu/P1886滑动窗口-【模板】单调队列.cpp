#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> nums(n,0);
    for(int i=0; i<n; ++i){
        cin >> nums[i];
    }

    // min
    deque<int> dq2;
    for(int i=0; i<k-1; ++i){
        while(!dq2.empty() && nums[dq2.back()] >= nums[i]){
            dq2.pop_back();
        }
        dq2.push_back(i);
    }
    for(int i=k-1; i<n; ++i){
        if(dq2.front()+k <= i) dq2.pop_front();
        while(!dq2.empty() && nums[dq2.back()] >= nums[i]){
            dq2.pop_back();
        }
        dq2.push_back(i);
        cout << nums[dq2.front()] << " ";
    }
    cout << endl;

    // max
    deque<int> dq1;
    for(int i=0; i<k-1; ++i){
        while(!dq1.empty() && nums[dq1.back()] <= nums[i]){
            dq1.pop_back();
        }
        dq1.push_back(i);
    }
    for(int i=k-1; i<n; ++i){
        if(dq1.front()+k <= i) dq1.pop_front();
        while(!dq1.empty() && nums[dq1.back()] <= nums[i]){
            dq1.pop_back();
        }
        dq1.push_back(i);
        cout << nums[dq1.front()] << " ";
    }
    cout << endl;

    return 0;
}