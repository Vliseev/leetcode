#include<vector>
#include<iostream>
#include<bitset>

using namespace std;
class Solution {
  public:
    vector<int> grayCode(int n) {
     vector<int> result{0};
     for(int i =0;i<n;++i){
      for(int j=result.size()-1;j>=0;--j){
        result.emplace_back(1<<i|result[j]);
      }
     }
     return result;
    }
};

int main(){
  auto res = Solution().grayCode(3);

  std::cout<<"\n";
  for(const auto& el: res){
    cout<<std::bitset<5>(el)<<"\n";
  }  
  
  return 0;
}
