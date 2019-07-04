#include<vector>
#include<iostream>
#include<bitset>
#include<algorithm>

using namespace std;
class Solution {
  public:
    int maxSum(vector<int> &prices) {
     int max_dif = 0;
     int min_el = prices[0];
     
     for(int i=1;i<prices.size();i++){
      max_dif = max(max_dif,prices[i]-min_el);
      min_el = min(min_el,prices[i]);
                   
     }
     
     
     return max_dif;
    }
};

int main(){
  auto res = Solution().maxSum(3);
  

  
  return 0;
}
