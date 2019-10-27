#include<iostream>
#include<vector>
#include<stack>

using namespace std;

//Given a string, your task is to count how many palindromic substrings in this string.
//
//The substrings with different start indexes or end indexes are counted as different substrings even they consist of same characters.
//
//Example 1:
//
//Input: "abc"
//	Output : 3
//	Explanation : Three palindromic strings : "a", "b", "c".


//1.
//dp[i][j]���i..j�Ƿ��ǻ����ִ�
//dp[i][j]=1     dp[i+1][j-1]==1 &&s[i]==s[j]

// Expand Around Center 

//�������ַ����е�ÿһ���ַ����������Ĵ��м��λ�ã�
//Ȼ����������ɢ��ÿ���ɹ�ƥ���������������ַ������ res ����1��Ȼ���ٱȽ���һ�ԡ�
//����������ż�������


class Solution_647 {
public:
	int countSubstrings(string s) {
		int n = s.size();
		vector<vector<int>>dp(n, vector<int>(n, 0));
		int rs = 0;
		for (int i = 0; i<n; i++) {
			dp[i][i] = 1;
			rs++;
			if (i != 0 && s[i] == s[i - 1]) {
				dp[i - 1][i] = 1;
				rs++;
			}
		}
		for (int length = 3; length <= n; length++) {
			for (int start = 0; start<n + 1 - length; start++) {
				int end = start + length - 1;
				if (s[start] == s[end] && dp[start + 1][end - 1] == true) {
					dp[start][end] = true;
					rs++;
				}
			}
		}
		return rs;

	}

	int countSubstrings_2(string s) {
		int rs = 0;
		for (int i = 0; i<s.size(); i++) {
			help(s, i, i, rs);
			help(s, i, i + 1, rs);
		}
		return rs;
	}
	void help(string &s, int i, int j, int &rs) {

		while (i >= 0 && j<s.size() && s[i] == s[j]) {
			rs++;
			i--;
			j++;
		}
	}

};