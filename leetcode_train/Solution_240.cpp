#include<vector>

using namespace std;

//Write an efficient algorithm that searches for a value in an m x n matrix.This matrix has the following properties :
//
//Integers in each row are sorted in ascending from left to right.
//Integers in each column are sorted in ascending from top to bottom.

//从右上角或者左下角开始搜索
//每次根据大小关系删除一行即可


class Solution_240 {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int m = matrix.size();
		if (m == 0)
			return false;
		int n = matrix[0].size();
		int row_index = 0;
		int col_index = n - 1;
		while (row_index<m&&col_index >= 0) {
			if (matrix[row_index][col_index] == target)
				return true;
			else if (matrix[row_index][col_index]>target)
				col_index--;
			else
				row_index++;
		}
		return false;
	}
};