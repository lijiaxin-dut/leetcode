#include<string>
#include<vector>

using namespace std;

//Given a string containing only digits, restore it by returning all possible valid IP address combinations.
//
//Example:
//
//Input: "25525511135"
//	Output : ["255.255.11.135", "255.255.111.35"]


//str.substr(pos,length);
//find_last_of���ص���index,�������Ƿ���string::npos

//dfs�������п��ܵ�λ���ϲ���'.'
//ע�����ǰ��0




//��Ϊip��ַÿһ���Ϊ������������Ϊһ����
//������еĿ�����

class Solution_97 {
public:
	vector<string> restoreIpAddresses_bf(string s) {
		vector<string> ret;
		string ans;

		for (int a = 1; a <= 3; a++)
			for (int b = 1; b <= 3; b++)
				for (int c = 1; c <= 3; c++)
					for (int d = 1; d <= 3; d++)
						if (a + b + c + d == s.length()) {
							int A = stoi(s.substr(0, a));
							int B = stoi(s.substr(a, b));
							int C = stoi(s.substr(a + b, c));
							int D = stoi(s.substr(a + b + c, d));
							if (A <= 255 && B <= 255 && C <= 255 && D <= 255) {
								string ans = to_string(A) + "." + to_string(B) + "." + to_string(C) + "." + to_string(D);
								//ȥ����ǰ��0���ڵ����
								if (ans.length() == s.length() + 3)
									ret.push_back(ans);
							}
						}

		return ret;
	}

	vector<string> restoreIpAddresses(string s) {
		vector<string>rs;
		string partial_rs;
		help(0, rs, s, 0, partial_rs);
		return rs;
	}
	void help(int dot_number, vector<string>&rs, string &s, int cur_index, string &partial_rs) {
		if (cur_index>s.size())
			return;

		if (dot_number == 4) {
			if (cur_index == s.size()) {
				rs.push_back(partial_rs);
				rs.back().pop_back();
			}
			return;
		}

		partial_rs.push_back(s[cur_index]);
		string p;
		//�ҵ����һ����.',
		auto last_dot = partial_rs.find_last_of('.');
		if (last_dot == string::npos)
			p = partial_rs;
		else {
			p = partial_rs.substr(last_dot + 1);
		}


		//���ֲ���Ϊ�գ��ر��0������£���0000�����һ������ܳ����������Ҫȥ�����ֲ��Ϸ������
		if (p.empty() || p[0] == '\0') {
			partial_rs.pop_back();
			return;
		}
		//���ֲ��ܳ���255
		if (stoi(p) > 255) {
			partial_rs.pop_back();
			return;
		}
		//������λ������0
		if (p.size()>1 && p[0] == '0') {
			partial_rs.pop_back();
			return;
		}

		//���������
		help(dot_number, rs, s, cur_index + 1, partial_rs);
		//�����С����
		partial_rs.push_back('.');
		help(dot_number + 1, rs, s, cur_index + 1, partial_rs);
		partial_rs.pop_back();
		partial_rs.pop_back();
	}
};

