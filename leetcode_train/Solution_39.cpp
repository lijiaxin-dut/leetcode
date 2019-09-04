#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>

using namespace std;

//Given a set of candidate numbers(candidates) (without duplicates) and a target number(target), find all unique combinations in candidates where the candidate numbers sums to target.
//
//The same repeated number may be chosen from candidates unlimited number of times.
//
//Note:
//
//All numbers(including target) will be positive integers.
//The solution set must not contain duplicate combinations.
//Example 1 :
//
//	Input : candidates = [2, 3, 6, 7], target = 7,
//	A solution set is :
//[
//	[7],
//	[2, 2, 3]
//]

//DFS遍历所有的可能
//一个数组中可以有多个数字出现
//下一次的搜索位置与上一次相同

class Solution_39 {
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		vector<vector<int>> rs;
		help(rs, vector<int>(), candidates, 0, target, 0);
		return rs;

	}
	void help(vector<vector<int>> &rs, vector<int>curr, vector<int>& candidates, int current_sum, int target, int start) {
		if (current_sum == target) {
			rs.push_back(curr);
			return;
		}
		for (int i = start; i < candidates.size(); i++) {
			auto one_num = candidates[i];
			if (current_sum + one_num > target)
				continue;
			current_sum += one_num;
			curr.push_back(one_num);
			help(rs, curr, candidates, current_sum, target, i);
			current_sum -= one_num;
			curr.pop_back();
		}
	}
};
//int main() {
//	Solution_39 s;
//	vector<int>c{ 8,7,4,3 };
//	s.combinationSum(c, 11);
//
//}