using namespace std;

#include<vector>
#include<iostream>
#include<algorithm>


class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector <vector<int>> result(1);
        sort(nums.begin(), nums.end());
        for (size_t i = 0; i < nums.size(); ++i) {
            const size_t size = result.size();
            for (size_t j = 0; j < size; ++j) {
                result.emplace_back(result[j]);
                result.back().emplace_back(nums[i]);
            }
        }
        return result;
    }
};


int main() {

    vector<int> v = {1, 2, 3};
    Solution().subsets(v);

    return 0;
}
