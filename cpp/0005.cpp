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
#include <cassert>
using namespace std;

class Solution {


	string max_odd(const string &s){
		int n = s.length();
		vector<int> d(n);
		int l = 0;
		int r = -1;
		int max_i = 0;
		
		for (int i = 0; i < n; ++i) {
			int k = 0;

			if (i <= r) {
				k = min(r - i, d[r - i + l]);
			}

			while (i + k + 1 < n && i - k - 1 >= 0 &&
				   s[i + k + 1] == s[i - k - 1])
				k++;
			d[i] = k;

			if (i > 0 && d[max_i] <= d[i]) max_i = i;

			if (i + k > r) {
				l = i - k;
				r = i + k;
			}
		}
		int max_d = d[max_i];

		return s.substr(max_i - max_d, 2*max_d);
	}
	
	string max_even(const string &s){
		int n = s.length();
		vector<int> d(n);
		int l = 0;
		int r = -1;
		int max_i = 0;
		
		for (int i = 0; i < n; ++i) {
			int k = 0;

			if (i <= r) {
				k = min(r - i, d[r - i + l]);
			}

			while (i + k < n && i - k - 1 >= 0 &&
						 s[i + k] == s[i - k - 1])
			k++;
			d[i] = k;

			if (i > 0 && d[max_i] <= d[i]) max_i = i;

			if (i + k > r) {
				l = i - k;
				r = i + k-1;
			}
		}
		int max_d = d[max_i];

		return s.substr(max_i - max_d, 2*max_d-1);
	
	}


public:
	string longestPalindrome(std::string& s) {
	std::cout<<max_even(s)<<std::endl;
	std::cout<<max_odd(s)<<std::endl;
	return "aaa";
	}
};


string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() -1; i++) {
        char currentChar = input[i];
        if (input[i] == '\\') {
            char nextChar = input[i+1];
            switch (nextChar) {
                case '\"': result.push_back('\"'); break;
                case '/' : result.push_back('/'); break;
                case '\\': result.push_back('\\'); break;
                case 'b' : result.push_back('\b'); break;
                case 'f' : result.push_back('\f'); break;
                case 'r' : result.push_back('\r'); break;
                case 'n' : result.push_back('\n'); break;
                case 't' : result.push_back('\t'); break;
                default: break;
            }
            i++;
        } else {
          result.push_back(currentChar);
        }
    }
    return result;
}

int main() {
    string line;
		
	  //string s = "babadbaabba";
    while (getline(cin, line)) {
        string s = stringToString(line);
        
        string ret = Solution().longestPalindrome(s);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}
