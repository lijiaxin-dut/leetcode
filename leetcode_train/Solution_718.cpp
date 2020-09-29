#include<vector>
#include<algorithm>

using namespace std;


//给两个整数数组 A 和 B ，返回两个数组中公共的、长度最长的子数组的长度。
//示例：
//输入：
//A : [1, 2, 3, 2, 1]
//	B : [3, 2, 1, 4, 7]
//	输出：3
//	解释：
//	长度最长的公共子数组是[3, 2, 1] 。



//滑动窗口
//固定两个数组的起始位置，就可以很容易的找到最长的相同部分
//分别固定其中一个数组，然后移动另一个数组即可

class Solution {
public:
	int findLength_sliding_window(vector<int>& A, vector<int>& B) {
		auto find_length = [](vector<int>&A, vector<int>&B, int startA, int startB, int length) {
			int rs = 0;
			int k = 0;
			for (int i = 0; i<length; i++) {
				if (A[startA + i] == B[startB + i]) {
					k++;
					rs = max(rs, k);
				}
				else {
					k = 0;
				}
			}
			return rs;
		};
		int m = A.size();
		int n = B.size();
		int rs = 0;
		for (int i = 0; i<m; i++) {
			int length = min(n, m - i);
			rs = max(rs, find_length(A, B, i, 0, length));
		}
		for (int i = 0; i<n; i++) {
			int length = min(m, n - i);
			rs = max(rs, find_length(A, B, 0, i, length));
		}
		return rs;
	}
	int findLength_dp(vector<int>& A, vector<int>& B) {
		int m = A.size();
		int n = B.size();
		vector<vector<int>>dp(m + 1, vector<int>(n + 1, 0));
		int rs = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (A[i - 1] == B[j - 1]) {
					dp[i][j] = dp[i - 1][j - 1] + 1;
				}
				else {
					dp[i][j] = 0;
				}
				rs = max(rs, dp[i][j]);
			}
		}
		return rs;
	}
};