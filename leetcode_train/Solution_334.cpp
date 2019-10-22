#include<string>
#include<sstream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

//Given an unsorted array return whether an increasing subsequence of length 3 exists or not in the array.
//
//Formally the function should :
//
//Return true if there exists i, j, k
//such that arr[i] < arr[j] < arr[k] given 0 ≤ i < j < k ≤ n - 1 else return false.
//	Note : Your algorithm should run in O(n) time complexity and O(1) space complexity.


//1.dp找最长的子序列
//2.记录目前为止最小的两个数



class Solution {
public:
	bool increasingTriplet(vector<int>& nums) {
		int x1 = INT_MAX;
		int x2 = INT_MAX;//x2>x1
		for (int i = 0; i<nums.size(); i++) {
			if (nums[i] <= x1)
				x1 = nums[i];
			else if (nums[i] <= x2)
				x2 = nums[i];
			else
				return true;
		}
		return false;
	}
	bool increasingTriplet_1(vector<int>& nums) {
		if (nums.empty())
			return false;
		vector<int>dp(nums.size(), 1);

		for (int i = 0; i<nums.size(); i++) {
			for (int j = 0; j<i; j++) {
				if (nums[i]>nums[j]) {
					dp[i] = max(dp[i], dp[j] + 1);
					if (dp[i] >= 3)
						return true;
				}
			}
		}
		return false;


	}
};