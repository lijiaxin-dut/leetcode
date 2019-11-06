#include<vector>
#include<string>


using namespace std;


//Given a 2D array A, each cell is 0 (representing sea) or 1 (representing land)
//
//A move consists of walking from one land square 4 - directionally to another land square, or off the boundary of the grid.
//
//Return the number of land squares in the grid for which we cannot walk off the boundary of the grid in any number of moves.

//不能到达边界的点，从边界开始dfs



class Solution_1020 {
public:
	vector<int> xx = { 1,-1,0,0 };
	vector<int> yy = { 0,0,1,-1 };
	void dfs(int m, int n, vector<vector<int>>& A, vector<vector<bool>>&mark, int x, int y) {
		for (int i = 0; i<4; i++) {
			int new_x = x + xx[i];
			int new_y = y + yy[i];
			if (new_x<0 || new_x >= m || new_y<0 || new_y >= n || A[new_x][new_y] != 1 || mark[new_x][new_y] == true)
				continue;
			mark[new_x][new_y] = true;
			dfs(m, n, A, mark, new_x, new_y);
		}

	}
	int numEnclaves(vector<vector<int>>& A) {
		int m = A.size();
		int n = A[0].size();
		vector<vector<bool>>mark(m, vector<bool>(n, false));
		for (int i = 0; i<m; i++) {
			if (A[i][0] == 1 && mark[i][0] == false) {
				mark[i][0] = true;
				dfs(m, n, A, mark, i, 0);
			}
			if (A[i][n - 1] == 1 && mark[i][n - 1] == false) {
				mark[i][n - 1] = true;
				dfs(m, n, A, mark, i, n - 1);
			}
		}
		for (int i = 0; i<n; i++) {
			if (A[0][i] == 1 && mark[0][i] == false) {
				mark[0][i] = true;
				dfs(m, n, A, mark, 0, i);
			}
			if (A[m - 1][i] == 1 && mark[m - 1][i] == false) {
				mark[m - 1][i] = true;
				dfs(m, n, A, mark, m - 1, i);
			}
		}
		int rs = 0;
		for (int i = 0; i<m; i++) {
			for (int j = 0; j<n; j++) {
				if (A[i][j] == 1 && mark[i][j] == false) {
					rs++;
				}
			}
		}
		return rs;
	}
};