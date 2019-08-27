//
// Created by vlad on 27.08.2019.
//
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        size_t n = nums.size();
        if(n<=1)
            return;
        vector<int> tmp_nums(n, 0);
        for(int i=0;i<n;++i){
            tmp_nums[(i+k)%n]=nums[i];
        }
        nums=tmp_nums;
    }
};