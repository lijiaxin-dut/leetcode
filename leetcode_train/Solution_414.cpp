#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>
#include<set>

using namespace std;


//Given a non - empty array of integers, return the third maximum number in this array.If it does not exist, return the maximum number.The time complexity must be in O(n).
//
//Example 1:
//Input: [3, 2, 1]
//
//	Output : 1
//
//	Explanation : The third maximum is 1.
//	Example 2 :
//	Input : [1, 2]
//
//	Output : 2
//
//	Explanation : The third maximum does not exist, so the maximum(2) is returned instead.


//如果不存在第三大的数，就返回最大的数


//使用set始终保存三个数
//超过三个数就删除第一个数


class Solution_414 {
public:
	int thirdMax(vector<int>& nums) {
		set<int>hash_set;

		for (int i = 0; i<nums.size(); i++) {
			hash_set.insert(nums[i]);
			if (hash_set.size()>3) {
				hash_set.erase(hash_set.begin());
			}
		}
		if (hash_set.size() == 3) {
			return *hash_set.begin();
		}
		else {
			return *hash_set.rbegin();
		}


	}
};