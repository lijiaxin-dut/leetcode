#include<iostream>
#include<stack>

using namespace std;

//类似于单调栈的思想
//
//int main() {
//	int n;
//	stack<int>s;
//	cin >> n;
//	for (int i = 0; i < n; i++) {
//		int temp;
//		cin >> temp;
//		s.push(temp);
//	}
//	stack<int>rs;
//	while (!s.empty()) {
//		int cur_val = s.top();
//		s.pop();
//		while (!rs.empty() && cur_val < rs.top()) {
//			s.push(rs.top());
//			rs.pop();
//		}
//		rs.push(cur_val);
//	}
//
//	while (!rs.empty()) {
//		cout << rs.top() << " ";
//		rs.pop();
//	}
//
//
//}

