#include<string>
#include<vector>

using namespace std;

//Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.
//
//Example 1:
//
//Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
//	Output : true
//	Example 2 :
//
//	Input : s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
//	Output : false

//1.
//dfs ������еĿ���  TLE
//2.dp
//dp[i][j]��ʾs1[0,i)��s2[0,j)�Ƿ񹹳ɴ�
//��i==0��j==0ʱ����Ϊ�գ�dp[0][0]=true
//j==0ʱ��s1��ǰ�벿����s3ǰ�벿�ֽ��бȽ�
//i==0ʱ��s2��ǰ�벿����s3ǰ�벿�ֽ��бȽ�

//��dp[i][j]Ϊtrueʱ��dp[i-1][j]��dp[i][j-1]������һ��Ϊ��

class Solution_97 {
public:
	bool isInterleave_dp(string s1, string s2, string s3) {

		if (s1.size() + s2.size() != s3.size())
			return false;
		vector<vector<bool>>dp(s1.size() + 1, vector<bool>(s2.size() + 1, false));
		dp[0][0] = true;
		//j=0�����
		for (int i = 1; i <= s1.size(); i++) {
			dp[i][0] = dp[i - 1][0] && (s1[i - 1] == s3[i - 1]);
		}
		for (int j = 1; j <= s2.size(); j++) {
			dp[0][j] = dp[0][j - 1] && (s2[j - 1] == s3[j - 1]);
		}
		for (int i = 1; i <= s1.size(); i++) {
			for (int j = 1; j <= s2.size(); j++) {
				if (s1[i - 1] == s3[i + j - 1] && dp[i - 1][j] == true)
					dp[i][j] = true;
				if (s2[j - 1] == s3[i + j - 1] && dp[i][j - 1] == true)
					dp[i][j] = true;
			}
		}
		return dp[s1.size()][s2.size()];

	}
	bool isInterleave(string s1, string s2, string s3) {

		return help(s1, 0, s2, 0, s3, 0);


	}
	bool help(string &s1, int s1_index, string &s2, int s2_index, string &s3, int s3_index) {
		if (s1_index == s1.size() && s2_index == s2.size() && s3_index == s3.size())
			return true;
		if (s1_index>s1.size() && s2_index>s2.size() && s3_index>s3.size())
			return false;
		if (s1[s1_index] != s3[s3_index] && s2[s2_index] != s3[s3_index])
			return false;
		bool is_s1 = false;
		if (s1[s1_index] == s3[s3_index]) {
			is_s1 = help(s1, s1_index + 1, s2, s2_index, s3, s3_index + 1);
		}
		bool is_s2 = false;
		if (s2[s2_index] == s3[s3_index]) {
			is_s2 = help(s1, s1_index, s2, s2_index + 1, s3, s3_index + 1);
		}
		return is_s1 || is_s2;
	}
};