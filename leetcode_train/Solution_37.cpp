#include<vector>

using namespace std;

//Write a program to solve a Sudoku puzzle by filling the empty cells.
//
//A sudoku solution must satisfy all of the following rules :
//
//Each of the digits 1 - 9 must occur exactly once in each row.
//Each of the digits 1 - 9 must occur exactly once in each column.
//Each of the the digits 1 - 9 must occur exactly once in each of the 9 3x3 sub - boxes of the grid.


//递归求解
//将一个数字放入位置后，进行可行性判断

//给定一个位置，对应的小块的坐标
//for(int i=0;i<9;i++)
	//[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3]


class Solution {
public:
	void solveSudoku(vector<vector<char>>& board) {
		solve(board);
	}
	bool solve(vector<vector<char>>& board) {
		for (int i = 0; i<9; i++) {
			for (int j = 0; j<9; j++) {
				if (board[i][j] == '.') {
					for (char c = '1'; c <= '9'; c++) {
						if (is_valid(board, i, j, c)) {
							board[i][j] = c;
							if (solve(board))
								return true;
							else
								board[i][j] = '.';
						}
					}
					return false;
				}
			}
		}
		return true;
	}
	bool is_valid(vector<vector<char>>& board, int row, int col, char c) {
		for (int i = 0; i<9; i++) {
			if (board[i][col] != '.' && board[i][col] == c)
				return false;
			if (board[row][i] != '.' && board[row][i] == c)
				return false;
			if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] != '.' &&
				board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c)
				return false;
		}
		return true;
	}
};