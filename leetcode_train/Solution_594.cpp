#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;

//��г������ָһ��������Ԫ�ص����ֵ����Сֵ֮��Ĳ��������1��
//
//���ڣ�����һ���������飬����Ҫ�����п��ܵ����������ҵ���ĺ�г�����еĳ��ȡ�
//
//ʾ�� 1:
//
//����: [1, 3, 2, 2, 5, 2, 3, 7]
//	��� : 5
//	ԭ�� : ��ĺ�г�����ǣ�[3, 2, 2, 2, 3].


class Solution {
public:
	int findLHS(vector<int>& nums) {
		unordered_map<int, int>m;
		for (auto i : nums) {
			m[i]++;
		}
		int rs = 0;
		for (auto one_pair : m) {
			int next_val = one_pair.first - 1;
			auto next_it = m.find(next_val);
			if (next_it != m.end())
				rs = max(rs, next_it->second + one_pair.second);
			next_val = one_pair.first + 1;
			next_it = m.find(next_val);
			if (next_it != m.end())
				rs = max(rs, next_it->second + one_pair.second);

		}
		return rs;
	}
};