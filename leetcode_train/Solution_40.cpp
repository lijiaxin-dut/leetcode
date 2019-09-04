#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>

using namespace std;

//Given a collection of candidate numbers(candidates) and a target number(target), 
//find all unique combinations in candidates where the candidate numbers sums to target.
//
//Each number in candidates may only be used once in the combination.


//�ȶ������������
//ÿһ��ѭ��ʱ��������ǵ�һ�����֣��жϸ�ǰһ�������Ƿ���ͬ

//if (i != start&&candidates[i] == candidates[i - 1])
//	continue;


class Solution_40 {
public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		sort(candidates.begin(), candidates.end());
		vector<vector<int>> rs;
		vector<int>one_rs;
		int current_sum = 0;
		help(rs, vector<int>(), candidates, 0, target, 0);
		return rs;
	}
	void help(vector<vector<int>> &rs, vector<int>curr, vector<int>& candidates, int current_sum, int target, int start) {
		if (current_sum == target) {
			rs.push_back(curr);
			return;
		}
		for (int i = start; i < candidates.size(); i++) {
			if (i != start&&candidates[i] == candidates[i - 1])
				continue;
			auto one_num = candidates[i];
			if (current_sum + one_num > target)
				continue;
			current_sum += one_num;
			curr.push_back(one_num);
			help(rs, curr, candidates, current_sum, target, i + 1);
			current_sum -= one_num;
			curr.pop_back();
		}
	}
};
//int main() {
//	Solution_40 s;
//	vector<int>c{ 10,1,2,7,6,1,5 };
//	s.combinationSum2(c, 8);
//
//}