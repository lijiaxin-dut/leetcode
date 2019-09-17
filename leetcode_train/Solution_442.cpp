#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>

using namespace std;

//Given an array of integers, 1 ≤ a[i] ≤ n(n = size of array), some elements appear twice and others appear once.
//
//Find all the elements that appear twice in this array.
//
//Could you do it without extra space and in O(n) runtime ?
//
//Example :
//	Input :
//	[4, 3, 2, 7, 8, 2, 3, 1]
//
//Output :
//	[2, 3]


//解法1：
//题目限定了每一个值的取值范围在，
//每遇到一个i,将nums[nums[i]-1]的值取反
//如果下次遇到j，nums[nums[j]-1]的已经为负数，说明之前遇见过这个数，保存即可


class Solution_442 {
public:
	vector<int> findDuplicates(vector<int>& nums) {
		int n = nums.size();
		vector<int>rs;
		for (int i = 0; i<n; i++) {
			//找到对应的索引
			int index = abs(nums[i]) - 1;
			//小于0说明之前遇到过这个值
			if (nums[index]<0) {
				rs.push_back(index + 1);
			}
			//将值取反
			else {
				nums[index] = -nums[index];
			}
		}
		return rs;
	}
};