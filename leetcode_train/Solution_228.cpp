#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>
#include<unordered_map>

using namespace std;


//Given a sorted integer array without duplicates, return the summary of its ranges.
//
//Example 1:
//
//Input:  [0, 1, 2, 4, 5, 7]
//	Output : ["0->2", "4->5", "7"]
//	Explanation : 0, 1, 2 form a continuous range; 4, 5 form a continuous range.

//两层循环，第一层循环i为当前判断的起点
//内层循环找到终点
//判断只有一个数还是多个数

//或者
//两个指针，记录left和当前位置
//单独考虑最后一个group


class Solution_228 {
public:
	vector<string> summaryRanges(vector<int>& nums) {
		if (nums.empty())
			return vector<string>();
		if (nums.size() == 1)
			return vector<string>{to_string(nums[0])};
		vector<string>rs;
		int left = 0;
		for (int i = 1; i<nums.size(); i++) {
			if (nums[i] != nums[i - 1] + 1) {
				string one_range;
				one_range += to_string(nums[left]);
				if (left != i - 1) {
					one_range += "->";
					one_range += to_string(nums[i - 1]);
				}
				rs.push_back(one_range);
				left = i;
			}
		}
		string one_range;
		one_range += to_string(nums[left]);
		if (left != nums.size() - 1) {
			one_range += "->";
			one_range += to_string(nums[nums.size() - 1]);
		}
		rs.push_back(one_range);
		return rs;
	}
	vector<string> summaryRanges_2(vector<int>& nums) {
		vector<string>rs;
		int n = nums.size();
		for (int i = 0; i<n; i++) {
			int left = nums[i];
			while (i + 1<n&&nums[i] + 1 == nums[i + 1])
				i++;
			if (nums[i] == left) {
				rs.push_back(to_string(nums[i]));
			}
			else {
				string one_group;
				one_group += to_string(left);
				one_group += "->";
				one_group += to_string(nums[i]);
				rs.push_back(one_group);
			}
		}
		return rs;
	}
};

//int main() {
//	Solution_228 s;
//	vector<int>nums{ -1 };
//	s.summaryRanges(nums);
//}
