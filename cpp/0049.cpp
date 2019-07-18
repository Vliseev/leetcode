/*["eat", "tea", "tan", "ate", "nat", "bat"], 
Return:

[
  ["ate", "eat","tea"],
  ["nat","tan"],
  ["bat"]
]*/


#include<vector>
#include<algorithm>
#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string,vector<string>> dict;
        for(auto& s: strs){
            auto key=s;
            sort(key.begin(),key.end());
            dict[key].push_back(s);
        }

        for(auto& el: dict){
            ans.emplace_back(move(el.second));
        }
        return ans;
    }
};

int main(){
  vector<string> s = {"eat", "tea", "tan", "ate", "nat", "bat"};

  auto ans = Solution().groupAnagrams(s);
  
  for(const auto &v:ans){
    for(const auto &st : v){
      cout<<st<<" ";
    }
    cout<<"\n";
  }
  
  return 0;
}
