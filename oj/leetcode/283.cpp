class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int l = 0; //  l 之前都不是0
        int c = 0; // 当前位置 c >= l
        while(c<n){
            if(nums[c]==0){
                ++c;
                continue;
            }else{
                swap(nums[c], nums[l]);
                ++l;
                ++c;
            }
        }
    }
};