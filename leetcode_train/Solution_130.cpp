#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>
#include<memory>
#include<unordered_map>
#include<set>


using namespace std;


//Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.
//
//A region is captured by flipping all 'O's into 'X's in that surrounded region.
//
//Example:
//
//X X X X
//X O O X
//X X O X
//X O X X
//After running your function, the board should be :
//
//X X X X
//X X X X
//X X X X
//X O X X

//使用dfs
//从四个边界开始深度优先遍历
//将遇到过的'O'用其它的符号表示



//使用并查集

class UF_130
{
private:
	int* id;
public:
	UF_130(int N)
	{
		id = new int[N];
		for (int i = 0; i < N; i++) {
			id[i] = i;
		}
	}
	~UF_130()
	{
		delete[] id;
	}
	int find(int p) {
		int root = p;
		while (root != id[root]) {
			root = id[root];
		}
		while (p != id[p]) {
			int temp = id[p];
			id[p] = root;
			p = temp;
		}
		return root;
	}

	bool connected(int p, int q) {
		return find(p) == find(q);
	}
	void connect(int p, int q) {
		int i = find(p);
		int j = find(q);
		if (i == j)
			return;
		id[i] = j;
	}
};

class Solution_130 {
public:
	void solve_UNF(vector<vector<char>>& board) {
		int n = board.size();
		if (n == 0)
			return;
		int m = board[0].size();
		UF_130 uf = UF_130(n*m + 1);
		for (int i = 0; i<n; i++) {
			for (int j = 0; j<m; j++) {
				//将边界连接到dumy节点
				if ((i == 0 || i == n - 1 || j == 0 || j == m - 1) && board[i][j] == 'O')
					uf.connect(i*m + j, n*m);
				//不断的将相邻的节点链接
				else if (board[i][j] == 'O')
				{
					if (board[i - 1][j] == 'O')
						uf.connect(i*m + j, (i - 1)*m + j);
					if (board[i + 1][j] == 'O')
						uf.connect(i*m + j, (i + 1)*m + j);
					if (board[i][j - 1] == 'O')
						uf.connect(i*m + j, i*m + j - 1);
					if (board[i][j + 1] == 'O')
						uf.connect(i*m + j, i*m + j + 1);
				}
			}
		}

		for (int i = 0; i<n; i++) {
			for (int j = 0; j<m; j++) {
				if (!uf.connected(i*m + j, n*m)) {
					board[i][j] = 'X';
				}
			}
		}
	}
	void solve_dfs(vector<vector<char>>& board) {
		int m = board.size();
		if (m == 0)
			return;
		int n = board[0].size();
		vector<int>change_x{ -1,1,0,0 };
		vector<int>change_y{ 0,0,-1,1 };
		for (int i = 0; i < m; i++) {
			if (board[i][0] == 'O') {
				board[i][0] = '&';
				dfs(m, n, change_x, change_y, board, i, 0);
			}
		}

		for (int i = 0; i < m; i++) {
			if (board[i][n-1] == 'O') {
				board[i][n-1] = '&';
				dfs(m, n, change_x, change_y, board, i, n - 1);
			}
		}
		for (int j = 0; j < n; j++) {
			if (board[0][j] == 'O') {
				board[0][j] = '&';
				dfs(m, n, change_x, change_y, board, 0, j);
			}
		}
		for (int j = 0; j < n; j++) {
			if (board[m - 1][j] == 'O') {
				board[m - 1][j] = '&';
				dfs(m, n, change_x, change_y, board, m - 1, j);
			}
		}
	
		for (int i = 0; i<m; i++) {
			for (int j = 0; j<n; j++) {
				if (board[i][j] == 'O')
					board[i][j] = 'X';
				if (board[i][j] == '&')
					board[i][j] = 'O';
			}
		}
	}
	void dfs(int m, int n, vector<int>&change_x, vector<int>&change_y, vector<vector<char>>& board, int x, int y) {
		for (int i = 0; i < 4; i++) {
			int new_x = x + change_x[i];
			int new_y = y + change_y[i];
			if (new_x < 0 || new_x >= m || new_y < 0 || new_y >= n)
				continue;
			if (board[new_x][new_y] == 'O') {
				board[new_x][new_y] = '&';
				dfs(m, n, change_x, change_y, board, new_x, new_y);
			}
		}

	}
};

//int main() {
//	Solution_130 s;
//	vector<vector<char>>board{ { 'O','X','O'},{'X','O','X'},{ 'O','X','O' } };
//
//	s.solve(board);
//}
