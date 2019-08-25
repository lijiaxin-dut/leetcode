#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>
using namespace std;


//Description
//Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0 ?
//Find all unique triplets in the array which gives the sum of zero.


class Solution_15 {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		//首先对数组进行排序处理
		sort(nums.begin(), nums.end());
		int n = nums.size();
		vector<vector<int>> rs;
		for (int i = 0; i<n; i++) {
			int left = i + 1;
			int right = n - 1;
			//跳过相同的数字，相同的数字在之前已经处理过
			if (i >= 1 && nums[i] == nums[i - 1])
				continue;
			while (left<right) {
				if (nums[left] + nums[right] + nums[i]>0) {
					right--;
				}
				else if (nums[left] + nums[right] + nums[i]<0) {
					left++;
				}
				else {
					vector<int>one_rs = { nums[i],nums[left],nums[right] };
					rs.emplace_back(std::move(one_rs));
					left++;
					right--;
					//跳过相同的数字
					while (left<right&&nums[left] == nums[left - 1])
						left++;
					//跳过相同的数字
					while (left<right&&nums[right] == nums[right + 1])
						right--;
				}
			}
		}
		return rs;
	}
};
//int main() {
//	vector<int>test{ -2,0,0,2,2 };
//	Solution_15 s;
//	auto rs =  s.threeSum(test);
//	system("pause");
//}