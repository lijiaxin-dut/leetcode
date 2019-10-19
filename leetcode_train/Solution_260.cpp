#include<iostream>
#include<vector>

using namespace std;
//
//Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice.Find the two elements that appear only once.
//
//Example:
//
//Input:  [1, 2, 1, 3, 2, 5]
//	Output : [3, 5]


//�������������һ��
//�ҵ���������һ��1
//��mark�ĸ�λ��Ϊ1

//ʹ��mark^nums[i]�Ƿ�Ϊ1������������


class Solution_260 {
public:
	vector<int> singleNumber(vector<int>& nums) {
		int r = 0;
		for (auto &i : nums)
			r ^= i;
		int mark = 1;
		while ((r&mark) == 0)
			mark <<= 1;
		vector<int>res{ 0,0 };
		for (auto &i : nums) {
			if (i&mark)
				res[0] = res[0] ^ i;
			else
				res[1] = res[1] ^ i;
		}
		return res;

	}
};