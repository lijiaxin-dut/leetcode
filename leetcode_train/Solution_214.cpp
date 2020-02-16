#include<iostream>
#include<vector>
#include<set>
#include<string>
using namespace std;

//Given a string s, you are allowed to convert it to a palindrome by adding characters in front of it.Find and return the shortest palindrome you can find by performing this transformation.
//
//Example 1:
//
//Input: "aacecaaa"
//	Output : "aaacecaaa"

//1.������
//�ҵ�������ʼλ�õ�����Ĵ�
//�õ����ǻ��Ĵ��Ĳ��֣����أ��ӵ�s��ǰ��

//2.���ȵõ�s������rs
//�ҵ�s��0��ʼ����һ��λ�ã���rs�ӷ�����ʼ����ȵ�λ��
//s[0,...i,....j]
//rs[0,....i.....j]
//���s[0,...,i]��rs[i,...,j]��ȣ�˵����һ�������ǻ��Ĵ�
//����rs��ǰ�벿�ּ���

class Solution_214 {

	bool is_para(const string &s) {
		if (s.size() <= 1)
			return true;
		int left = 0;
		int right = s.size() - 1;
		while (left<right) {
			if (s[left] != s[right])
				return false;
			left++;
			right--;
		}
		return true;
	}
public:

	string shortestPalindrome_help(string s) {
		const string r(s.rbegin(), s.rend());
		const int n = s.size();
		for (int i = 0; i < n; ++i) {
			if (s.compare(0, n - i, r, i, n - i) == 0)
				return r.substr(0, i) + s;
		}
		return "";
	}
	string shortestPalindrome(string s) {

		if (s.size() <= 1)
			return s;
		string para;
		for (int length = 1; length <= s.size(); length++) {
			string t = s.substr(0, length);
			if (is_para(t))
				para = t;
		}
		if (para.size() == s.size())
			return s;
		string left = s.substr(para.size());
		reverse(left.begin(), left.end());
		return left + s;


	}
};