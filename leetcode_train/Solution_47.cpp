#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>


using namespace std;

class Solution_47 {
	void next_permutation(vector<int>&nums) {
		int n = nums.size();
		if (n == 0)
			return;
		for (int i = n - 1; i >= 1; i--) {
			if (nums[i - 1]<nums[i]) {
				for (int j = n - 1; j >= i; j--) {
					if (nums[j]>nums[i - 1])
					{
						swap(nums[j], nums[i - 1]);
						reverse(nums.begin() + i, nums.end());
						return;
					}
				}

			}
		}
		reverse(nums.begin(), nums.end());
	}
public:
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		//sort(nums.begin(),nums.end());
		vector<vector<int>>rs;
		rs.push_back(nums);
		while (true)
		{
			next_permutation(nums);
			if (nums != rs.front())
				rs.push_back(nums);
			else
				break;
		}
		return rs;
	}
};