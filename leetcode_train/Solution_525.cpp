#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

//Given a binary array, find the maximum length of a contiguous subarray with equal number of 0 and 1.
//
//Example 1:
//Input: [0, 1]
//	Output : 2
//	Explanation : [0, 1] is the longest contiguous subarray with equal number of 0 and 1.
//

//使用count表示到当前位置0与1的和
//遇到1,count++
//遇到0，count--

//如果当前count在set中，说明这一段求和为0，即1的个数与0相同

class Solution {
public:
	int findMaxLength(vector<int>& nums) {
		int rs = 0;
		int n = nums.size();
		unordered_map<int, int>hash_map;
		hash_map[0] = -1;
		int count = 0;
		for (int i = 0; i<nums.size(); i++) {
			count += (nums[i] == 1) ? 1 : -1;
			if (hash_map.count(count)) {
				rs = max(rs, i - hash_map[count]);
			}
			else {
				hash_map[count] = i;
			}
		}

		return rs;
	}
};