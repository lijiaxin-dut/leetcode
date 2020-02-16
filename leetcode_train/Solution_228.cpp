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


//在nums后面插入特殊值，处理结束的位置
//两个指针，记录left和当前位置



class Solution_228 {
public:
	
	vector<string> summaryRanges_2(vector<int>& nums) {
		int left = 0;
		if (nums.empty())
			return{};
		vector<string>rs;
		nums.push_back(INT_MIN);
		int n = nums.size();
		for (int i = 0; i<n - 1; i++) {
			long t = long(nums[i + 1]) - 1;
			if (nums[i] == t)
				continue;
			else {
				if (left == i) {
					rs.push_back(to_string(nums[left]));
				}
				else {
					rs.push_back(to_string(nums[left]));
					rs.back() += "->";
					rs.back() += to_string(nums[i]);
				}
				left = i + 1;
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
