#include<set>
#include<vector>
#include<map>
using namespace std;

//Given an array of integers, find out whether there are two distinct indices i and j 
//in the array such that the absolute difference between nums[i] and nums[j] is at 
//most t and the absolute difference between i and j is at most k.


//std::set::upper_bound 是 >
//std::set::lower_bound 是 >=

//对于任何一个nums[i]
// lb = nums[i] - tt;
// ub = nums[i] + tt;
//使用lower_bound找到>=lb
//使用upper_boud找到>lb
//这样就找到了一段区间，满足值的要求
//在判断这些值的下标



class Solution_220 {
public:
	bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
		if (t<0 || k<0)
			return false;
		int n = nums.size();
		map<long long, long long>hash_map;
		long long tt = t;
		for (int i = 0; i<n; i++) {
			long long lb = nums[i] - tt;
			long long ub = nums[i] + tt;
			auto t1 = hash_map.lower_bound(lb);
			auto t2 = hash_map.upper_bound(ub);
			while (t1 != t2) {
				if (i - t1->second <= k)
					return true;
				else
					t1++;
			}
			hash_map[nums[i]] = i;
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