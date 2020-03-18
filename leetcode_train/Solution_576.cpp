#include<vector>

using namespace std;

//There is an m by n grid with a ball.Given the start coordinate(i, j) of the ball, 
//you can move the ball to adjacent cell or cross the grid boundary in four 
//directions(up, down, left, right).However, you can at most move N times.
//Find out the number of paths to move the ball out of grid boundary.
//The answer may be very large, return it after mod 109 + 7.

//dfs 穷举所有的可能
//dp
//dp[i][j][k]经过n步到达(i,j)的步数



class Solution_576 {

	int M = 1000000000 + 7;
public:
	vector<int>xx{ 0,0,1,-1 };
	vector<int>yy{ 1,-1,0,0 };
public:
	int findPaths(int m, int n, int N, int i, int j) {
		int rs = 0;
		int mode = 1e9 + 7;
		vector<vector<vector<int>>>dp(m, vector<vector<int>>(n, vector<int>(N + 1, 0)));
		dp[i][j][0] = 1;
		for (int cur_step = 1; cur_step <= N; cur_step++) {
			for (int curx = 0; curx<m; curx++) {
				for (int cury = 0; cury<n; cury++) {
					if (dp[curx][cury][cur_step - 1] == 0)
						continue;
					for (int k = 0; k<4; k++) {
						int new_x = curx + xx[k];
						int new_y = cury + yy[k];
						if (new_x<0 || new_x >= m || new_y<0 || new_y >= n) {
							rs += dp[curx][cury][cur_step - 1];
							rs = rs % (mode);
							continue;
						}
						dp[new_x][new_y][cur_step] += dp[curx][cury][cur_step - 1];
						dp[new_x][new_y][cur_step] = dp[new_x][new_y][cur_step] % mode;
					}
				}
			}
		}
		return rs;
	}
	int findPaths_(int m, int n, int N, int i, int j) {
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