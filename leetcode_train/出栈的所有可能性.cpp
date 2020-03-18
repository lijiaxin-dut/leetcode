#include<vector>
#include<stack>
#include<iostream>

using namespace std;


class Solution {
public:
	vector<vector<int>>all_posible(vector<int>nums) {
		stack<int>s;
		vector<vector<int>>rs;
		vector<int> partial_rs;
		dfs(s, nums, 0, rs, partial_rs);
		cout << rs.size() << endl;

		return rs;
	}
	void dfs(stack<int>&s, vector<int>&nums, int cur_index, vector<vector<int>>&rs, vector<int>&partial_rs) {
		if (partial_rs.size() == nums.size()) {
			rs.push_back(partial_rs);
			return;
		}


		if (s.empty()) {
			//只能入栈
			s.push(nums[cur_index]);
			dfs(s, nums, cur_index + 1, rs, partial_rs);
			s.pop();
		}
		else if (cur_index == nums.size()) {
			int cur_val = s.top();
			partial_rs.push_back(cur_val);
			s.pop();
			dfs(s, nums, cur_index, rs, partial_rs);
			s.push(cur_val);
			partial_rs.pop_back();
		}
		else {
			//可以入栈
			s.push(nums[cur_index]);
			dfs(s, nums, cur_index + 1, rs, partial_rs);
			s.pop();

			//也可以出栈
			int cur_val = s.top();
			partial_rs.push_back(cur_val);
			s.pop();
			dfs(s, nums, cur_index, rs, partial_rs);
			s.push(cur_val);
			partial_rs.pop_back();


		}
	}

};


//int main() {
//	Solution s;
//	auto rs= s.all_posible(vector<int>{1, 2, 3});
//	for (auto &one : rs) {
//		for (auto &one_node : one)
//			cout << one_node << "\t";
//		cout << endl;
//	}
//}