#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>

using namespace std;
//Given an array, rotate the array to the right by k steps, where k is non - negative.
//
//Example 1:
//
//Input: [1, 2, 3, 4, 5, 6, 7] and k = 3
//	Output : [5, 6, 7, 1, 2, 3, 4]
//	Explanation :
//	rotate 1 steps to the right : [7, 1, 2, 3, 4, 5, 6]
//	rotate 2 steps to the right : [6, 7, 1, 2, 3, 4, 5]
//	rotate 3 steps to the right : [5, 6, 7, 1, 2, 3, 4]



class Solution_189 {
public:

	//使用额外空间
	void rotate_1(vector<int>& nums, int k) {
		int n = nums.size();
		k = k%n;
		vector<int>aux_array(n);
		for (int i = 0; i<n; i++) {
			aux_array[(i + k) % n] = nums[i];
		}
		for (int i = 0; i<n; i++) {
			nums[i] = aux_array[i];
		}
	}
	//将前半段逆序
	//将后半段逆序
	//将整个数组逆序
	//就得到了结果
	void rotate_1(vector<int>& nums, int k) {
		int n = nums.size();
		k = k%n;
		reverse(nums.begin(), nums.begin() + n - k);
		reverse(nums.begin() + n - k, nums.end());
		reverse(nums.begin(), nums.end());
	}


};