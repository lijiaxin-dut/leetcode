#include<vector>
#include<set>
#include<algorithm>
using namespace std;

//Consider the string s to be the infinite wraparound string of
// "abcdefghijklmnopqrstuvwxyz", so s will look like this: 
//"...zabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcd....".
//
//Now we have another string p.Your job is to find out how many 
//unique non - empty substrings of p are present in s.In particular, 
//your input is the string p and you need to output the number of 
//different non - empty substrings of p in the string s.


//1.考虑所有长度的滑动窗口
//2.考虑以每个字符为截至字符的最长连续字串


class Solution {
public:
	int findSubstringInWraproundString_greedy(string p) {
		vector<int>count(26, 0);
		int max_length_cur = 0;
		for (int i = 0; i<p.size(); i++) {
			if (i>0 && (p[i - 1] + 1 == p[i] || (p[i - 1] == 'z'&&p[i] == 'a')))
				max_length_cur++;
			else
				max_length_cur = 1;
			int cur_index = p[i] - 'a';
			count[cur_index] = max(count[cur_index], max_length_cur);
		}
		int rs = 0;
		for (int i = 0; i<26; i++)
			rs += count[i];
		return rs;
	}
	int findSubstringInWraproundString(string p) {
		int n = p.size();
		vector<vector<bool>>dp(n, vector<bool>(n, 0));
		set<string>rs;
		for (int i = 0; i<n; i++) {
			dp[i][i] = true;
			rs.insert(p.substr(i, 1));
		}
		for (int i = 0; i<n - 1; i++) {
			if (p[i] + 1 == p[i + 1] || (p[i] == 'z'&&p[i + 1] == 'a')) {
				dp[i][i + 1] = true;
				rs.insert(p.substr(i, 2));
			}
		}
		for (int length = 3; length <= n; length++) {
			for (int i = 0; i<n; i++) {
				int j = i + length - 1;
				if (j<n&&dp[i + 1][j - 1]==true && (p[i] + 1 == p[i + 1] || (p[i] == 'z'&&p[i + 1] == 'a')) && (p[j - 1] + 1 == p[j] || (p[j - 1] == 'z'&&p[j] == 'a'))) {
					dp[i][j] = true;
					rs.insert(p.substr(i, length));
				}
			}
		}

		return rs.size();
	}
};

