#include<vector>

using namespace std;

//Given a matrix of M x N elements(M rows, N columns), return all elements of the matrix in diagonal order as shown in the below image.
//
//
//
//Example:
//
//Input:
//[
//	[1, 2, 3],
//	[4, 5, 6],
//	[7, 8, 9]
//]
//
//Output : [1, 2, 4, 7, 5, 3, 6, 8, 9]


//按照左侧边界和下侧边界去遍历


class Solution {
	vector<int>help(int iter, vector<vector<int>>& matrix, int m, int n, int cur_x, int cur_y) {
		vector<int>rs;
		while (cur_x >= 0 & cur_y<n) {
			rs.push_back(matrix[cur_x][cur_y]);
			cur_x--;
			cur_y++;
		}
		if (iter % 2 == 1)
			reverse(rs.begin(), rs.end());
		return rs;
	}
public:
	vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
		vector<int>rs;
		int m = matrix.size();
		if (m == 0)
			return rs;
		int n = matrix[0].size();
		int iter = 0;
		for (int i = 0; i<m; i++) {
			auto t = help(iter++, matrix, m, n, i, 0);
			rs.insert(rs.end(), t.begin(), t.end());
		}
		for (int j = 1; j<n; j++) {
			auto t = help(iter++, matrix, m, n, m - 1, j);
			rs.insert(rs.end(), t.begin(), t.end());
		}
		return rs;
	}
};