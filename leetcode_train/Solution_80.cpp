#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>

using namespace std;

//Description
//Given a sorted array nums, remove the duplicates in - place such that duplicates appeared at most twice 
//and return the new length.

//Do not allocate extra space for another array, you must do this by modifying the input array in - place
//with O(1) extra memory.


//记录当前重复的个数，当相等且重复数大于等于2时，跳过当前的数
//当相等且重复数小于2时，进行赋值，更新重复数字的长度为2
//当不相等时，进行赋值，更行重复数字的长度为1

class Solution_80 {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.size() <= 2)
			return nums.size();
		int current_length = 1;
		int current_index = 0;
		for (int i = 1; i<nums.size(); i++) {
			if (nums[i] == nums[current_index] && current_length >= 2) {
				continue;
			}
			else if (nums[i] == nums[current_index] && current_length < 2) {
				nums[++current_index] = nums[i];
				current_length++;
			}
			else if (nums[i] != nums[current_index]) {
				nums[++current_index] = nums[i];
				current_length = 1;
			}

		}
		return current_index + 1;

	}
};

//int main() {
//	Solution_80 s;
//	vector<int>v{ 0,0,1,1,1,1,2,3,3 };
//	s.removeDuplicates(v);
//}