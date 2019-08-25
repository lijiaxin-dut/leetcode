#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>

using namespace std;
//Description
//Given an array nums and a value val, remove all instances of that value in - place and 
//return the new length.

//Do not allocate extra space for another array, you must do this by modifying the 
//input array in - place with O(1) extra memory.

//The order of elements can be changed.It doesn't matter what you leave beyond the new length.

//使用两个指针，一个标记当前不相等的位置，一个标记当前判断的位置
class Solution_27 {
public:
	int removeElement(vector<int>& nums, int val) {
		if (nums.empty())
			return 0;
		int current_index = 0;
		for (int i = 0; i<nums.size(); i++) {
			if (nums[i] == val)
				continue;
			else
				nums[current_index++] = nums[i];
		}
		return current_index;
	}
};

//int main() {
//	Solution_27 s;
//	s.removeElement(vector<int>{ 0, 1, 2, 2, 3, 0, 4, 2 },2);
//}