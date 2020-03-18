#include<vector>

using namespace std;

//Let's play the minesweeper game (Wikipedia, online game)!
//
//You are given a 2D char matrix representing the game board. 'M' represents an unrevealed mine, 'E' represents an unrevealed empty square, 'B' represents a revealed blank square that has no adjacent(above, below, left, right, and all 4 diagonals) mines, digit('1' to '8') represents how many mines are adjacent to this revealed square, and finally 'X' represents a revealed mine.
//
//Now given the next click position(row and column indices) among all the unrevealed squares('M' or 'E'), return the board after revealing this position according to the following rules :
//
//If a mine('M') is revealed, then the game is over - change it to 'X'.
//If an empty square('E') with no adjacent mines is revealed, then change it to revealed blank('B') and all of its adjacent unrevealed squares should be revealed recursively.
//If an empty square('E') with at least one adjacent mine is revealed, then change it to a digit('1' to '8') representing the number of adjacent mines.
//Return the board when no more squares will be revealed.
//
//
//Example 1:
//
//Input:
//
//[['E', 'E', 'E', 'E', 'E'],
//['E', 'E', 'M', 'E', 'E'],
//['E', 'E', 'E', 'E', 'E'],
//['E', 'E', 'E', 'E', 'E']]
//
//Click : [3, 0]
//
//	Output :
//
//	[['B', '1', 'E', '1', 'B'],
//	['B', '1', 'M', '1', 'B'],
//	['B', '1', '1', '1', 'B'],
//	['B', 'B', 'B', 'B', 'B']]


//dfs，对于周围没有地雷的邻居，继续dfs
//有地雷的邻居，只修改面板值


class Solution {
	vector<int>xx{ 1,-1,0,0,-1,1,-1,1 };
	vector<int>yy{ 0,0,1,-1,-1,1,1,-1 };
	int count_mine(int x, int y, vector<vector<char>>& board) {
		int rs = 0;
		int m = board.size();
		int n = board[0].size();
		for (int i = 0; i<8; i++) {
			int new_x = x + xx[i];
			int new_y = y + yy[i];
			if (new_x<0 || new_x >= m || new_y<0 || new_y >= n)
				continue;
			if (board[new_x][new_y] == 'M')
				rs++;
		}
		return rs;

	}
public:
	vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
		int x = click[0];
		int y = click[1];
		if (board[x][y] == 'M') {
			board[x][y] = 'X';
			return board;
		}


		int neigh_mine = count_mine(x, y, board);
		if (neigh_mine == 0) {
			board[x][y] = 'B';
			dfs(x, y, board);
		}
		else {
			board[x][y] = (neigh_mine + '0');
		}

		return board;

	}
	void dfs(int x, int y, vector<vector<char>>& board) {
		int m = board.size();
		int n = board[0].size();
		for (int i = 0; i<8; i++) {
			int new_x = x + xx[i];
			int new_y = y + yy[i];
			if (new_x<0 || new_x >= m || new_y<0 || new_y >= n)
				continue;
			if (board[new_x][new_y] == 'E') {
				int neigh_mine = count_mine(new_x, new_y, board);
				if (neigh_mine == 0) {
					board[new_x][new_y] = 'B';
					dfs(new_x, new_y, board);
				}
				else {
					board[new_x][new_y] = (neigh_mine + '0');
				}

			}

		}
	}
};