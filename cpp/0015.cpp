class Solution {
 public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    vector<vector<int>> result;
    sort(nums.begin(), nums.end());
    int n = nums.size();

    for (int i = 0; i < n - 2; i++) {
      int idx1 = i + 1;
      int idx2 = n - 1;
      if (i == 0 || (nums[i] != nums[i - 1])) {
        for (int j = i + 1; j < n - 1; j++) {
          if (idx1 - 1 > i && (nums[idx1 - 1] == nums[idx1]))
            idx1++;
          else {
            if (idx2 + 1 < n && nums[idx2] == nums[idx2 + 1])
              idx2--;
            else {
              if (nums[i] + nums[idx1] + nums[idx2] < 0) {
                idx1++;
              } else if (nums[i] + nums[idx1] + nums[idx2] > 0) {
                idx2--;
              } else {
                result.push_back({nums[i], nums[idx1], nums[idx2]});
                idx1++;
                idx2--;
              }
            }
          }
          if (idx1 >= idx2) break;
        }
      }
    }
    return result;
  }
};