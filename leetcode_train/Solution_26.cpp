#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>

using namespace std;


//Description
//Given a sorted array nums, remove the duplicates in - place such that each 
//element appear only once and return the new length.

//使用两个指针，一个标记最后一个不相等的位置，一个标记当前判断的位置

class Solution_26 {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.empty())
			return 0;
		int current_index = 0;
		for (int i = 1; i<nums.size(); i++) {
			if (nums[i] != nums[current_index])
				nums[++current_index] = nums[i];
		}
		return current_index + 1;
	}
};
//int main() {
//	Solution_26 s;
//	s.removeDuplicates(vector<int>{ 1, 8, 6, 2, 5, 4, 8, 3, 7 });
//}