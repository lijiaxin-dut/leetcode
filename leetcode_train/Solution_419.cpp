#include<vector>

using namespace std;

//Given an 2D board, count how many battleships are in it.The battleships are represented with 'X's, empty slots are represented with '.'s.You may assume the following rules :
//You receive a valid board, made of only battleships or empty slots.
//Battleships can only be placed horizontally or vertically.In other words, they can only be made of the shape 1xN(1 row, N columns) or Nx1(N rows, 1 column), where N can be of any size.
//At least one horizontal or vertical cell separates between two battleships - there are no adjacent battleships.
//Example :
//	X..X
//	...X
//	...X
//	In the above board there are 2 battleships.
//	Invalid Example :
//...X
//XXXX
//...X

//1.dfs 计算多少个连通域
//修改了输入

//2.只考虑每个联通分量的第一个X
//即最左上角的位置


class Solution_419 {
	vector<int>xx{ 0, 0,1,-1 };
	vector<int>yy{ 1,-1,0, 0 };
public:
	int countBattleships_1(vector<vector<char>>& board) {
		int rs = 0;
		int m = board.size();
		int n = board[0].size();
		for (int x = 0; x<m; x++) {
			for (int y = 0; y<n; y++) {
				if (board[x][y] == '.')
					continue;
				if (x>0 && board[x - 1][y] == 'X')
					continue;
				if (y>0 && board[x][y - 1] == 'X')
					continue;
				rs++;
			}
		}
		return rs;
	}
	int countBattleships(vector<vector<char>>& board) {
		int rs = 0;
		int m = board.size();
		int n = board[0].size();
		for (int x = 0; x<m; x++) {
			for (int y = 0; y<n; y++) {
				if (board[x][y] == 'X') {
					board[x][y] = '.';
					rs++;
					dfs(board, x, y);
				}
			}
		}
		return rs;
	}
	void dfs(vector<vector<char>>& board, int x, int y) {
		int m = board.size();
		int n = board[0].size();
		for (int i = 0; i<4; i++) {
			int new_x = x + xx[i];
			int new_y = y + yy[i];
			if (new_x<0 || new_x >= m || new_y<0 || new_y >= n || board[new_x][new_y] != 'X')
				continue;
			board[new_x][new_y] = '.';
			dfs(board, new_x, new_y);
		}

	}
};