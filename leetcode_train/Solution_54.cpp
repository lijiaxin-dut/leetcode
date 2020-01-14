#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>

using namespace std;

//Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

//Example 1:
//
//Input:
//[
//	[1, 2, 3],
//	[4, 5, 6],
//	[7, 8, 9]
//]
//Output : [1, 2, 3, 6, 9, 8, 7, 4, 5]

//使用索引记录轮次
//每次开始的地方于轮次相关


class Solution_54 {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		int n = matrix.size();
		vector<int>rs;
		if (n == 0)
			return rs;
		int m = matrix[0].size();
		int iterator_time = 0;
		int total_number = m*n;
		while (rs.size()<total_number) {
			int cur_row = iterator_time;
			int cur_col = iterator_time;

			while (cur_col<m - iterator_time&&rs.size()<total_number) {
				rs.push_back(matrix[cur_row][cur_col++]);
			}
			cur_row++;
			cur_col--;
			while (cur_row<n - iterator_time&&rs.size()<total_number) {
				rs.push_back(matrix[cur_row++][cur_col]);
			}
			cur_col--;
			cur_row--;
			while (cur_col >= iterator_time&&rs.size()<total_number) {
				rs.push_back(matrix[cur_row][cur_col--]);
			}
			cur_col++;
			cur_row--;
			while (cur_row>iterator_time&&rs.size()<total_number) {
				rs.push_back(matrix[cur_row--][cur_col]);
			}
			iterator_time++;
		}
		return rs;
	}
};
//int main() {
//	vector<vector<int>>matrix{ { 1, 2, 3, 4 },{ 5, 6, 7, 8 },{ 9,10,11,12 } };
//	Solution_54 s;
//	s.spiralOrder(matrix);
//}