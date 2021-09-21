#include <bits/stdc++.h>
using namespace std;

void qsort(vector<int>& nums, int s, int e){
    if(s>=e) return;
    int l = 0;
    int r = e;
    int m = nums[l+(r-l)/2];
    while(l<=r){
        while(nums[l]<m) ++l;
        while(nums[r]>m) --r;
        if(l<=r){
            swap(nums[l], nums[r]);
            ++l;
            --r;
        }
    }
    qsort(nums, s, r);
    qsort(nums, l, e);
}

int main() {
    int n;
    cin>>n;
    vector<int> nums(n,0);
    while(n--){
        cin>>nums[n];
    }
    qsort(nums, 0, nums.size()-1);
    for(auto num: nums){
        cout<<num << " ";
    }
    return 0;
}