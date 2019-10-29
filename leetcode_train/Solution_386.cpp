#include<string>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

//Given an integer n, return 1 - n in lexicographical order.
//
//For example, given 13, return: [1, 10, 11, 12, 13, 2, 3, 4, 5, 6, 7, 8, 9].
//
//Please optimize your algorithm to use less time and space.The input size may be as large as 5, 000, 000.



//自定义比较函数，转化为字符串
//dfs
//看作以可十叉树
//前序遍历



class Solution_386 {
public:
	vector<int> lexicalOrder(int n) {
		vector<int>nums;
		for (int i = 1; i <= n; i++) {
			nums.push_back(i);
		}
		auto compare = [](int a, int b) {string s_a = to_string(a); string s_b = to_string(b); return s_a<s_b; };
		sort(nums.begin(), nums.end(), compare);
		return nums;
	}

	vector<int> lexicalOrder_dfs(int n) {
		vector<int>rs;
		for (int i = 1; i <= 9; i++)
			dfs(rs, n, i);
		return rs;

	}
	void dfs(vector<int>&rs, int n, int current_val) {
		if (current_val>n)
			return;
		rs.push_back(current_val);
		for (int i = 0; i <= 9; i++) {
			if (current_val * 10 + i <= n) {
				dfs(rs, n, current_val * 10 + i);
			}
		}
		string t = "dir/subdir2/subsubdir2/file2.ext";
	}
	

};