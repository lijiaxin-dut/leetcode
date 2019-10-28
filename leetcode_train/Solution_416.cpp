#include<vector>

using namespace std;

//Given a non - empty array containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.
//
//Note:
//
//Each of the array element will not exceed 100.
//The array size will not exceed 200.
//
//
//Example 1:
//
//Input: [1, 5, 11, 5]
//
//	Output : true
//
//	Explanation : The array can be partitioned as[1, 5, 5] and [11].
//
//
//	Example 2 :
//
//	Input : [1, 2, 3, 5]
//
//	Output : false
//
//	Explanation : The array cannot be partitioned into equal sum subsets.

//1.dfs遍历所有划分的可能
//2.dp
//0 -1 背包  将数组求和sum,然后sum=sum/2
//找到一个子集求和为sum/2
//背包问题

class Solution_416 {
public:
	bool canPartition(vector<int>& nums) {
		bool rs = false;
		int p1_sum = 0;
		int p2_sum = 0;
		dfs(rs, nums, p1_sum, p2_sum, 0);
		return rs;
	}
	void dfs(bool &rs, vector<int>&nums, int &p1_sum, int &p2_sum, int current_index) {
		if (rs == true)
			return;
		if (current_index == nums.size()) {
			if (p1_sum == p2_sum)
			{
				rs = true;
			}
			return;
		}
		p1_sum += nums[current_index];
		dfs(rs, nums, p1_sum, p2_sum, current_index + 1);
		p1_sum -= nums[current_index];
		p2_sum += nums[current_index];
		dfs(rs, nums, p1_sum, p2_sum, current_index + 1);
		p2_sum -= nums[current_index];

	}
};