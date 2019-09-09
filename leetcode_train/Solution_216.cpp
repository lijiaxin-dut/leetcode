#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>

using namespace std;

//Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.
//
//Note:
//
//All numbers will be positive integers.
//The solution set must not contain duplicate combinations.
//Example 1 :
//
//	Input : k = 3, n = 7
//	Output : [[1, 2, 4]]


//递归，寻找所有可能的组合


class Solution_216 {
public:
	vector<vector<int>> combinationSum3(int k, int n) {
		vector<vector<int>> rs;
		vector<int>temp;
		int sum = 0;
		help(1, rs, temp, k, sum, n);
		return rs;
	}
	void help(int start, vector<vector<int>> &rs, vector<int>&temp, int k, int &sum, int n) {
		if (k == 0) {
			if (sum == n) {
				rs.push_back(temp);
			}
			return;
		}
		for (int i = start; i <= 9; i++) {
			temp.push_back(i);
			sum += i;
			help(i + 1, rs, temp, k - 1, sum, n);
			sum -= i;
			temp.pop_back();
		}

	}
};