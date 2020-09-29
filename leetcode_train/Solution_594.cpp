#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;

//和谐数组是指一个数组里元素的最大值和最小值之间的差别正好是1。
//
//现在，给定一个整数数组，你需要在所有可能的子序列中找到最长的和谐子序列的长度。
//
//示例 1:
//
//输入: [1, 3, 2, 2, 5, 2, 3, 7]
//	输出 : 5
//	原因 : 最长的和谐数组是：[3, 2, 2, 2, 3].


class Solution {
public:
	int findLHS(vector<int>& nums) {
		unordered_map<int, int>m;
		for (auto i : nums) {
			m[i]++;
		}
		int rs = 0;
		for (auto one_pair : m) {
			int next_val = one_pair.first - 1;
			auto next_it = m.find(next_val);
			if (next_it != m.end())
				rs = max(rs, next_it->second + one_pair.second);
			next_val = one_pair.first + 1;
			next_it = m.find(next_val);
			if (next_it != m.end())
				rs = max(rs, next_it->second + one_pair.second);

		}
		return rs;
	}
};