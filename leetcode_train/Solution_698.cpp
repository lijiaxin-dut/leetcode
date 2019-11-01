#include<algorithm>
#include<vector>
#include<set>
#include<unordered_set>
using namespace std;

//Given an array of integers nums and a positive integer k, find whether it's possible to divide this array into k non-empty subsets whose sums are all equal.
//
//
//
//Example 1:
//
//Input: nums = [4, 3, 2, 3, 5, 2, 1], k = 4
//	Output : True
//	Explanation : It's possible to divide it into 4 subsets (5), (1, 4), (2,3), (2,3) with equal sums.


//dfs  先由大到小排序

class Solution_698 {
public:
	bool canPartitionKSubsets(vector<int>& nums, int k) {
		int sum = 0;
		int n = nums.size();
		for (int i = 0; i<n; i++)
			sum += nums[i];
		sort(nums.rbegin(), nums.rend());
		if (sum%k != 0)
			return false;
		int target = sum / k;
		vector<int>k_sum(k, 0);
		bool find = false;
		dfs(target, k, nums, k_sum, 0, find);
		return find;
	}
	void dfs(int target, int k, vector<int>&nums, vector<int>&k_sum, int current_index, bool &find) {
		if (find == true)
			return;
		if (current_index >= nums.size()) {
			for (int i = 0; i<k; i++) {
				if (k_sum[i] != target)
					return;
			}
			find = true;
			return;
		}
		for (int i = 0; i<k&&find == false; i++) {
			if (k_sum[i] + nums[current_index] <= target) {
				k_sum[i] += nums[current_index];
				dfs(target, k, nums, k_sum, current_index + 1, find);
				k_sum[i] -= nums[current_index];
			}
		}


	}
};