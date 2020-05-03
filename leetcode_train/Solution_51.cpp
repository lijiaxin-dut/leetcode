#include<iostream>
#include<vector>
#include<queue>

using namespace std;

//The n - queens puzzle is the problem of placing n queens on an n��n chessboard such that no two queens attack each other.
//
//
//
//Given an integer n, return all distinct solutions to the n - queens puzzle.
//
//Each solution contains a distinct board configuration of the n - queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.


//ͬһ�����С����л�б�߶����ܴ��ڻʺ�
//�ݹ飬������еĿ��ܣ�ÿ�ε�һ��λ�ã��жϵ�ǰλ���ܷ���ûʺ�
//�жϵ�ǰ�к������Խ���


class Solution_51 {
public:
	vector<vector<string>> solveNQueens(int n) {
		
		vector<vector<string>>rs;
		vector<string>board(n, string(n, '.'));
		help(rs, board, 0, n);
		return rs;
	}
	bool feasible(vector<string>&board, int cur_row, int n, int cur_col) {
		//��ǰ��
		for (int r = 0; r<cur_row; r++) {
			if (board[r][cur_col] == 'Q')
				return false;
		}
		//���Խ���
		int i = cur_row - 1, j = cur_col - 1;
		while (i >= 0 && j >= 0) {
			if (board[i][j] == 'Q')
				return false;
			i--;
			j--;
		}
		i = cur_row + 1;
		j = cur_col + 1;
		while (i<n&&j<n) {
			if (board[i][j] == 'Q')
				return false;
			i++;
			j++;
		}

		i = cur_row + 1;
		j = cur_col - 1;
		while (i<n&&j >= 0) {
			if (board[i][j] == 'Q')
				return false;
			i++;
			j--;
		}
		i = cur_row - 1;
		j = cur_col + 1;
		while (i >= 0 && j<n) {
			if (board[i][j] == 'Q')
				return false;
			i--;
			j++;
		}


		return true;

	}
	void help(vector<vector<string>>&rs, vector<string>&board, int cur_row, int n) {
		if (cur_row == n) {
			rs.push_back(board);
			return;
		}
		//��ǰ�е�ÿһ��
		for (int col = 0; col<n; col++) {
			if (feasible(board, cur_row, n, col) == true) {
				board[cur_row][col] = 'Q';
				help(rs, board, cur_row + 1, n);
				board[cur_row][col] = '.';
			}
		}
	}
};