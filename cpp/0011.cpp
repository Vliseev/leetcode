//
// Created by vlad on 12.08.19.
//
static int speedup=[](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();


class Solution {
public:
    int maxArea(vector<int>& height) {
        int left=0, right=height.size()-1;
        int max_area = 0;

        while(left<right){
            auto area = (right-left)*min(height[left],height[right]);
            max_area = max(area,max_area);
            if(height[left]<height[right]){
                left++;
            }else{
                right--;
            }
        }
        return max_area;
    }
};