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


class Solution_din_prog {
    bool** alloc_mem(int n) {
        bool** P = new bool*[n];
        P[0] = new bool[n * n];
        for (int i = 1; i < n; ++i) P[i] = P[0] + i * n;
        std::fill(P[0], P[0]+n*n, false);
        return P;
    }

    void dealloc_mem(bool** P) {
        delete[] P[0];
        delete[] P;
    }

public:
    string longestPalindrome(std::string& s) {
        int n = s.size();
        if(n==0)
            return "";
        bool** P = alloc_mem(n);
        int max_i = 0, max_j = 0;

        for (int i = 0; i < n - 1; i++) {
            P[i][i + 1] = s[i] == s[i + 1];
            if (P[i][i + 1]) max_j = i, max_i = 1;
            P[i][i] = true;
        }
        P[n - 1][n - 1] = true;

        for (int i = 2; i < n; ++i) {
            for (int j = 0; j + i < n; j++) {
                if (P[j + 1][j + i - 1] && (s[j] == s[j + i])) {
                    P[j][j + i] = true;
                    if (i > max_i) {
                        max_j = j;
                        max_i = i;
                    }
                }
            }
        }
        dealloc_mem(P);
        return s.substr(max_j, max_i + 1);
    }
};