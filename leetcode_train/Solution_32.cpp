#include<string>
#include<algorithm>
#include<stack>
using namespace std;

//dfs �ҳ����еĿ���


//ɨ�������ַ���
//����ǣ����ͱ���λ��
//����ǣ����͵���һ������������ԣ������ܵ��������ǷǷ��ģ����ߵ�������Ҳ�ǷǷ���
//
//������ջ�б������еķǷ��±꣬�����ڵ��±�������



class Solution_32 {
public:
	int longestValidParentheses_greedy(string s) {
		int n = s.length(), longest = 0;
		stack<int> st;//��󱣴����в��Ϸ���λ��
		for (int i = 0; i < n; i++) {
			if (s[i] == '(')
				st.push(i);
			else {
				if (!st.empty()) {
					//�ҳ�һ�ԺϷ������
					if (s[st.top()] == '(')
						st.pop();
					else
						st.push(i);
				}
				else st.push(i);
			}
		}
		if (st.empty())
			longest = n;
		else {
			int a = n;//�Ҳ಻�Ϸ�
			int b = 0;//��಻�Ϸ�
			while (!st.empty()) {
				b = st.top();
				st.pop();
				longest = max(longest, a - b - 1);
				a = b;
			}
			//���Ϸ���λ�ö��ں��棬��"())"
			longest = max(longest, a);
		}
		return longest;



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