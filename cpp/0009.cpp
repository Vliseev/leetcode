//
// Created by vlad on 07.08.19.
//

class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
            return false;
        std::vector<uint8_t> digit;

        while(x){
            int tmp = x%10;
            x /= 10;
            digit.push_back(tmp);
        }
        auto num_digit = digit.size();
        for(int i=0; i<num_digit/2;++i){
            if(digit[i]!=digit[num_digit-1-i])
                return false;
        }
        return true;
    }
};