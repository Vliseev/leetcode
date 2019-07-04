using namespace std;
#include<vector>
#include<iostream>
#include<algorithm>


class Test {
public:
    /*vector<vector<int> > test(vector<int> &nums) {

    }*/
    
    void print_v(vector<vector<int>> &ans){
    
     for(const auto &v:ans){
      cout<<"{";
      for(const auto &st : v){
        cout<<st<<",";
      }
        cout<<"},";
     }
    }
    
    vector<vector<int> > subsets(vector<int> &nums) {
        vector<vector<int>> result(1);
        sort(nums.begin(), nums.end());
        for (size_t i = 0; i < nums.size(); ++i) {
            const size_t size = result.size();
            for (size_t j = 0; j < size; ++j) {
                result.emplace_back(result[j]);
                result.back().emplace_back(nums[i]);
                
                print_v(result);
                cout<<"\n";
            }
        }
        return result;
    }
    
};


int main(){

  vector<int> v = {1,2,3};
  Test().subsets(v);

  return 0;
}
