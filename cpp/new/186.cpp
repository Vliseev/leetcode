// Time:  O(n)
// Space: O(1)
#include<string>
#include<iostream>
#include<algorithm>

class Solution {
public:
    void reverseWords(string &s) {
       reverse(s.begin(),s.end());
       for(int i=0,j=0;i<s.size();++i){
          if(s[i]==' '){
            reverse(s.begin()+j,s.begin()+i);
            j=i+1;
          }
       }
    }
};
