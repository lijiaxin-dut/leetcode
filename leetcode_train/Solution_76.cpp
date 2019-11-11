#include<string>
#include<unordered_map>

using namespace std;
//
//Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).
//
//Example:
//
//Input: S = "ADOBECODEBANC", T = "ABC"
//	Output : "BANC"
//

//ʹ��mapͳ��t��ÿ���ַ����ֵĴ���

//����s���������ַ���map�д����Խ�

//����Լ����������>=0����˵����t�г���

//��¼���ֵĸ���

//��ÿ���ַ������ֹ�ʱ��leftָ�������ƶ���ֱ�����ܰ���t�е�ÿ���ַ�


class Solution_76 {
public:
	string minWindow(string s, string t) {
		unordered_map<char, int>letter_cnt;
		for (auto c : t)
			letter_cnt[c]++;
		int left = 0;
		int cnt = 0;
		string rs;
		int min_length = INT_MAX;
		for (int i = 0; i<s.size(); i++) {
			if (--letter_cnt[s[i]] >= 0)
				cnt++;
			while (cnt == t.size()) {
				if (min_length>i - left + 1) {
					min_length = i - left + 1;
					rs = s.substr(left, i - left + 1);
				}
				if (++letter_cnt[s[left]]>0)
					cnt--;
				left++;
			}
		}
		return rs;

	}
};

