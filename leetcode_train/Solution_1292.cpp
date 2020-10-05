#include<vector>
#include<algorithm>
using namespace std;
//给你一个大小为 m x n 的矩阵 mat 和一个整数阈值 threshold。
//
//请你返回元素总和小于或等于阈值的正方形区域的最大边长；如果没有这样的正方形区域，则返回 0 。

//1.穷举所有的可能
//2.二分搜索
class Solution {
public:
	int maxSideLength(vector<vector<int>>& mat, int threshold) {
		int m = mat.size();
		int n = mat[0].size();
		vector<vector<int>>pre_sum(m, vector<int>(n, 0));
		pre_sum[0][0] = mat[0][0];
		for (int i = 1; i<m; i++) {
			pre_sum[i][0] = pre_sum[i - 1][0] + mat[i][0];
		}
		for (int j = 1; j<n; j++) {
			pre_sum[0][j] = pre_sum[0][j - 1] + mat[0][j];
		}
		for (int i = 1; i<m; i++) {
			for (int j = 1; j<n; j++) {
				pre_sum[i][j] = pre_sum[i][j - 1] + pre_sum[i - 1][j] - pre_sum[i - 1][j - 1] + mat[i][j];
			}
		}
		int rs = 0;
		int left = 0;
		int right = min(m, n);
		while (left <= right) {
			int mid = left + (right - left) / 2;
			int cur_sum = 0;
			for (int i = 0; i < m; i++) {
				if (i + mid >= m)
					break;
				for (int j = 0; j < n; j++) {
					int cur_row = i + mid, cur_col = j + mid;
					if (cur_col >= n)
						break;
					if (i == 0 && j == 0) {
						cur_sum = pre_sum[cur_row][cur_col];
					}
					else if (i == 0) {
						cur_sum = pre_sum[cur_row][cur_col] - pre_sum[cur_row][j - 1];
					}
					else if (j == 0) {
						cur_sum = pre_sum[cur_row][cur_col] - pre_sum[i - 1][cur_col];
					}
					else {
						cur_sum = pre_sum[cur_row][cur_col] + pre_sum[i - 1][j - 1]
							- pre_sum[i - 1][cur_col] - pre_sum[cur_row][j - 1];
					}
					if (cur_sum <= threshold)
						rs = max(rs, cur_col - j + 1);
				}
			}
			if (cur_sum <= threshold) {
				left = mid + 1;
			}
			else {
				right = mid - 1;
			}
		}
		return rs;
	}
};