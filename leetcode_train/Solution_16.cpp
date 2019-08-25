#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>
using namespace std;


//Description
//Given an array nums of n integers and an integer target,
//find three integers in nums such that the sum is closest to target.Return the sum of the three integers.
//You may assume that each input would have exactly one solution.


class Solution_16 {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		//首先对数组进行排序处理
		sort(nums.begin(), nums.end());
		//记录当前的差值
		int current_abs = INT_MAX;
		int rs = 0;
		for (int i = 0; i<nums.size(); i++) {
			//跳过相同的数组
			if (i >= 1 && nums[i] == nums[i - 1])
				continue;
			int left = i + 1;
			int right = nums.size() - 1;
			while (left<right) {
				int difference = target - nums[i] - nums[left] - nums[right];
				//找到了更好的差值
				if (abs(difference)<current_abs) {
					current_abs = abs(difference);
					rs = nums[i] + nums[left] + nums[right];
				}
				if (difference>0)
					left++;
				else if (difference<0)
					right--;
				else
					return target;
			}
		}
		return rs;
	}
};
//int main() {
//	vector<int>test{ -1, 2, 1, -4 };
//	Solution_16 s;
//	auto rs = s.threeSumClosest(test,1);
//	system("pause");
//}