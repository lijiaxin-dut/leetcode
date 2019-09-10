#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>
#include<unordered_map>

using namespace std;

//Given an array nums of n integers where n > 1, return an array output such that 
//output[i] is equal to the product of all the elements of nums except nums[i].

//Example:
//
//Input:  [1, 2, 3, 4]
//	Output : [24, 12, 8, 6]
//	Note : Please solve it without division and in O(n).

//使用两个辅助向量
//left[i]保存nums[0]-nums[i-1]的乘积
//right[i]保存nums[i+1]-num[end]的乘积
//output[i]=left[i]*right[i]


class Solution_238 {
public:
	vector<int> productExceptSelf(vector<int>& nums) {
		int n = nums.size();
		vector<int>left(n, 1);
		vector<int>right(n, 1);
		for (int i = 1; i<n; i++) {
			left[i] = left[i - 1] * nums[i - 1];
		}
		for (int i = n - 2; i >= 0; i--) {
			right[i] = right[i + 1] * nums[i + 1];
		}
		vector<int>output(n);
		for (int i = 0; i<n; i++) {
			output[i] = left[i] * right[i];
		}
		return output;
	}
};