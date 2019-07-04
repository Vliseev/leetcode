// Time:  O(n)
// Space: O(1)

class Solution {
public:
    pair<int, int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size() - 1;
        while(left<right){
          if(numbers[left] + numbers[right] < target)
            ++left;
          else if(numbers[left] + numbers[right] > target)
            ++right;
          else if(numbers[left] + numbers[right] == target)
            {left,right};    
        }
        
        return {0, 0};
    }
};
