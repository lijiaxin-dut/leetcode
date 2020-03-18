#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>
using namespace std;


//Description
//Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums such that
// a + b + c + d = target ?
// Find all unique quadruplets in the array which gives the sum of target.

class Solution_18 {
public:
	vector<vector<int>> fourSum_k(vector<int>& nums, int target) {
		sort(nums.begin(), nums.end());
		return k_sum(nums, 0, target, 4);
	}
	vector<vector<int>> k_sum(vector<int>& nums, int cur_index, int target, int k) {
		if (k == 2) {
			vector<vector<int>>rs;
			int left = cur_index;
			int right = nums.size() - 1;
			while (left<right) {
				if (nums[left] + nums[right] == target) {
					rs.push_back({ nums[left],nums[right] });
					left++;
					right--;
					while (left<right&&nums[left] == nums[left - 1])
						left++;
					while (left<right&&nums[right] == nums[right + 1])
						right--;
				}
				else if (nums[left] + nums[right]>target)
					right--;
				else
					left++;
			}
			return rs;
		}
		else {
			vector<vector<int>>rs;
			for (int i = cur_index; i<nums.size(); i++) {
				if (i != cur_index&&nums[i] == nums[i - 1])
					continue;
				auto pre_rs = k_sum(nums, i + 1, target - nums[i], k - 1);
				for (auto &one_pre_rs : pre_rs) {
					rs.push_back({ nums[i] });
					rs.back().insert(rs.back().end(), one_pre_rs.begin(), one_pre_rs.end());
				}
			}
			return rs;


		}

	}
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		sort(nums.begin(), nums.end());
		int n = nums.size();
		vector<vector<int>>rs;
		for (int i = 0; i<n; i++) {
			//跳过重复结果，第一次不需要跳过
			if (i != 0 && nums[i] == nums[i - 1])
				continue;
			for (int j = i + 1; j<n; j++) {
				//跳过重复结果，第一次不需要跳过
				if (j != i + 1 && nums[j] == nums[j - 1])
					continue;
				int two_sum = nums[i] + nums[j];
				int left = j + 1;
				int right = n - 1;
				while (left<right) {
					if (nums[left] + nums[right] + two_sum == target) {
						vector<int>one_rs{ nums[i],nums[j],nums[left],nums[right] };
						rs.push_back(std::move(one_rs));
						left++;
						right--;
						//跳过相同的数字
						while (left<right&&nums[left] == nums[left - 1])
							left++;
						//跳过相同的数字
						while (left<right&&nums[right] == nums[right + 1])
							right--;
					}
					else if (nums[left] + nums[right] + two_sum>target) {
						right--;
					}
					else {
						left++;
					}
				}
			}
		}
		return rs;
	}
};
//int main() {
//	vector<int>test{ 0,0,0,0};
//	Solution_18 s;
//	auto rs = s.fourSum(test, 1);
//	system("pause");
//}