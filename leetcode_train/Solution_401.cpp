#include<vector>
#include<string>

using namespace std;

//A binary watch has 4 LEDs on the top which represent the hours(0 - 11), and the 6 LEDs on the bottom represent the minutes(0 - 59).
//
//Each LED represents a zero or one, with the least significant bit on the right.

//dfs穷举所有的可能


class Solution_401 {
public:
	vector<string> readBinaryWatch(int num) {
		vector<string>rs;
		for (int i = 0; i <= num; i++) {
			if (i <= 4 && num - i <= 6) {
				auto h = hours(i);
				auto m = minutes(num - i);
				for (auto &one_h : h) {
					for (auto &one_m : m) {
						rs.push_back(one_h + ":" + one_m);
					}
				}
			}
		}
		return rs;

	}
	vector<string>hours(int n) {
		vector<string>rs;
		vector<int>mark(4);
		if (n == 0)
			return{ "0" };
		dfs_h(1, rs, n, 0, mark);
		mark[0] = 1;
		dfs_h(1, rs, n, 1, mark);
		return rs;
	}
	void dfs_h(int current_index, vector<string>&rs, int n, int current_one, vector<int>&mark) {

		if (n == current_one) {
			int num = 0;
			for (int i = 0; i<4; i++)
				num += mark[i] * pow(2, i);
			if (num <= 11)
				rs.push_back(to_string(num));
			return;
		}
		if (current_index >= 4 || current_one>n)
			return;
		mark[current_index] = 1;
		dfs_h(current_index + 1, rs, n, current_one + 1, mark);
		mark[current_index] = 0;
		dfs_h(current_index + 1, rs, n, current_one, mark);

	}
	vector<string>minutes(int n) {
		vector<string>rs;
		vector<int>mark(6);
		if (n == 0)
			return{ "00" };
		dfs_m(1, rs, n, 0, mark);
		mark[0] = 1;
		dfs_m(1, rs, n, 1, mark);
		return rs;

	}
	void dfs_m(int current_index, vector<string>&rs, int n, int current_one, vector<int>&mark) {
		if (n == current_one) {
			int num = 0;
			for (int i = 0; i<6; i++)
				num += mark[i] * pow(2, i);
			if (num <= 59) {
				if (num <= 9)
					rs.push_back("0" + to_string(num));
				else
					rs.push_back(to_string(num));
			}
			return;
		}
		if (current_index >= 6 || current_one>n)
			return;
		mark[current_index] = 1;
		dfs_m(current_index + 1, rs, n, current_one + 1, mark);
		mark[current_index] = 0;
		dfs_m(current_index + 1, rs, n, current_one, mark);

	}
};

