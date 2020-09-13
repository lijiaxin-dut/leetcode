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



class Solution {
public:
	int longestValidParentheses(string s) {
		int n = s.size();
		stack<int>un_legal;
		for (int i = 0; i<n; i++) {
			if (s[i] == '(')
				un_legal.push(i);
			else {
				if (!un_legal.empty()) {
					if (s[un_legal.top()] == '(')
						un_legal.pop();
					else
						un_legal.push(i);
				}
				else {
					un_legal.push(i);
				}
			}
		}
		if (un_legal.empty())
			return n;
		int right = n;
		int left = 0;
		int rs = 0;
		while (!un_legal.empty()) {
			left = un_legal.top();
			un_legal.pop();
			rs = max(rs, right - left - 1);
			right = left;
		}
		rs = max(rs, left);
		return rs;
	}
};