#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>

using namespace std;

//Given a positive integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.
//
//Example:
//
//Input: 3
//	Output :
//	[
//		[1, 2, 3],
//		[8, 9, 4],
//		[7, 6, 5]
//	]

class Solution_59 {
public:
	vector<vector<int>> generateMatrix(int n) {
		if (n == 0)
			return vector<vector<int>>();
		vector<vector<int>>rs(n, vector<int>(n, 0));
		int nn = n*n;
		int current_value = 1;
		int current_row = 0;
		int current_col = 0;
		int iterator_time = 0;
		while (current_value <= nn) {
			while (current_col<n - iterator_time)
				rs[current_row][current_col++] = current_value++;
			current_col--;
			current_row++;
			if (current_value>nn)
				break;
			while (current_row<n - iterator_time)
				rs[current_row++][current_col] = current_value++;
			current_row--;
			current_col--;
			if (current_value>nn)
				break;
			while (current_col >= iterator_time)
				rs[current_row][current_col--] = current_value++;
			current_col++;
			current_row--;
			if (current_value>nn)
				break;
			while (current_row>iterator_time)
				rs[current_row--][current_col] = current_value++;
			current_col++;
			current_row++;
			iterator_time++;
			if (current_value>nn)
				break;
		}
		return rs;
	}
};

//int main() {
//	Solution_59 s; 
//	s.generateMatrix(3);
//}