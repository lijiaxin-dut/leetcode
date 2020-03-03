#include<vector>
#include<unordered_map>
#include<stack>

//You are given two arrays(without duplicates) nums1 and nums2 where nums1’s elements are subset of nums2.Find all the next greater numbers for nums1's elements in the corresponding places of nums2.
//
//The Next Greater Number of a number x in nums1 is the first greater number to its right in nums2.If it does not exist, output - 1 for this number.
//
//Example 1:
//Input: nums1 = [4, 1, 2], nums2 = [1, 3, 4, 2].
//	Output : [-1, 3, -1]
//	Explanation :
//	For number 4 in the first array, you cannot find the next greater number for it in the second array, so output - 1.
//	For number 1 in the first array, the next greater number for it in the second array is 3.
//	For number 2 in the first array, there is no next greater number for it in the second array, so output - 1.
//


//找到每个数组中，右边第一个大于该位置的元素

using namespace std;

class Solution {
public:
	vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
		stack<int>s;
		unordered_map<int, int>next_greater;
		for (int i = 0; i<nums2.size(); i++) {
			while (!s.empty() && nums2[i]>s.top()) {
				next_greater[s.top()] = nums2[i];
				s.pop();
			}
			s.push(nums2[i]);
		}
		int n = nums1.size();
		vector<int>rs(n, -1);
		for (int i = 0; i<nums1.size(); i++) {
			if (next_greater.count(nums1[i]))
				rs[i] = next_greater[nums1[i]];
		}
		return rs;
	}
};