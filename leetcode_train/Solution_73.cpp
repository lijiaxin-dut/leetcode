#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>

using namespace std;

//Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in - place.
//
//Example 1:
//
//Input:
//[
//	[1, 1, 1],
//	[1, 0, 1],
//	[1, 1, 1]
//]
//Output :
//	[
//		[1, 0, 1],
//		[0, 0, 0],
//		[1, 0, 1]
//	]

//使用额外的一行和一列标记出现0的行和列
//最后扫描数组，根据标记清零


//可以使用第一行和第一列作为标记
//使用两个flag标记第一行和第一列是否存在0
//然后使用第一行和第一列标记
//结束后根据标记位来判断是否将第一行、第一列清零



class Solution_73 {
public:
	void setZeroes(vector<vector<int>>& matrix) {
		if (matrix.empty())
			return;
		int m = matrix.size();
		int n = matrix[0].size();
		vector<int>row(m, -1);
		vector<int>col(n, -1);
		for (int i = 0; i<m; i++) {
			for (int j = 0; j<n; j++) {
				if (matrix[i][j] == 0) {
					row[i] = i;
					col[j] = j;
				}
			}
		}
		for (int i = 0; i<m; i++) {
			if (row[i] != -1) {
				for (int j = 0; j<n; j++) {
					matrix[i][j] = 0;
				}
			}
		}
		for (int j = 0; j<n; j++) {
			if (col[j] != -1) {
				for (int i = 0; i<m; i++) {
					matrix[i][j] = 0;
				}
			}
		}
	}
};