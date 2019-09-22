#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>


using namespace std;


//Determine if a 9x9 Sudoku board is valid.Only the filled cells need to be validated according to the following rules :
//
//Each row must contain the digits 1 - 9 without repetition.
//Each column must contain the digits 1 - 9 without repetition.
//Each of the 9 3x3 sub - boxes of the grid must contain the digits 1 - 9 without repetition.



//分别判断行、列、和小矩形

class Solution_36 {
	void clear(vector<int>&hash_map, int n) {
		for (int i = 0; i<=n; i++) {
			hash_map[i] = 0;
		}

	}
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		vector<int>hash_map(10, 0);
		int n = board.size();
		//行
		for (int i = 0; i<n; i++) {
			clear(hash_map, n);
			for (int j = 0; j<n; j++) {
				if (board[i][j] != '.') {
					if (hash_map[board[i][j] - '0'] != 0)
						return false;
					hash_map[board[i][j] - '0']++;
				}
			}
		}
		//列
		for (int i = 0; i<n; i++) {
			clear(hash_map, n);
			for (int j = 0; j<n; j++) {
				if (board[j][i] != '.') {
					if (hash_map[board[j][i] - '0'] != 0)
						return false;
					hash_map[board[j][i] - '0']++;
				}
			}
		}
		//小矩形
		vector<int>x_start{ 0,3,6 };
		vector<int>y_start{ 0,3,6 };
		for (int x : x_start) {
			for (int y : y_start) {
				clear(hash_map, n);
				for (int i = x; i<x + 3; i++) {
					for (int j = y; j<y + 3; j++) {
						if (board[i][j] != '.') {
							if (hash_map[board[i][j] - '0'] != 0)
								return false;
							hash_map[board[i][j] - '0']++;
						}
					}
				}
			}
		}
		return true;




	}
};