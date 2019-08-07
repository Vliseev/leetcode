//
// Created by vlad on 07.08.19.
//

class Solution {
public:
    int reverse(int x) {
        int64_t abs = x;
        abs = abs>0? abs: -abs;
        int64_t res = 0;
        const int64_t max_val = 1L<<31;

        while(abs){
            res *=10;
            if(res>max_val)
                return 0;
            int tmp = abs%10;
            abs -= tmp;
            abs /= 10;
            res += tmp;
        }

        return x>0? res: -res;

    }
};