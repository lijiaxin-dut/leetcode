#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>

using namespace std;

//Your are given an array of positive integers nums.

//Count and print the number of(contiguous) subarrays where the product of all the elements in the subarray is less than k.

//使用滑动窗口
//始终保持max-product-window less than K
//Every time shift window by adding a new number on the right(j), 
//if the product is greater than k, then try to reduce numbers on the left(i), 
//until the subarray product fit less than k again, (subarray could be empty);
//Each step introduces x new subarrays, where x is the size of the current window(j + 1 - i);
//example:
//for window(5, 2), when 6 is introduced, it add 3 new subarray : (5, (2, (6)))
//(6)
//(2, 6)
//(5, 2, 6)

class Solution_713 {
public:
	int numSubarrayProductLessThanK(vector<int>& nums, int k) {
		if (k <= 1)
			return 0;
		int rs = 0;
		int left = 0;
		int product = 1;
		for (int i = 0; i<nums.size(); i++) {
			product *= nums[i];
			//如果当前nums[i]已经大于k,while循环结束后，i=left+1,rs不会发生变化
			while (product >= k)
				product /= nums[left++];
			rs += i - left + 1;
		}
		return rs;
	}
};

//int main() {
//	Solution_713 s;
//	vector<int>nums = { 10, 5, 2, 6 };
//	s.numSubarrayProductLessThanK(nums, 10);
//}