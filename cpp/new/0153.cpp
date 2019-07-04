/*
Find Minimum in Rotated Sorted Array 
------------------------------
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
Find the minimum element.
You may assume no duplicate exists in the array.
*/

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

int solution(std::vector<int> &numbers){
  int left=0, right = numbers.size()-1;
  int mid = (right-left)/2;
  
  while(left<right&&numbers[left]>=numbers[right]){
    if(numbers[mid]<numbers[right])
      right = mid;
    else
      left = mid+1;
    mid = left+(right-left)/2;
  }
  return left;
}

int main(){
  using namespace std;
  vector<int> v={0,1,2,4, 5, 6, 7};
  std::cout<<v[solution(v)]<<std::endl;
  
  
  
  return 0;
}
