#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using pint = pair<int,int>;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
	
		vector<int> res;		
		if(nums.size()==0)
			return res;
			
		vector<pint> nums_pair;
		for(int i=0;i<nums.size();++i)
			nums_pair.push_back({nums[i],i});
			
		sort(nums_pair.begin(),nums_pair.end(),
			[](const pint &l, const pint &r) -> bool{
			 return l.first<r.first;
		});
		int l=0,r=nums.size()-1;
		
		while(l<r){
			int sum = nums_pair[l].first+nums_pair[r].first;
			if(sum<target)
				l++;
			else if(sum>target)
				r--;
			else{
				res.assign({nums_pair[l].second,nums_pair[r].second});
        break;
			}
		}
		return res;				      
	}
};

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
	
		vector<int> res;
		unordered_map<int,int> htbl;
		for(int i=0;i<nums.size();++i){
			htbl[nums[i]]=i;
		}
		
		for(int i=0;i<nums.size();++i){
			auto it = htbl.find(target-nums[i]);
			if(it!=htbl.end()&&(it->second!=i)){
				res.assign({i,it->second});
			}
		}
				
		return res;				      
	}
};
