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
	string longestCommonSubsequence(string text1, string text2) {
		int n1 = text1.size();
		int n2 = text2.size();
		vector<vector<int>>dp(n1 + 1, vector<int>(n2 + 1, 0));
		vector<vector<int>>mark(n1 + 1, vector<int>(n2 + 1, 0));
		for (int i = 1; i <= n1; i++) {
			for (int j = 1; j <= n2; j++) {
				if (text1[i - 1] == text2[j - 1]) {
					dp[i][j] = dp[i - 1][j - 1] + 1;
					mark[i][j] = 0;
				}
				else if (dp[i - 1][j] >= dp[i][j - 1]) {
					dp[i][j] = dp[i - 1][j];
					mark[i][j] = 1;
				}
				else if (dp[i - 1][j]< dp[i][j - 1]) {
					dp[i][j] = dp[i][j - 1];
					mark[i][j] = -1;
				}
			}
		}
		string rs;
		while (n1 >= 1 && n2 >= 1) {
			if (mark[n1][n2] == 0) {
				rs += text1[n1 - 1];
				n1--;
				n2--;
			}
			else if (mark[n1][n2] == 1) {
				n1--;
			}
			else if (mark[n1][n2] == -1) {
				n2--;
			}
		}
		reverse(rs.begin(), rs.end());
		return rs;
	}
public:
	string shortestCommonSupersequence(string str1, string str2) {
		string  common_sequence = longestCommonSubsequence(str1, str2);
		int str1_index = 0;
		int str2_index = 0;
		string rs;
		for (auto c : common_sequence) {
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
};