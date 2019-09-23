#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>
#include<unordered_map>
#include<stack>
#include<sstream>
using namespace std;

class Solution_77 {
public:
	vector<vector<int>> combine(int n, int k) {
		vector<vector<int>>rs;
		vector<int>partial_rs;
		help(rs, 1, n, k, partial_rs);
		return rs;
	}
	void help(vector<vector<int>>&rs, int start, int n, int k, vector<int>&partial_rs) {
		if (partial_rs.size() == k) {
			rs.push_back(partial_rs);
			return;
		}

		for (int i = start; i <= n; i++) {
			partial_rs.push_back(i);
			help(rs, i + 1, n, k, partial_rs);
			partial_rs.pop_back();
		}


	}
};