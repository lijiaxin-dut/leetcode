#include<string>
#include<algorithm>
#include<stack>
using namespace std;

//dfs 找出所有的可能


//扫描整个字符串
//如果是（，就保存位置
//如果是），就弹出一个（，进行配对，若不能弹出，则是非法的，或者弹出（，也是非法的
//
//结束后，栈中保存所有的非法下标，用相邻的下标进行相减



class Solution_32 {
public:
	int longestValidParentheses_greedy(string s) {
		int n = s.length(), longest = 0;
		stack<int> st;//最后保存所有不合法的位置
		for (int i = 0; i < n; i++) {
			if (s[i] == '(')
				st.push(i);
			else {
				if (!st.empty()) {
					//找出一对合法的配对
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
			int a = n;//右侧不合法
			int b = 0;//左侧不合法
			while (!st.empty()) {
				b = st.top();
				st.pop();
				longest = max(longest, a - b - 1);
				a = b;
			}
			//不合法的位置都在后面，如"())"
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