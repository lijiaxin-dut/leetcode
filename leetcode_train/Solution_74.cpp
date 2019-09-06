#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>

using namespace std;


//Write an efficient algorithm that searches for a value in an m x n matrix.
//This matrix has the following properties :
//
//Integers in each row are sorted from left to right.
//The first integer of each row is greater than the last integer of the previous row.

//先找到对应的行，在找到对应的列
//在找行的过程中
//若在第一列没有找到target
//所对应的行为high_row

//matrix = [
//	[1, 3, 5, 7],
//		[10, 11, 16, 20],
//		[23, 30, 34, 50]
//]
//target = 17

//step 1
//low =0 high =2 mid =1
//10<target    low=mid+1=2
//low=2 high=2 mid=2
//23>target    high=mid-1
//循环结束
//high所在的行就是我们要找的行




class Solution_74 {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		if (matrix.empty() || matrix[0].empty())
			return false;
		if (target < matrix[0][0] || target > matrix.back().back())
			return false;
		int m = matrix.size();
		int n = matrix[0].size();
		int row_low = 0;
		int row_high = m - 1;
		while (row_low <= row_high) {
			int mid = (row_low + row_high) / 2;
			if (matrix[mid][0] == target)
				return true;
			else if (matrix[mid][0]>target) {
				row_high = mid - 1;
			}
			else
				row_low = mid + 1;

		}
		int col_right = n - 1;
		int col_left = 0;
		while (col_left <= col_right) {
			int mid = (col_right + col_left) / 2;
			if (matrix[row_high][mid] == target)
				return true;
			else if (matrix[row_high][mid]>target)
				col_right = mid - 1;
			else
				col_left = mid + 1;
		}
		return false;

	}
};
//int main(){
//	Solution_74 s;
//	vector<vector<int>> matrix = {
//		{1, 3, 5, 7},
//		{ 10, 11, 16, 20 },
//		{ 23, 30, 34, 50 }
//	};
//	s.searchMatrix(matrix,16);
//}