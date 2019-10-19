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
		//ֻ��������
		if (rs.empty())
			rs.push_back(atoi(input.c_str()));
		return rs;

	}
};