//
// Created by vlad on 15.08.2019.
//

class Solution {
public:
    int strStr(string haystack, string needle) {
        if(haystack.size()<needle.size())
            return -1;

        int i,j;
        int last_id=0;
        for(i=0,j=0;i<haystack.size()&&j<needle.size();){
            if (haystack[i] == needle[j]) {
                i++,j++;
            }else{
                j=0;
                last_id++;
                i=last_id;
            }
        }
        if (j == needle.size())
            return i-j;

        return -1;
    }
};