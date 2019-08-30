#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>

using namespace std;


//Given two strings S and T, return if they are equal when both are typed into empty text editors. 
//# means a backspace character.

//Example 1:
//
//Input: S = "ab#c", T = "ad#c"
//	Output : true
//	Explanation : Both S and T become "ac".

class Solution {
	string bulid_string(string s) {
		//遇到#，如果字符串不为空就弹出上一个字符
		//遇到字符就保存
		string val;
		for (const auto &one_char : s) {
			if (one_char == '#') {
				if (!val.empty())
					val.pop_back();
			}
			else
				val.push_back(one_char);
		}
		return val;
	}
public:
	bool backspaceCompare_build(string S, string T) {
		return bulid_string(S) == bulid_string(T);
	}
	//使用双指针一次比较
	bool backspaceCompare(string S, string T) {
		//return bulid_string(S) == bulid_string(T);
		int s_index = S.size() - 1;
		int t_index = T.size() - 1;
		int s_skip = 0;
		int t_skip = 0;
		//长度不想的情况在循环内考虑，长度不相等时，将一个字符与空字符比较，返回false
		while (s_index >= 0 || t_index >= 0) {
			//跳过删除的字符，记录#的个数，需要跳过#个字符，跳过后就是不删除的字符
			while (s_index >= 0) {
				if (S[s_index] == '#') {
					s_index--;
					s_skip++;
				}
				else if (s_skip>0) {
					s_skip--;
					s_index--;
				}
				else
					break;
			}
			//跳过删除的字符，记录#的个数，需要跳过#个字符，跳过后就是不删除的字符
			while (t_index >= 0) {
				if (T[t_index] == '#') {
					t_index--;
					t_skip++;
				}
				else if (t_skip>0) {
					t_skip--;
					t_index--;
				}
				else
					break;
			}
			//一个有字符一个没有字符,长度不相等时
			if ((s_index >= 0) != (t_index >= 0))
				return false;
			//两个都有字符
			if (s_index >= 0 && t_index >= 0 && S[s_index] != T[t_index])
				return false;
			s_index--;
			t_index--;
		}
		return true;
	}
};