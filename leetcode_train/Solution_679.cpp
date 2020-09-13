#include<vector>

using namespace std;


//你有 4 张写有 1 到 9 数字的牌。你需要判断是否能通过 *， / ， + ， - ，(，) 的运算得到 24。
//
//示例 1:
//
//输入: [4, 1, 8, 7]
//	输出 : True
//	解释 : (8 - 4) * (7 - 1) = 24
//	示例 2 :
//
//	输入 : [1, 2, 1, 2]
//	输出 : False
//

//第一步肯定是挑出两个数，算出一个数，替代它们俩。
//
//然后在三个数中玩 24 点，再挑出两个数，算出一个数替代它们。
//
//然后在两个数中玩 24 点……
//
//这就有了递归的思路。
//
//挑出不同的两数组合，需要两层循环。




class Solution {
public:
	bool judgePoint24(vector<int>& nums) {
		vector<double>d_nums;
		for (auto i : nums) {
			d_nums.push_back(i);
		}
		return dfs(d_nums);
	}
	bool dfs(vector<double>&nums) {
		if (nums.size() == 1) {
			return abs(nums[0] - 24) <= 0.00001;
		}
		int n = nums.size();
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				vector<double>new_nums(nums.begin(), nums.end());
				new_nums.erase(new_nums.begin() + i);
				new_nums.erase(new_nums.begin() + j - 1);
				bool rs = false;
				double a = nums[i];
				double b = nums[j];
				new_nums.push_back(a + b);
				rs |= dfs(new_nums);
				new_nums.back() = a - b;
				rs |= dfs(new_nums);
				new_nums.back() = a*b;
				rs |= dfs(new_nums);
				new_nums.back() = a / b;
				rs |= dfs(new_nums);
				new_nums.back() = b - a;
				rs |= dfs(new_nums);
				new_nums.back() = b / a;
				rs |= dfs(new_nums);
				if (rs) {
					return true;
				}
			}
		}
		return false;
	}
};