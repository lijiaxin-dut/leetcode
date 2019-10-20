#include<vector>

using namespace std;

//Given a 2D matrix matrix, find the sum of the elements inside the rectangle defined by its upper left corner(row1, col1) and lower right corner(row2, col2).
//
//Range Sum Query 2D
//The above rectangle(with the red border) is defined by(row1, col1) = (2, 1) and (row2, col2) = (4, 3), which contains sum = 8.
//
//Example:
//Given matrix = [
//	[3, 0, 1, 4, 2],
//		[5, 6, 3, 2, 1],
//		[1, 2, 0, 1, 5],
//		[4, 1, 0, 1, 7],
//		[1, 0, 3, 0, 5]
//]
//
//sumRegion(2, 1, 4, 3) -> 8
//sumRegion(1, 1, 2, 2) -> 11
//sumRegion(1, 2, 2, 4) -> 12


//_catch[i][j]表示以右下角位端点的矩形
//sum[row1,col1,row2,col2] _catch[row2][col2] - _catch[row1 - 1][col2] - s_2 = _catch[row2][col1 - 1] + _catch[row1 - 1][col1 - 1];



class NumMatrix {
	vector<vector<int>>_catch;
public:
	NumMatrix(vector<vector<int>>& matrix) {
		int n = matrix.size();
		if (n != 0) {
			int m = matrix[0].size();
			_catch.resize(n, vector<int>(m, 0));
			_catch[0][0] = matrix[0][0];
			for (int i = 1; i<n; i++) {
				_catch[i][0] = _catch[i - 1][0] + matrix[i][0];
			}
			for (int j = 1; j<m; j++) {
				_catch[0][j] = _catch[0][j - 1] + matrix[0][j];
			}
			for (int i = 1; i<n; i++) {
				for (int j = 1; j<m; j++) {
					_catch[i][j] = _catch[i][j - 1] + _catch[i - 1][j] - _catch[i - 1][j - 1] + matrix[i][j];
				}
			}
		}
	}

	int sumRegion(int row1, int col1, int row2, int col2) {
		int s_1 = 0;
		if (row1>0) {
			s_1 = _catch[row1 - 1][col2];
		}
		int s_2 = 0;
		if (col1>0) {
			s_2 = _catch[row2][col1 - 1];
		}
		int s_3 = 0;
		if (row1>0 && col1>0) {
			s_3 = _catch[row1 - 1][col1 - 1];
		}
		return _catch[row2][col2] - s_2 - s_1 + s_3;
	}
};

/**
* Your NumMatrix object will be instantiated and called as such:
* NumMatrix* obj = new NumMatrix(matrix);
* int param_1 = obj->sumRegion(row1,col1,row2,col2);
*/

int main() {
	vector<vector<int>>m{ { 3, 0, 1, 4, 2 }, \
	{ 5, 6, 3, 2, 1 } ,{ 1, 2, 0, 1, 5 } ,{ 4, 1, 0, 1, 7 } ,{ 1, 0, 3, 0, 5 } };
	NumMatrix mmm(m);
	mmm.sumRegion( 2,1,4,3 );
}