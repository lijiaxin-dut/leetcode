#include<algorithm>
#include<vector>
#include<set>
#include<unordered_set>
using namespace std;

//Remember the story of Little Match Girl ? By now, you know exactly what matchsticks the little match girl has, please find out a way you can make one square by using up all those matchsticks.You should not break any stick, but you can link them up, and each matchstick must be used exactly one time.
//
//Your input will be several matchsticks the girl has, represented with their stick length.Your output will either be true or false, to represent whether you could make one square using all the matchsticks the little match girl has.
//
//Example 1 :
//	Input : [1, 1, 2, 2, 2]
//	Output : true
//
//	Explanation : You can form a square with length 2, one side of the square came two sticks with length 1.

//dfs   先排序，优先考虑大的数值，更有可能产生不可行解，加速求解


class Solution_473 {
public:
	bool makesquare(vector<int>& nums) {
		int sum = 0;
		for (int i = 0; i<nums.size(); i++)
			sum += nums[i];
		if (sum % 4 != 0)
			return false;
		sort(nums.rbegin(), nums.rend());
		int each_length = sum / 4;
		bool find = false;
		int a_length = 0;
		int b_length = 0;
		int c_length = 0;
		int d_length = 0;
		dfs(find, each_length, a_length, b_length, c_length, d_length, 0, nums);
		return find;
	}
	void dfs(bool &rs, int each_length, int a_length, int b_length, int c_length, int d_length, int current_index, vector<int>&nums) {
		if (rs == true)
			return;
		if (current_index == nums.size()) {
			if (a_length == each_length&&a_length == b_length&&a_length == c_length&&a_length&&d_length) {
				rs = true;
			}
			return;
		}
		if (a_length + nums[current_index] <= each_length)
			dfs(rs, each_length, a_length + nums[current_index], b_length, c_length, d_length, current_index + 1, nums);
		if (b_length + nums[current_index] <= each_length)
			dfs(rs, each_length, a_length, b_length + nums[current_index], c_length, d_length, current_index + 1, nums);
		if (c_length + nums[current_index] <= each_length)
			dfs(rs, each_length, a_length, b_length, c_length + nums[current_index], d_length, current_index + 1, nums);
		if (d_length + nums[current_index] <= each_length)
			dfs(rs, each_length, a_length, b_length, c_length, d_length + nums[current_index], current_index + 1, nums);
	}
};

