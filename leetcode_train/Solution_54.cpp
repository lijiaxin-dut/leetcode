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




class Solution_54 {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		if (matrix.empty())
			return vector<int>();
		int m = matrix.size();
		int n = matrix[0].size();
		int mn = m*n;
		int row_index = 0;
		int col_index = 0;
		vector<int>rs;
		int iterator_index = 0;
		while (true) {
			while (col_index<n - iterator_index) {
				rs.push_back(matrix[row_index][col_index++]);
			}
			if (rs.size() == mn)
				break;
			col_index--;
			row_index++;
			while (row_index<m - iterator_index) {
				rs.push_back(matrix[row_index++][col_index]);
			}
			if (rs.size() == mn)
				break;
			row_index--;
			col_index--;
			while (col_index >= iterator_index) {
				rs.push_back(matrix[row_index][col_index--]);
			}
			if (rs.size() == mn)
				break;
			col_index++;
			row_index--;
			while (row_index > iterator_index) {
				rs.push_back(matrix[row_index--][col_index]);
			}
			if (rs.size() == mn)
				break;
			row_index++;
			col_index++;
			iterator_index++;
		}
		return rs;
	}
};
//int main() {
//	vector<vector<int>>matrix{ { 1, 2, 3, 4 },{ 5, 6, 7, 8 },{ 9,10,11,12 } };
//	Solution_54 s;
//	s.spiralOrder(matrix);
//}