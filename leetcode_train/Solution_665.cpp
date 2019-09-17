#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>

using namespace std;

//Given an array with n integers, your task is to check if it could become non - decreasing by modifying at most 1 element.
//
//We define an array is non - decreasing if array[i] <= array[i + 1] holds for every i(1 <= i < n).
//
//	Example 1:
//Input: [4, 2, 3]
//	Output : True
//	Explanation : You could modify the first 4 to 1 to get a non - decreasing array.


//���nums[i]>nums[i+1]
//��Ҫ�ж�nums[i-1]��nums[i+1]�Ĺ�ϵ���޸�����
//���i=0,ֱ���޸�nums[i]����
//���nums[i-1]>nums[i+1],��Ҫ�޸�nums[i+1]
//�����޸�nums[i],�Ժ���û��Ӱ��

class Solution_665 {
public:
	bool checkPossibility(vector<int>& nums) {
		int n = nums.size();
		int cnt = 1;
		for (int i = 0; i<n - 1; i++) {
			if (nums[i]>nums[i + 1]) {
				if (cnt == 0)
					return false;
				if (i == 0 || nums[i - 1] <= nums[i + 1])
					nums[i] = nums[i + 1];

				else
					nums[i + 1] = nums[i];

				cnt--;
			}
		}

		return true;
	}
};