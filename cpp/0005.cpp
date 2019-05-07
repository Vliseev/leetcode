/*------------------------------
------------------------------
Longest Palindromic Substring
------------------------------
Given a string s, find the longest palindromic substring in s. You may assume
that the maximum length of s is 1000.

Example:

Input: "babadaba"

Output: "bab"

Note: "aba" is also a valid answer.



Example:

Input: "cbbd"

Output: "bb"
*/
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>


class Solution {
public:
	std::string solution(std::string& s) {
		using namespace std;
		int n = s.length();
		vector<int> d1(n);
		vector<int> d2(n);
		int l = 0;
		int r = -1;
		int max_1 = 0;
		int max_2 = 0;

		for (int i = 0; i < n; ++i) {
			int k1 = 0;
			int k2 = 0;

			if (i <= r) {
				k1 = min(r - i, d1[r - i + l]);
				k2 = min(r - i + 1, d2[r - i + l + 1]);
			}

			while (i + k1 + 1 < n && i - k1 - 1 >= 0 &&
				   s[i + k1 + 1] == s[i - k1 - 1])
				k1++;
			d1[i] = k1;

			while (i + k2 < n && i - k2 - 1 >= 0 && s[i + k2] == s[i - k2 - 1]) k2++;
			d2[i] = k2;

			if (i > 0 && d1[max_i] <= d1[i]) max_i = i;

			if (i + k > r) {
				l = i - k;
				r = i + k;
			}
		}
		int max_d = d1[max_i];

		return s.substr(max_i - max_d, max_i + max_d);
	}
};

int main() {
  using namespace std;
  string s = "babadbaabba";
  Solution sol;

  auto ans = sol.longestPalindrome(s);  // solution(s);

  cout << ans << "\n";
  return 0;
}
