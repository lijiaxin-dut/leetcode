#include<set>
#include<vector>

using namespace std;

//Given an array of integers, find out whether there are two distinct indices i and j 
//in the array such that the absolute difference between nums[i] and nums[j] is at 
//most t and the absolute difference between i and j is at most k.


//std::set::upper_bound 是 >
//std::set::lower_bound 是 >=





class Solution_220 {
public:
	bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
		set<double> hash_set;
		for (int i = 0; i<nums.size(); i++) {
			//判断是否存在>=nums[i]的数字
			auto s = hash_set.lower_bound(nums[i]);
			if (s != hash_set.end() && (*s - nums[i]) <= t)
				return true;
			//判断是否存在<=nums[i]的数字
			//nums[i]-*ss<=存在
			//nums[i]>=*ss
			//需要满足这两个条件
			auto ss = hash_set.lower_bound(nums[i] - (double)t);
			if (ss != hash_set.end() && nums[i] - *ss >= 0)
				return true;
			hash_set.insert(nums[i]);
			if (hash_set.size()>k) {
				hash_set.erase(nums[i - k]);
			}
		}
		return false;

	}
};

//int main() {
//
//	Solution_220 s;
//	s.containsNearbyAlmostDuplicate(vector<int>{ 1,5,9,1,5,9 },2,3);
//
//}