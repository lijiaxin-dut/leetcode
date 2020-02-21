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

//数字后面一定接着'['
//解析出数字后，找出后面对应的字符串 2[adfaf[adfadf]]addf就是找出adfaf[adfadf]，递归调用
//s更新为剩下的部分，继续解析


class Solution {
public:
	string decodeString(string s) {
		if (s.empty())
			return "";
		if (s.find('[') == std::string::npos)
			return s;
		string rs;
		int cur_index = 0;
		while (cur_index < s.size()) {
			if (s[cur_index] >= '0'&&s[cur_index] <= '9') {
				int num = 0;
				while (s[cur_index] >= '0'&&s[cur_index] <= '9') {
					num = num * 10 + (s[cur_index] - '0');
					cur_index++;
				}
				int left_size = 0;
				int right_size = 0;
				string middel;
				string left;
				for (int j = cur_index; j < s.size(); j++) {
					if (s[j] == '[')
						left_size++;
					else if (s[j] == ']')
						right_size++;
					if (left_size == right_size) {
						middel = s.substr(cur_index +1, j - cur_index-1);
						left = s.substr(j + 1);
						break;
					}
				}
				auto t = decodeString(middel);
				for (int i = 0; i < num; i++)
					rs += t;
				cur_index = 0;
				s = left;
			}
			else if (s[cur_index] >= 'a'&&s[cur_index] <= 'z') {
				while (s[cur_index] >= 'a'&&s[cur_index] <= 'z') {
					rs.push_back(s[cur_index]);
					cur_index++;
				}
			}
		}
		return rs;
	}

};
