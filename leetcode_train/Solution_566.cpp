#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>

using namespace std;

//In MATLAB, there is a very useful function called 'reshape', which can reshape a
// matrix into a new one with different size but keep its original data.

//You're given a matrix represented by a two-dimensional array, 
//and two positive integers r and c representing the row number and column 
//number of the wanted reshaped matrix, respectively.
//
//The reshaped matrix need to be filled with all the elements of the original 
//matrix in the same row - traversing order as they were.
//
//If the 'reshape' operation with given parameters is possible and legal, 
//output the new reshaped matrix; Otherwise, output the original matrix.
//
//Example 1:
//Input:
//nums =
//[[1, 2],
//[3, 4]]
//r = 1, c = 4
//Output :
//	[[1, 2, 3, 4]]
//Explanation :
//	The row - traversing of nums is[1, 2, 3, 4].The new reshaped matrix is a 1 * 4 matrix, fill it row by row by using the previous list.
//

class Solution_566 {
public:
	vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
		int m = nums.size();
		if (m == 0)
			return nums;
		int n = nums[0].size();
		if (m*n != r*c)
			return nums;

		vector<vector<int>>rs(r, vector<int>(c));
		int row_index = 0;
		int col_index = 0;
		for (int i = 0; i<m; i++) {
			for (int j = 0; j<n; j++) {
				if (col_index == c)
				{
					row_index++;
					col_index = 0;
				}
				rs[row_index][col_index++] = nums[i][j];

			}
		}
		return rs;
	}
};