#include<map>
#include<vector>
#include<algorithm>
using namespace std;

//Given a non - empty integer array of size n, find the minimum number of moves required to make all array elements equal, where a move is incrementing n - 1 elements by 1.
//
//Example:
//
//Input:
//[1, 2, 3]
//
//Output :
//	3
//
//	Explanation :
//	Only three moves are needed(remember each move increments two elements) :
//
//	[1, 2, 3] = >[2, 3, 3] = >[3, 4, 3] = >[4, 4, 4]


//给最小的n-1个数字+1等价于给最大的数字-1

class Solution {
public:
	int minMoves(vector<int>& nums) {
		int rs = 0;
		int min_val = *min_element(nums.begin(), nums.end());
		for (auto &one_num : nums) {
			rs += one_num - min_val;
		}
		return rs;
	}
};