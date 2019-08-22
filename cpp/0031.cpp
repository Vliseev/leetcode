//
// Created by vlad on 22.08.2019.
//

class Solution {
public:
    void nextPermutation(vector<int>& nums) {

        if(nums.size()<=1)
            return;

        int i = nums.size() - 1;
        while (i >= 1 && nums[i - 1] >= nums[i]) {
            i--;
        }

        if (i-1 >= 0){
            int j = nums.size() - 1;
            while (j >= 0 && nums[i - 1] >= nums[j]) {
                j--;
            }
            swap(nums[i - 1], nums[j]);
        }
        reverse(nums.begin() + i, nums.end());

    }
};