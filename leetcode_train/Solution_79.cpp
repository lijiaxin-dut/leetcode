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

//对每一个位置进行dfs搜索
//找到一个即可
//注意参数传递方式
//使用引用传递参数



bool exist(vector<vector<char>>& board, string word) {
	//找到第一个字母所有出现的位置，然后递归寻找
	//遍历所有的位置，跳过不相等的情况
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
	//跳过不合法的情况
	if (row_index >= m || col_index >= n || row_index<0 || col_index<0 || mark[row_index][col_index] == true || word[word_index] != board[row_index][col_index])
		return false;
	//在这一轮中，board[row_index][col_index]已经被访问过
	mark[row_index][col_index] = true;
	bool rs = help(m, n, board, mark, row_index + 1, col_index, word_index + 1, word) ||
		help(m, n, board, mark, row_index - 1, col_index, word_index + 1, word) ||
		help(m, n, board, mark, row_index, col_index + 1, word_index + 1, word) ||
		help(m, n, board, mark, row_index, col_index - 1, word_index + 1, word);
	mark[row_index][col_index] = false;
	return rs;
}