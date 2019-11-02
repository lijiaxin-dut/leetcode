#include<vector>
#include<unordered_set>
#include<unordered_map>
#include<queue>

using namespace std;

//Given a non - empty 2D array grid of 0's and 1's, an island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.
//
//Find the maximum area of an island in the given 2D array. (If there is no island, the maximum area is 0.)
//
//Example 1:
//
//[[0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0],
//[0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0],
//[0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0],
//[0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0],
//[0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0],
//[0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0],
//[0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0],
//[0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0]]
//Given the above grid, return 6. Note the answer is not 11, because the island must be connected 4 - directionally.

//dfs¼´¿É


class Solution_695 {
	vector<int>xx{ 0,0,1,-1 };
	vector<int>yy{ 1,-1,0,0 };
public:
	int maxAreaOfIsland(vector<vector<int>>& grid) {
		int m = grid.size();
		int n = grid[0].size();
		int rs = 0;
		vector<vector<int>>mark(m, vector<int>(n, 0));
		for (int i = 0; i<m; i++) {
			for (int j = 0; j<n; j++) {
				if (grid[i][j] == 1 && mark[i][j] == 0) {
					mark[i][j] = 1;
					int c = 1;
					dfs(c, m, n, grid, mark, i, j);
					rs = max(c, rs);
				}
			}
		}
		return rs;
	}
	void dfs(int &rs, int m, int n, vector<vector<int>>&grid, vector<vector<int>>&mark, int x, int y) {
		for (int i = 0; i<4; i++) {
			int new_x = x + xx[i];
			int new_y = y + yy[i];
			if (new_x<0 || new_x >= m || new_y<0 || new_y >= n || mark[new_x][new_y] == 1 || grid[new_x][new_y] == 0)
				continue;
			mark[new_x][new_y] = 1;
			rs++;
			dfs(rs, m, n, grid, mark, new_x, new_y);
		}

	}
};