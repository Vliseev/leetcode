#include<unordered_set>
#include<string>
#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

class Solution {
  public:
    int ladderLength(
        string start,
        string end,
        unordered_set<string> &dict){
      if(start==end)
        return 1;

      auto level = 1;
      auto num_in_level = 1;
      queue<string> queue;
      unordered_set<string> visited;
      queue.push(start);

      while(!queue.empty()){
        unordered_set<string> children;

        string cur_el = queue.front();
        
        queue.pop();
        num_in_level--;

        if(cur_el == end)
          return level;

        for(auto i=0;i<cur_el.size();i++){
          for(char c='a';c<='z';c++){
            string child = cur_el;
            child[i] = c;
            if(dict.find(child)!=dict.end()
                && visited.find(child)==visited.end())
              children.insert(child);            
              visited.insert(child);
          }
        }
        for_each(children.begin(), children.end(),[&queue](const string &el){queue.push(el);});
        if(num_in_level==0){
          num_in_level = queue.size();
          level++;
        }
      }

      return 0;
    }
};

int main(){
  unordered_set<string> dic = {"hot","dot","dog","lot","log","cog"};

  cout<<Solution().ladderLength("hit","cog",dic) << endl;


  return 0; 
}
