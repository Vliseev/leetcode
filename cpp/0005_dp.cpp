#include<string>
#include<algorithm>
#include<vector>

using namespace std;

class Solution {
  
  bool** alloc_mem(int n){
    bool **P = new *bool[n];
    P[0] = new bool[n*n];
    for(int i=1; i<n; ++i)
      P[i] = P[0]+i*n;
    
    return P;
  }
  
  void dealloc_mem(bool** P){
    delete [] P[0];
    delete [] P;
  }

public:
    string longestPalindrome(std::string &s) {
      int n = s.size();
      bool** P=alloc_mem(n);
      int max_i=0,max_j=0;
      
      for(int i=0;i<n-1;i++){
        P[i][i+1] = s[i]==s[i+1];
        P[i][i] = true;
       }
      P[n-1][n-1] = true;
      
      for(int i=3;i<n;++i){
        for(int j=0;j+i<n;j+=i){
          if(P[j+1][j+i-1]&&(s[j]==s[j+i])){
            P[j][j+i]=true;
            if(j>max_j){
              max_j=j;
              max_i=i;
            }
          }
        }
      }
      
      dealloc_mem(P);
      return s.substr(max_j,max_i);    
    }
};
