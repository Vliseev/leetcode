#include<unordered_set>
#include<string>
#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        const int n = s.length();
        vector<bool> t(n+1);
        t[0]=true;
        for(int i=0;i<n;++i){
          if(!t[i])
            continue;
          
          for(const auto word: wordDict){
            auto len = word.size();
            auto end = len + i;
            if(end>n)
              continue;
            if(t[end])
              continue;
              
            if(s.substr(i,len) == word)
              t[end] = true;
          }
        
        }
        
        return t[n];    
    }
};

int main(){
  unordered_set<string> dic = {"leet", "code"};

  cout<<Solution().wordBreak("leetcode",dic) << endl;


  return 0; 
}
