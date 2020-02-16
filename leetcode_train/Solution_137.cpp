#include<string>
#include<vector>
#include<queue>
#include<unordered_set>
using namespace std;

//Given a non - empty array of integers, every element appears three times except for one, 
//which appears exactly once.Find that single one.
//
//Note:
//
//Your algorithm should have a linear runtime complexity.
//Could you implement it without using extra memory ?
//

//每一个数字共32位，统计每一位出现的一的个数
//sum += (nums[j] >> i) & 1;

//如果某一位上为1的话，那么如果该整数出现了三次，对3取余为0，
//这样把每个数的对应位都加起来对3取余，最终剩下来的那个数就是单独的数字

class Solution_137 {
public:
	int singleNumber(vector<int>& nums) {

		int res = 0;
		for (int i = 0; i<32; i++) {
			int sum = 0;
			for (int j = 0; j<nums.size(); j++) {
				sum += (nums[j] >> i) & 1;
			}
			res |= (sum % 3) << i;
		}
		return res;

	}
};