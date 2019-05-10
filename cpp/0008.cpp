class Solution {
public:
    int myAtoi(string str) {
        int64_t imax = std::numeric_limits<int>::max();
        
        int64_t ans=0;
        bool positive = true;
        auto it=str.begin();
        
        while(*it==' ') ++it;
        
        if(*it=='-'||*it=='+'){
            positive = *(it++)=='+'?true:false;
        }
        
        for(;it!=str.end();++it){
            if(*it>='0' && *it<='9'){
                int digit=(int)*it-(int)'0';
                ans*=10;
                ans+=digit;
                if(ans>imax){
                    ans = positive ?imax:imax+1;
                    break;
                }
            }
            else
                break;
        }
        return positive?ans:-ans;
    }
};
