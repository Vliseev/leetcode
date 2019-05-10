class Solution {
    string max_odd(const string &s) {
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

            while (i + k + 1 < n && i - k - 1 >= 0 && s[i + k + 1] == s[i - k - 1])
                k++;
            d[i] = k;

            if (i > 0 && d[max_i] <= d[i]) max_i = i;

            if (i + k > r) {
                l = i - k;
                r = i + k;
            }
        }
        int max_d = d[max_i];

        return s.substr(max_i - max_d, 2 * max_d + 1);
    }

    string max_even(const string &s) {
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

            while (i + k < n && i - k - 1 >= 0 && s[i + k] == s[i - k - 1]) k++;
            d[i] = k;

            if (i > 0 && d[max_i] <= d[i]) max_i = i;

            if (i + k > r) {
                l = i - k;
                r = i + k - 1;
            }
        }
        int max_d = d[max_i];

        return s.substr(max_i - max_d, 2 * max_d);
    }

public:
    string longestPalindrome(std::string &s) {
        if(s.empty())
            return "";
        auto even = max_even(s);
        auto odd = max_odd(s);
        return even.length() > odd.length() ? even : odd;
    }
};