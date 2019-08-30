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
		//����#������ַ�����Ϊ�վ͵�����һ���ַ�
		//�����ַ��ͱ���
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
	//ʹ��˫ָ��һ�αȽ�
	bool backspaceCompare(string S, string T) {
		//return bulid_string(S) == bulid_string(T);
		int s_index = S.size() - 1;
		int t_index = T.size() - 1;
		int s_skip = 0;
		int t_skip = 0;
		//���Ȳ���������ѭ���ڿ��ǣ����Ȳ����ʱ����һ���ַ�����ַ��Ƚϣ�����false
		while (s_index >= 0 || t_index >= 0) {
			//����ɾ�����ַ�����¼#�ĸ�������Ҫ����#���ַ�����������ǲ�ɾ�����ַ�
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
			//����ɾ�����ַ�����¼#�ĸ�������Ҫ����#���ַ�����������ǲ�ɾ�����ַ�
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
			//һ�����ַ�һ��û���ַ�,���Ȳ����ʱ
			if ((s_index >= 0) != (t_index >= 0))
				return false;
			//���������ַ�
			if (s_index >= 0 && t_index >= 0 && S[s_index] != T[t_index])
				return false;
			s_index--;
			t_index--;
		}
		return true;
	}
};