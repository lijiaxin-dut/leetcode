#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>

using namespace std;

//Description
//Given an array nums, write a function to move all 0's to the end of it while maintaining the
// relative order of the non-zero elements.
//
//Example:
//
//Input: [0, 1, 0, 3, 12]
//	Output : [1, 3, 12, 0, 0]
//	Note :
//
//	You must do this in - place without making a copy of the array.
//	Minimize the total number of operations.



//ʹ������ָ�룬һ����¼��ǰ�����жϵ�λ��
//һ����¼��һ��0���ֵ�λ��

class Solution_283 {
public:
	void moveZeroes(vector<int>& nums) {
		if (nums.size() <= 1)
			return;
		int last_zero_index = 0;
		for (int i = 0; i<nums.size(); i++) {
			if (nums[i] != 0) {
				swap(nums[i], nums[last_zero_index]);
				last_zero_index++;
			}
			else
				continue;
		}
	}
};