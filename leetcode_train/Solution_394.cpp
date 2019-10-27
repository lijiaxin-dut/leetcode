#include<iostream>
#include<vector>
#include<stack>
#include<string>

using namespace std;


//Given an encoded string, return its decoded string.
//
//The encoding rule is : k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times.Note that k is guaranteed to be a positive integer.
//
//You may assume that the input string is always valid; No extra white spaces, square brackets are well - formed, etc.
//
//Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k.For example, there won't be input like 3a or 2[4].
//
//Examples:
//
//s = "3[a]2[bc]", return "aaabcbc".
//s = "3[a2[c]]", return "accaccacc".
//s = "2[abc]3[cd]ef", return "abcabccdcdcdef".

//ʹ��ջ��������
//���ϵĽ�'['�����ֺ���ĸ����ջ�� 
//����������ʱ���ʹ�ջ�е����������ţ�ע��ƴ�ӵ�˳��
//Ȼ�󵯳������ţ����µ���ĸ��Ϸ���ջ��



class Solution_394 {
public:
	string decodeString(string s) {
		stack<string>my_stack;
		int index = 0;
		string rs;
		while (index<s.size()) {
			string temp;
			while (s[index] >= '0'&&s[index] <= '9') {
				temp += s[index];
				index++;
			}
			if (!temp.empty())
				my_stack.push(temp);
			temp.clear();
			while ((s[index] >= 'a'&&s[index] <= 'z') || (s[index] >= 'A'&&s[index] <= 'Z')) {
				temp += s[index];
				index++;
			}
			if (!temp.empty())
				my_stack.push(temp);
			temp.clear();
			if (s[index] == '[') {
				my_stack.push("[");
				index++;
			}
			if (s[index] == ']') {
				temp.clear();
				while (my_stack.top() != "[") {
					temp.insert(temp.begin(), my_stack.top().begin(), my_stack.top().end());
					my_stack.pop();
				}
				my_stack.pop();
				int cur_size = stoi(my_stack.top().c_str());
				my_stack.pop();
				string new_de;
				for (int i = 0; i<cur_size; i++)
					new_de += temp;
				my_stack.push(new_de);
				index++;
			}

		}
		while (!my_stack.empty()) {
			rs.insert(rs.begin(), my_stack.top().begin(), my_stack.top().end());
			my_stack.pop();
		}
		return rs;
	}
};

int main() {
	Solution_394 s;
	s.decodeString("3[a]2[bc]");
}