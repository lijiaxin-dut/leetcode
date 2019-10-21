#include<vector>
#include<string>

using namespace std; 


//Given a string S of digits, such as S = "123456579", we can split it into a Fibonacci - like sequence[123, 456, 579].
//
//Formally, a Fibonacci - like sequence is a list F of non - negative integers such that :
//
//0 <= F[i] <= 2 ^ 31 - 1, (that is, each integer fits a 32 - bit signed integer type);
//F.length >= 3;
//and F[i] + F[i + 1] = F[i + 2] for all 0 <= i < F.length - 2.
//	Also, note that when splitting the string into pieces, each piece must not have extra leading zeroes, except if the piece is the number 0 itself.
//
//	Return any Fibonacci - like sequence split from S, or return[] if it cannot be done.

//dfs穷举所有的可能



class Solution_842 {
public:
	vector<int> splitIntoFibonacci(string S) {
		vector<int>rs;
		vector<int>split_nums;
		int n = S.size();
		bool is_find = false;
		help(rs, S, split_nums, 0, n, is_find);
		return rs;
	}
	void help(vector<int>&rs, string& num, vector<int>&split_nums, int start, int n, bool &is_find) {
		if (start == n&&split_nums.size() >= 3) {
			rs = split_nums;
			is_find = true;
		}
		if (is_find == true)
			return;
		for (int length = 1; length <= n - start&&is_find == false; length++) {
			string temp;
			temp = num.substr(start, length);
			if (temp.size()>1 && temp[0] == '0')
				continue;
			long current_num = atol(temp.c_str());
			if (current_num>INT_MAX)
				return;
			if (split_nums.size() >= 2) {
				int cur_size = split_nums.size();
				if (split_nums[cur_size - 1] == (int)current_num - split_nums[cur_size - 2]) {
					split_nums.push_back(current_num);
					help(rs, num, split_nums, start + length, n, is_find);
					split_nums.pop_back();
				}
			}
			else {
				split_nums.push_back(current_num);
				help(rs, num, split_nums, start + length, n, is_find);
				split_nums.pop_back();
			}
		}

	}
};