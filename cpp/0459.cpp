//
// Created by vlad on 07.05.19.
//

#include<string>

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        using namespace std;
        auto len_s = s.length();
        if(len_s<=1)
            return false;

        bool flag;

        for (auto len = 1; len <= len_s / 2; ++len) {
            flag = true;
            for (auto j = 0; j < len_s - len; j += len) {
                if (s.compare(j, len, s, j + len, len)) {
                    flag = false;
                    break;
                }
            }
            if(flag)
                break;
        }
        return flag;
    }
};