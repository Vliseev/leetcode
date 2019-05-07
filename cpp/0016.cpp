#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>

int solution(std::vector<int>& numbers, int target) {
  using namespace std;
  sort(numbers.begin(), numbers.end());
  int ans = numeric_limits<int>::max();
  int min_diff = numeric_limits<int>::max();
  size_t n = numbers.size();

  for (int i = 0; i < n - 2; i++) {
    int k = n - 1;
    int j = i + 1;
    while (j < k) {
      int sum = numbers[i] + numbers[j] + numbers[k];
      cout << numbers[i] << " " << numbers[j] << " " << numbers[k] << " sum "
           << sum << "\n";

      if (sum < target) {
        j++;
      } else if (sum > target) {
        k--;
      } else {
        return 0;
      }
      if (abs(sum - target) < min_diff) {
        min_diff = abs(sum - target);
        ans = sum;
      }
    }
  }
  return ans;
}

int main() {
  std::vector<int> numbers = {-1, 2, 1, -4};
  int target = 1;
  std::cout << solution(numbers, target) << std::endl;

  return 0;
}
