#include<vector>
#include<string>

using namespace std;

//Additive number is a string whose digits can form additive sequence.
//
//A valid additive sequence should contain at least three numbers.Except for the first two numbers, each subsequent number in the sequence must be the sum of the preceding two.
//
//Given a string containing only digits '0' - '9', write a function to determine if it's an additive number.
//
//Note: Numbers in the additive sequence cannot have leading zeros, so sequence 1, 2, 03 or 1, 02, 3 is invalid.


//dfs穷举所有的可能性
//找到一个可行的组合就返回即可


class Solution_306 {
public:
	bool isAdditiveNumber(string num) {
		vector<long long >split_nums;
		int n = num.size();
		bool is_find = false;
		help(num, split_nums, 0, n, is_find);
		return is_find;
	}
	void help(string& num, vector<long long>&split_nums, int start, int n, bool &is_find) {
		if (start == n&&split_nums.size() >= 3)
			is_find = true;
		if (is_find == true)
			return;
		for (int length = 1; length <= n - start&&is_find == false; length++) {
			string temp;
			temp = num.substr(start, length);
			if (temp.size()>1 && temp[0] == '0')
				continue;
			long long current_num = atol(temp.c_str());
			if (split_nums.size() >= 2) {
				int cur_size = split_nums.size();
				if (split_nums[cur_size - 1] == current_num - split_nums[cur_size - 2]) {
					split_nums.push_back(current_num);
					help(num, split_nums, start + length, n, is_find);
					split_nums.pop_back();
				}
			}
			else {
				split_nums.push_back(current_num);
				help(num, split_nums, start + length, n, is_find);
				split_nums.pop_back();
			}
		}

	}
};