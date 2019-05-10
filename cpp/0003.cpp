#include <string>
#include <iostream>
#include <unordered_map>
using namespace std;

/*
TLE
O(n^3)
*/
class SolutionNative {
 public:
  bool isUnique(string&& s) {
    unordered_map<char, int> counter;

    for (const auto& c : s) {
      counter[c]++;
      if (counter[c] > 1) return false;
    }
    return true;
  }
  int lengthOfLongestSubstring(string s) {
    int n = s.size();
    if(n==0)
        return 0;
    int ans = 1;
    for (int i = 0; i < n - 1; i++) {
      for (int j = 1; j < n - i+1; ++j) {
          if (isUnique(s.substr(i, j)))
              ans = ans > j ? ans : j;
          else
              break;
      }
    }
    return ans;
  }
};

class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    int n = s.size();
    int ans = 0;
    unordered_map<char, int> counter;
    int i = 0, j = 0;

    while (j < n && i < n) {
      if (counter[s[j]] == 0) {
          ++counter[s[j++]];
        ans = max(ans, j - i);
      } else {
        counter[s[i++]]--;
      }
    }

    return ans;
  }
};
