
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
    using VecIt=vector<int>::iterator;
    
    int left_amount(VecIt begin, VecIt end){
      int ans = 0;
      if(begin==end)
        return 0;
     
      auto max = max_element(begin,end);
      ans = get_water_count(max,end+1,*max);
      ans += left_amount(begin,max-1);
      
      return ans;
    }
    
    int right_amount(VecIt begin, VecIt end){
      int ans = 0;
      if(begin==end)
        return 0;
      auto max = max_element(begin,end);
      ans = get_water_count(begin,max,*max);
      ans += right_amount(max+1,end);
      
      return ans;
    }
    
    int get_water_count(VecIt begin, VecIt end,int max_val){
      int ans=0;
      while(begin!=end){
        ans+=(max_val-*begin++);
      }
      return ans;        
    }
    
public:
    int trap(vector<int>& height) {
        int ans=0;
        if (height.empty()) {
            return 0;
        }
        VecIt max = max_element(height.begin(),height.end());
        ans += left_amount(height.begin(),max-1);
        ans += right_amount(max+1,height.end());

        return ans;
    }
};

class Solution1 {
    using VecIt=vector<int>::iterator;
    vector<int> left_max_arr;
    vector<int> right_max_arr;
    
    int left_amount(int begin, int end,const vector<int>& height){
      int ans = 0;
      if(begin==end)
        return 0;
     
      auto max = left_max_arr[end];
      ans = get_water_count(max,end+1,height[max],height);
      ans += left_amount(begin,max-1,height);
      
      return ans;
    }
    
    int right_amount(int begin, int end,const vector<int>& height){
      int ans = 0;
      if(begin==end)
        return 0;
      auto max = right_max_arr[begin];
      ans = get_water_count(begin,max,height[max],height);
      ans += right_amount(max+1,end,height);
      
      return ans;
    }
    
    int get_water_count(int begin, int end,int max_val,const vector<int>& height){
      int ans=0;
      while(begin!=end){
        ans+=(max_val-height[begin++]);
      }
      return ans;        
    }
    
    void fill_max_arr(const vector<int>& height){
      int n = height.size();
      left_max_arr.resize(n);
      right_max_arr.resize(n);
      
      int max=0;
      for(int i=0; i<n; ++i){
        if(height[i]>height[max])
          max = i;
        left_max_arr[i]=max;
      }
      
      max = n-1;
      for(int i=n-1; i>=0; --i){
        if(height[i]>height[max])
          max = i;
        right_max_arr[i]=max;
      }
        
    }
    
public:
    int trap(vector<int>& height) {
        int ans=0;
        if (height.empty()) {
            return 0;
        }
                
        auto max = distance(height.begin(),
                        max_element(height.begin(),height.end()));
        fill_max_arr(height);
        ans += left_amount(0,max-1, height);
        ans += right_amount(max+1,height.size(), height);

        return ans;
    }
};

int main(){
  std::vector<int> v={0,4,0,8,0,3,0,6,0,0,0,500};
  auto ans = Solution().trap(v);
  cout<<ans<<"\n";
  
  ans = Solution1().trap(v);
  cout<<ans<<"\n";

  return 0;
}
