#include<iostream>
#include<string>
#include<stack>
#include<vector>
#include<sstream>


using namespace std;

class Solution_151 {
public:
	string reverseWords(string s) {
		stringstream ss(s);
		stack<string>my_stack;
		string rs;
		while (getline(ss, s, ' ')) {
			if (s.empty())
				continue;
			my_stack.push(s);
		}
		while (!my_stack.empty()) {
			rs += my_stack.top();
			rs += " ";
			my_stack.pop();
		}
		if (!rs.empty())
			rs.pop_back();
		return rs;

	}
};