#include<vector>
#include<algorithm>

using namespace std;

//Given a non - empty integer array, find the minimum number of moves required to make all array elements equal, where a move is incrementing a selected element by 1 or decrementing a selected element by 1.
//
//You may assume the array's length is at most 10,000.
//
//Example:
//
//Input:
//[1, 2, 3]
//
//Output :
//	2
//
//	Explanation :
//	Only two moves are needed(remember each move increments or decrements one element) :
//
//	[1, 2, 3] = >[2, 2, 3] = >[2, 2, 2]


//对数据排序，排序后中间的数字就是目标值


class Solution {
public:
	int minMoves2(vector<int>& nums) {
		if (nums.empty())
			return 0;
		int rs = 0;
		int left = 0;
		int right = nums.size() - 1;
		sort(nums.begin(), nums.end());
		while (left < right) {
			rs += nums[right--] - nums[left++];
		}
		return rs;
	}
};