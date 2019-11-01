#include<vector>

using namespace std;

//There is an m by n grid with a ball.Given the start coordinate(i, j) of the ball, 
//you can move the ball to adjacent cell or cross the grid boundary in four 
//directions(up, down, left, right).However, you can at most move N times.
//Find out the number of paths to move the ball out of grid boundary.
//The answer may be very large, return it after mod 109 + 7.

//dfs 穷举所有的可能
//dp
//dp[k][i][j]  i j 到边界经过k步的所有可能



class Solution_576 {
	vector<int>xx{ -1,1,0,0 };
	vector<int>yy{ 0,0,-1,1 };
	int M = 1000000000 + 7;
public:
	int findPaths_dp(int m, int n, int N, int i, int j) {
		vector<vector<vector<long>>>dp(N + 1, vector<vector<long>>(m, vector<long>(n, 0)));
		for (int k = 1; k <= N; k++) {
			for (int x = 0; x<m; x++) {
				for (int y = 0; y<n; y++) {
					int v1 = 0, v2 = 0, v3 = 0, v4 = 0;
					if (x == 0)
						dp[k][x][y] += 1;
					else
						dp[k][x][y] += dp[k - 1][x - 1][y];
					if (x == m - 1)
						dp[k][x][y] += 1;
					else
						dp[k][x][y] += dp[k - 1][x + 1][y];
					if (y == 0)
						dp[k][x][y] += 1;
					else
						dp[k][x][y] += dp[k - 1][x][y - 1];
					if (y == n - 1)
						dp[k][x][y] += 1;
					else
						dp[k][x][y] += dp[k - 1][x][y + 1];
					dp[k][x][y] %= (1000000000 + 7);
				}
			}
		}
		return dp[N][i][j];
	}
	int findPaths(int m, int n, int N, int i, int j) {
		int rs = 0;
		dfs(m, n, N, 0, rs, i, j);
		return rs;
	}
	void dfs(int m, int n, int N, int current_n, int &rs, int current_x, int current_y) {
		if (current_n >= N)
			return;
		for (int i = 0; i<4; i++) {
			int new_x = current_x + xx[i];
			int new_y = current_y + yy[i];
			if (new_x<0 || new_x >= m || new_y<0 || new_y >= n) {
				if (current_n<N) {
					rs++;
					rs = rs%M;
				}
				continue;
			}
			dfs(m, n, N, current_n + 1, rs, new_x, new_y);
		}
	}
};