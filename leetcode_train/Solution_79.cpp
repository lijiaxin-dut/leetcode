#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>

using namespace std;

//Given a 2D board and a word, find if the word exists in the grid.
//
//The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring.The same letter cell may not be used more than once.
//
//Example:
//
//board =
//[
//	['A', 'B', 'C', 'E'],
//	['S', 'F', 'C', 'S'],
//	['A', 'D', 'E', 'E']
//]
//
//Given word = "ABCCED", return true.
//Given word = "SEE", return true.
//Given word = "ABCB", return false.

//��ÿһ��λ�ý���dfs����
//�ҵ�һ������
//ע��������ݷ�ʽ
//ʹ�����ô��ݲ���



bool exist(vector<vector<char>>& board, string word) {
	//�ҵ���һ����ĸ���г��ֵ�λ�ã�Ȼ��ݹ�Ѱ��
	//�������е�λ�ã���������ȵ����
	int m = board.size();
	int n = board[0].size();
	vector<vector<bool>>mark(m, vector<bool>(n, false));
	for (int i = 0; i<m; i++) {
		for (int j = 0; j<n; j++) {
			if (help(m, n, board, mark, i, j, 0, word) == true)
				return true;
		}
	}
	return false;
}
bool help(int m, int n, vector<vector<char>>& board, vector<vector<bool>>&mark, int row_index, int col_index, int word_index, string &word) {
	if (word_index == word.size())
		return true;
	//�������Ϸ������
	if (row_index >= m || col_index >= n || row_index<0 || col_index<0 || mark[row_index][col_index] == true || word[word_index] != board[row_index][col_index])
		return false;
	//����һ���У�board[row_index][col_index]�Ѿ������ʹ�
	mark[row_index][col_index] = true;
	bool rs = help(m, n, board, mark, row_index + 1, col_index, word_index + 1, word) ||
		help(m, n, board, mark, row_index - 1, col_index, word_index + 1, word) ||
		help(m, n, board, mark, row_index, col_index + 1, word_index + 1, word) ||
		help(m, n, board, mark, row_index, col_index - 1, word_index + 1, word);
	mark[row_index][col_index] = false;
	return rs;
}