#include<stack>
#include<iostream>
#include<string>
#include<vector>

using namespace std;

//利用2个栈实现简单的运算操作，不能省略括号，支持 + - * /
// dijkstra双栈算法
//对字符串进行拆分
//忽略所有空格，



//1.将数字压入数字栈
//2.将运算符压入运算符栈
//3.忽略左括号
//4.遇到右括号，弹出两个操作数和一个运算符，将结果压入数字栈



class evaluate {
public:
	vector<string>split(string s) {
		vector<string>rs;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == ' ')
				continue;
			if (s[i] == '(')
				rs.push_back("(");
			else if (s[i] == ')')
				rs.push_back(")");
			else if (s[i] == '+')
				rs.push_back("+");
			else if (s[i] == '-')
				rs.push_back("-");
			else if (s[i] == '*')
				rs.push_back("*");
			else if (s[i] == '/')
				rs.push_back("/");
			else if (s[i] >= '0'&&s[i] <= '9') {
				string temp;
				while ((i<s.size()&&s[i] >= '0'&&s[i] <= '9')||(s[i]=='.')) {
					temp.push_back(s[i]);
					i++;
				}
				i--;
				rs.push_back(temp);
			}
		}
		return rs;

	}
	double calculate(string s) {
		stack<string>ops;
		stack<double>vals;
		vector<string>splited_s = this->split(s);
		for (const auto &one_s : splited_s) {
			if (one_s == "(") {
			}
			else if (one_s == "+")
				ops.push("+");
			else if (one_s == "-")
				ops.push("-");
			else if (one_s == "*")
				ops.push("*");
			else if (one_s == "/")
				ops.push("/");
			else if (one_s == ")") {
				string op = ops.top();
				ops.pop();
				double first = vals.top();
				vals.pop();
				double second = vals.top();
				vals.pop();
				if (op == "+")
					vals.push(second + first);
				else if (op == "-")
					vals.push(second - first);
				else if (op == "*")
					vals.push(second*first);
				else if (op == "/")
					vals.push(second/first);
			}
			else
				vals.push(stof(one_s));			
		}
		return vals.top();
	}
};

//int main() {
//	string s("(1+((2+3)*(4*5.0)))");
//	evaluate e;
//	cout<<e.calculate(s);
//	system("pause");
//}