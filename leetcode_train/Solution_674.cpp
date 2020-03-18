#include<vector>
#include<algorithm>

using namespace std;
//
//Given an unsorted array of integers, find the length of longest continuous increasing subsequence(subarray).
//
//Example 1:
//Input: [1, 3, 5, 4, 7]
//	Output : 3
//	Explanation : The longest continuous increasing subsequence is[1, 3, 5], its length is 3.
//	Even though[1, 3, 5, 7] is also an increasing subsequence, it's not a continuous one where 5 and 7 are separated by 4. 

//»¬¶¯´°¿Ú



class Solution {
public:
	int findLengthOfLCIS(vector<int>& nums) {
		if (nums.size() == 0)
			return 0;
		int n = nums.size();
		int rs = 1;
		int left = 0;
		for (int i = 1; i<n; i++) {
			if (nums[i]>nums[i - 1])
				rs = max(i - left + 1, rs);
			else
				left = i;
		}
		return rs;

	}
};