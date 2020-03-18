#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>

using namespace std;



//Given a string and a string dictionary, find the longest string in the dictionary 
//that can be formed by deleting some characters of the given string. If there are more 
//than one possible results, return the longest word with the smallest lexicographical order. 
//If there is no possible result, return the empty string.



class Solution_524 {
	string substring;
	//返回最长公共子序列
	int lcs(string a, string b) {
		int m = a.size();
		int n = b.size();
		vector<vector<int>>c(m + 1, vector<int>(n + 1));
		vector<vector<int>>mark(m + 1, vector<int>(n + 1,-1));
		for (int i = 0; i <= m; i++)
			c[i][0] = 0;
		for (int i = 0; i <= n; i++)
			c[0][i] = 0;
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= n; j++) {
				if (a[i - 1] == b[j - 1]) {
					c[i][j] = c[i - 1][j - 1] + 1;
					mark[i][j] = 2;
				}
				else {
					if (c[i - 1][j] > c[i][j - 1]) {
						c[i][j] = c[i - 1][j];
						mark[i][j] = 1;
					}
					else {						
						c[i][j] = c[i][j - 1];
						mark[i][j] = 0;
					}
				}
			}
		}
		int rs = c[m][n];
		substring.clear();
		while (true) {
			if (mark[m][n] == 2) {
				if (c[m][n] != c[m - 1][n - 1]) {
					substring += a[m - 1];
				}
				m--;
				n--;
			}
			else if (mark[m][n] == 1)
			{	
				if (c[m][n] != c[m-1][n]) {
					substring += a[m - 1];
				}
				m--;
			}
			else if (mark[m][n] == 0) {		
				if (c[m][n] != c[m][n-1]) {
					substring += a[m - 1];
				}
				n--;
			}
			if (m == 0 || n == 0)
				break;
		}
		reverse(substring.begin(), substring.end());
		return rs;
	}
public:
	//判断d中的字符串是否是s的子序列，在所有子序列中返回一个最长的
	bool is_subsequence(string &s1, string &s2) {
		int j = 0;
		for (int i = 0; i<s1.size() && j<s2.size(); i++)
			if (s1[i] == s2[j])
				j++;
		return j == s2.size();
	}
public:
	string findLongestWord(string s, vector<string>& d) {
		sort(d.begin(), d.end(), [](string a, string b) {
			return a.size()>b.size() || (a.size() == b.size() && a<b);
		});
		for (int i = 0; i<d.size(); i++) {
			if (is_subsequence(s, d[i]))
				return d[i];
		}
		return "";
	}
};
//
//int main() {
//	Solution_524 s;
//	string ss ="aewfafwafjlwajflwajflwafj";
//	vector<string>d{ "apple","ewaf","awefawfwaf","awef","awefe","ewafeffewafewf" };
//	cout<<s.findLongestWord(ss, d);
//}