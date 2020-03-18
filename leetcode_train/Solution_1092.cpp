#include<string>
#include<string>
#include<vector>
using namespace std;

//Given two strings str1 and str2, return the shortest string that has both str1 and str2 as subsequences.If multiple answers exist, you may return any of them.
//
//(A string S is a subsequence of string T if deleting some number of characters from T(possibly 0, and the characters are chosen anywhere from T) results in the string S.)
//
//
//
//Example 1:
//
//Input: str1 = "abac", str2 = "cab"
//	Output : "cabac"
//	Explanation :
//	str1 = "abac" is a subsequence of "cabac" because we can delete the first "c".
//	str2 = "cab" is a subsequence of "cabac" because we can delete the last "ac".
//	The answer provided is the shortest such string that satisfies these properties.
//


//最后结果的长度就是len(A)+len(B)-lcs
//首先计算lcs的长度
//然后依次遍历lcs
//如果A当前位置与lcs当前位置不等，A的当前位置在结果中
//同理B也是
//对于都相等的位置，只需要加一个就好

class Solution {
public:
	string shortestCommonSupersequence(string str1, string str2) {
		string l = lcs(str1, str2);
		string rs;
		int str1_index = 0;
		int str2_index = 0;
		for (auto &c : l) {
			while (str1[str1_index] != c)
				rs.push_back(str1[str1_index++]);
			while (str2[str2_index] != c)
				rs.push_back(str2[str2_index++]);
			str1_index++;
			str2_index++;
			rs.push_back(c);
		}
		return rs + str1.substr(str1_index) + str2.substr(str2_index);



	}
	string lcs(string &text1, string &text2) {
		int m = text1.size();
		int n = text2.size();
		vector<vector<string>>dp(m + 1, vector<string>(n + 1));
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= n; j++) {
				if (text1[i - 1] == text2[j - 1]) {
					dp[i][j] = dp[i - 1][j - 1];
					dp[i][j].push_back(text1[i - 1]);
				}
				else
					dp[i][j] = dp[i - 1][j].size()>dp[i][j - 1].size() ? dp[i - 1][j] : dp[i][j - 1];
			}
		}
		return dp[m][n];

	}
};