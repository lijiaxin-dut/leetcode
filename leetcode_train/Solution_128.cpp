#include<vector>
#include<unordered_set>
#include<algorithm>

using namespace std;


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