#include<vector>

using namespace std;


//Given an integer array nums, find the sum of the elements between indices i and j(i ≤ j), inclusive.
//
//Example:
//Given nums = [-2, 0, 3, -5, 2, -1]
//
//sumRange(0, 2) -> 1
//sumRange(2, 5) -> - 1
//sumRange(0, 5) -> - 3


//前缀和
//_catch[i]表示前i个数字的和
// sum(i,j)=_catch[j]-catch[i]+num[i]



class NumArray {
	vector<int>num;
	vector<int>_catch;
	int n;
public:
	NumArray(vector<int>& nums) {
		n = nums.size();
		if (n != 0) {
			num = nums;
			_catch.resize(n);
			_catch[0] = num[0];
			for (int i = 1; i<n; i++) {
				_catch[i] = _catch[i - 1] + num[i];

			}
		}
	}

	int sumRange(int i, int j) {
		return _catch[j] - _catch[i] + num[i];
	}

};