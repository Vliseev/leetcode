#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  template <class ItType>
  ItType uniq(ItType first, ItType last) {
    ItType result = first;
    while (++first != last) {
      if (*result != *first && ++result != first) {
        *result = std::move(*first);
      }
    }
    return ++result;
  }

  int removeDuplicates(vector<int>& nums) {
    if (nums.empty()) return 0;
    auto last = uniq(nums.begin(), nums.end());
    return reinterpret_cast<int>(std::distance(nums.begin(), last));
  }
};

int main() {
  using namespace std;
  std::vector<int> v = {1, 2, 3, 4, 5, 6, 2, 3, 4, 5,
                        2, 2, 1, 3, 4, 5, 6, 7, 2, 3};
  sort(v.begin(), v.end());
  Solution s;
  std::cout << s.removeDuplicates(v) << "\n";

  return 0;
}
