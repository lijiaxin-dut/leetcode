#include<string>
#include<vector>

using namespace std;


//Given a string of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators.The valid operators are + , -and *.
//
//Example 1:
//
//Input: "2-1-1"
//	Output : [0, 2]
//	Explanation :
//	((2 - 1) - 1) = 0
//	(2 - (1 - 1)) = 2


//自底向上递归

//抽象为如下形式
//()?()
//遇到一个运算符时，就划分为两个部分
//然后进行递归
//得到结果后，进行笛卡尔乘积重组

//类似于  有多少不同的二叉搜索树   p95



class Solution {
public:
	vector<int> diffWaysToCompute(string input) {
		vector<int>rs;
		for (int i = 0; i<input.size(); i++) {
			if (input[i] == '+' || input[i] == '-' || input[i] == '*') {
				vector<int>left = diffWaysToCompute(input.substr(0, i));
				vector<int>right = diffWaysToCompute(input.substr(i + 1));
				for (auto &one_left : left) {
					for (auto &one_right : right) {
						if (input[i] == '+') {
							rs.push_back(one_left + one_right);
						}
						else if (input[i] == '-') {
							rs.push_back(one_left - one_right);
						}
						else if (input[i] == '*') {
							rs.push_back(one_left*one_right);
						}
					}
				}
			}
		}
		//只包含数字
		if (rs.empty())
			rs.push_back(atoi(input.c_str()));
		return rs;

	}
};