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


//�Ե����ϵݹ�

//����Ϊ������ʽ
//()?()
//����һ�������ʱ���ͻ���Ϊ��������
//Ȼ����еݹ�
//�õ�����󣬽��еѿ����˻�����

//������  �ж��ٲ�ͬ�Ķ���������   p95



class Solution {
public:
	vector<int> diffWaysToCompute(string input) {
		if (input.size() == 0)
			return{};
		if (input.find_first_of("+-*") == std::string::npos)
			return{ stoi(input) };
		vector<int>rs;
		for (int i = 0; i<input.size(); i++) {
			if (input[i] == '*') {
				auto first = input.substr(0, i);
				auto second = input.substr(i + 1);
				auto first_rs = diffWaysToCompute(first);
				auto second_rs = diffWaysToCompute(second);
				for (auto i : first_rs) {
					for (auto j : second_rs)
						rs.push_back(i*j);
				}

			}
			else if (input[i] == '-') {
				auto first = input.substr(0, i);
				auto second = input.substr(i + 1);
				auto first_rs = diffWaysToCompute(first);
				auto second_rs = diffWaysToCompute(second);
				for (auto i : first_rs) {
					for (auto j : second_rs)
						rs.push_back(i - j);
				}

			}
			else if (input[i] == '+') {
				auto first = input.substr(0, i);
				auto second = input.substr(i + 1);
				auto first_rs = diffWaysToCompute(first);
				auto second_rs = diffWaysToCompute(second);
				for (auto i : first_rs) {
					for (auto j : second_rs)
						rs.push_back(i + j);
				}
			}

		}
		return rs;

	}
};