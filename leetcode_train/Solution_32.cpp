#include<string>
#include<algorithm>
#include<stack>
using namespace std;

//dfs �ҳ����еĿ���



//ʹ��stack
//ʹ��startָ���¼��һ�������ŵ�Ϊֹ

//����������ʱ������ջ��
//����������ʱ������һ��������
//����ջ�Ƿ�Ϊ�գ�����rs


class Solution_32 {
public:
	int longestValidParentheses_stack(string s) {
		int rs = 0;
		int start = 0;
		stack<int>st;
		for (int i = 0; i<s.size(); i++) {
			if (s[i] == '(')
				st.push(i);
			else {
				if (st.empty())
					start = i + 1;
				else {
					st.pop();
					if (st.empty()) {
						rs = max(rs, i - start + 1);
					}
					else {
						rs = max(rs, i - st.top());
					}
				}
			}
		}
		return rs;

	}
	int longestValidParentheses(string s) {
		int rs = 0;
		for (int i = 0; i<s.size(); i++)
			dfs(rs, 0, 0, i, s);
		return rs;
	}
	void dfs(int &rs, int l_size, int r_size, int index, string &s) {
		if (r_size>l_size)
			return;
		if (l_size == r_size)
			rs = max(rs, l_size + r_size);
		if (index >= s.size())
			return;
		if (s[index] == '(') {
			dfs(rs, l_size + 1, r_size, index + 1, s);
		}
		else if (s[index] == ')'&&l_size >= r_size + 1) {
			dfs(rs, l_size, r_size + 1, index + 1, s);
		}
	}
};