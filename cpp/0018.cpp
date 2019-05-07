#include <algorithm>
#include <iostream>
#include <vector>

using int_v = std::vector<int>;
using vector_of_int_v = std::vector<std::vector<int>>;

vector_of_int_v solution(int_v numbers, int target) {
  using namespace std;
  vector_of_int_v result;

  sort(numbers.begin(), numbers.end());
  int n = numbers.size();

  for (int i = 0; i < n - 3; ++i) {
    if (i > 0 && numbers[i] == numbers[i - 1]) continue;
    for (int j = i + 1; j < n - 2; ++j) {
      if (j != i + 1 && numbers[j] == numbers[j - 1]) continue;

      int sum = target - (numbers[i] + numbers[j]);
      int k = j + 1, l = n - 1;
      // int l = n-1;

      while (k < l) {
        if (k > j + 1 && numbers[k] == numbers[k - 1]) {
          k++;
          continue;
        }
        if (l < n - 1 && numbers[l] == numbers[l + 1]) {
          l--;
          continue;
        }

        int sub_sum = numbers[k] + numbers[l];
        if (sum == sub_sum) {
          result.push_back({numbers[i], numbers[j], numbers[k], numbers[l]});
          k++;
          l--;
          continue;
        }
        if (sub_sum < sum) {
          k++;
        } else {
          l--;
        }
      }
    }
  }

  return result;
}

int main() {
  using namespace std;
  /*
        For example, given array S = [1, 0, -1, 0, -2, 2], and target = 0.

        A solution set is:
        [
          [-1,  0, 0, 1],
          [-2, -1, 1, 2],
          [-2,  0, 0, 2]
        ]
        */

  vector_of_int_v result;
  vector<int> numbers = {1, 0, -1, 0, -2, 2};
  int target = 0;
  result = solution(numbers, target);
  for (const auto &res : result) {
    for (const auto &el : res) {
      cout << el << " ";
    }
    cout << "\n";
  }

  return 0;
}
