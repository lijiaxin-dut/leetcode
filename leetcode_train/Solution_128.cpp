#include<vector>
#include<unordered_set>
#include<algorithm>

using namespace std;
//
//Given an unsorted array of integers, find the length of the longest consecutive elements sequence.
//
//Your algorithm should run in O(n) complexity.

//将数字存放到set中，遍历数字
//不断在set中查找当前数字的邻居
//直至查不到位置
//就找到了一个连续的区间

class Solution_128 {
public:
	int longestConsecutive(vector<int>& nums) {
		unordered_set<int>s(nums.begin(), nums.end());
		int rs = 0;
		for (auto val : nums) {
			if (s.count(val) == 0)
				continue;
			s.erase(val);
			int pre = val - 1;
			int next = val + 1;
			while (s.count(pre))
				s.erase(pre--);
			while (s.count(next))
				s.erase(next++);
			rs = max(rs, next - pre - 1);
		}
		return rs;

	}
};