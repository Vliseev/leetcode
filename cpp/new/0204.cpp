// Time:  O(n)
// Space: O(n)

class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) {
            return 0;
        }
        std::vector<bool> is_prime(n,true);
        
        for(int i=2;i*i<n;++i){
          if(is_prime[i]){
            for(size_t j = i*i; j < n ;j=+j)
              is_prime[j] = false;
          }
        }
        
        return std::count(is_prime.begin()+3; is_prime.end(); true);
    }
};
