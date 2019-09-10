#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>
#include<set>

using namespace std;

//Given an array of integers where 1 �� a[i] �� n(n = size of array), 
//some elements appear twice and others appear once.
//
//Find all the elements of[1, n] inclusive that do not appear in this array.
//
//Could you do it without extra space and in O(n) runtime ? 
//You may assume the returned list does not count as extra space.
//

//���ϵĽ�num[i]��num[nums[i]-1]����λ�ý���
//������齫�����������


class Solution_448 {
public:
	vector<int> findDisappearedNumbers(vector<int>& nums) {
		vector<int>rs;
		int n = nums.size();
		for (int i = 0; i<n; i++) {
			while (nums[i] != i + 1 && nums[i] != nums[nums[i] - 1]) {
				swap(nums[i], nums[nums[i] - 1]);
			}
		}
		for (int i = 0; i<n; i++) {
			if (nums[i] != i + 1)
				rs.push_back(i + 1);
		}
		return rs;
	}
};