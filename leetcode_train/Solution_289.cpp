#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>
#include<unordered_map>

using namespace std;

//According to the Wikipedia's article: "The Game of Life, also known simply as Life,
// is a cellular automaton devised by the British mathematician John Horton Conway in 1970."

//Given a board with m by n cells, each cell has an initial state live(1) or dead(0).
//Each cell interacts with its eight neighbors(horizontal, vertical, diagonal) using the following four rules(taken from the above Wikipedia article) :

//	Any live cell with fewer than two live neighbors dies, as if caused by under - population.
//	Any live cell with two or three live neighbors lives on to the next generation.
//	Any live cell with more than three live neighbors dies, as if by over - population..
//	Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
//	Write a function to compute the next state(after one update) of the board given its current state.
//The next state is created by applying the above rules simultaneously to every cell in the current state, 
//where births and deaths occur simultaneously.

//o(m*n)的空间复杂度


//o(1)空间复杂度
//标记四个状态
//状态0： 死细胞转为死细胞
//
//状态1： 活细胞转为活细胞
//
//状态2： 活细胞转为死细胞
//
//状态3： 死细胞转为活细胞

//遍历过程中如果遇到2或者1，live_number++

//for (int i = 0; i<m; i++) {
//	for (int j = 0; j<n; j++) {
//		int live_number = find_live_number(board, i, j, m, n);
//		//死细胞转为活
//		if (board[i][j] == 0 && live_number == 3)
//			board[i][j] = 3;
//		//活细胞转为死
//		else if (board[i][j] == 1 && (live_number<2 || live_number>3))
//			board[i][j] = 2;
//	}
//}

class Solution_289 {
public:
	void gameOfLife(vector<vector<int>>& board) {
		if (board.empty())
			return;
		int m = board.size();
		int n = board[0].size();
		vector<vector<int>>rs(m, vector<int>(n, 0));
		for (int i = 0; i<m; i++) {
			for (int j = 0; j<n; j++) {
				int live_number = find_live_number(board, i, j, m, n );
				rs[i][j] = board[i][j];
				if (board[i][j] == 1) {
					if (live_number<2)
						rs[i][j] = 0;
					else if (live_number >= 2 && live_number <= 3)
						rs[i][j] = 1;
					else if (live_number>3)
						rs[i][j] = 0;
				}
				else {
					if (live_number == 3)
						rs[i][j] = 1;
				}

			}
		}
		board = rs;


	}
	int find_live_number(vector<vector<int>>& board, int row_index, int col_index, int m, int n) {
		int live_number = 0;
		if (row_index - 1 >= 0 && col_index - 1 >= 0 && board[row_index - 1][col_index - 1] == 1)
			live_number++;
		if (row_index - 1 >= 0 && board[row_index - 1][col_index] == 1)
			live_number++;
		if (row_index - 1 >= 0 && col_index + 1<n&&board[row_index - 1][col_index + 1] == 1)
			live_number++;
		if (row_index + 1<n&&col_index - 1 >= 0 && board[row_index + 1][col_index - 1] == 1)
			live_number++;
		if (row_index + 1<n&&board[row_index + 1][col_index] == 1)
			live_number++;
		if (row_index + 1<n&&col_index + 1<n&&board[row_index + 1][col_index + 1] == 1)
			live_number++;
		if (col_index - 1 >= 0 && board[row_index][col_index - 1] == 1)
			live_number++;
		if (col_index + 1<n&&board[row_index][col_index + 1] == 1)
			live_number++;
		return live_number;
	}
	int find_live_number_(vector<vector<int>>& board, int row_index, int col_index, int m, int n) {
		int live_number = 0;
		if (row_index - 1 >= 0 && col_index - 1 >= 0 && (board[row_index - 1][col_index - 1] == 1 || board[row_index - 1][col_index - 1] == 2))
			live_number++;
		if (row_index - 1 >= 0 && (board[row_index - 1][col_index] == 1 || board[row_index - 1][col_index] == 2))
			live_number++;
		if (row_index - 1 >= 0 && col_index + 1 < n && (board[row_index - 1][col_index + 1] == 1 || board[row_index - 1][col_index + 1] == 2))
			live_number++;
		if (row_index + 1 < m&&col_index - 1 >= 0 && (board[row_index + 1][col_index - 1] == 1 || board[row_index + 1][col_index - 1] == 2))
			live_number++;
		if (row_index + 1 < m && (board[row_index + 1][col_index] == 1 || board[row_index + 1][col_index] == 2))
			live_number++;
		if (row_index + 1 < m&&col_index + 1 < n && (board[row_index + 1][col_index + 1] == 1 || board[row_index + 1][col_index + 1] == 2))
			live_number++;
		if (col_index - 1 >= 0 && (board[row_index][col_index - 1] == 1 || board[row_index][col_index - 1] == 2))
			live_number++;
		if (col_index + 1 < n && (board[row_index][col_index + 1] == 1 || board[row_index][col_index + 1] == 2))
			live_number++;
		return live_number;
	}

};

//int main() {
//	vector<vector<int>>nums{ { 0,0 }/*, { 0,0,1 }, { 1,1,1 }, { 0,0,0 }*/ };
//	Solution_289 s;
//	s.gameOfLife(nums);
//	
//}