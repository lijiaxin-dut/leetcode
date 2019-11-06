#include<vector>
#include<memory>
#include<queue>

using namespace std;


//In a given grid, each cell can have one of three values :
//
//the value 0 representing an empty cell;
//the value 1 representing a fresh orange;
//the value 2 representing a rotten orange.
//Every minute, any fresh orange that is adjacent(4 - directionally) to a rotten orange becomes rotten.
//
//Return the minimum number of minutes that must elapse until no cell has a fresh orange.If this is impossible, return -1 instead.


//∂‡‘¥bfs

class Solution {
public:
	int orangesRotting(vector<vector<int>>& grid) {
		int m = grid.size();
		int n = grid[0].size();
		queue<pair<int, int>>q;
		for (int i = 0; i<m; i++) {
			for (int j = 0; j<n; j++) {
				if (grid[i][j] == 2) {
					q.push(make_pair(i, j));
				}
			}
		}
		int rs = 0;
		vector<int>xx{ 0,0,1,-1 };
		vector<int>yy{ 1,-1,0,0 };
		while (!q.empty()) {
			int level_size = q.size();
			for (int i = 0; i<level_size; i++) {
				auto t = q.front();
				q.pop();
				for (int i = 0; i<4; i++) {
					int new_x = t.first + xx[i];
					int new_y = t.second + yy[i];
					if (new_x<0 || new_x >= m || new_y<0 || new_y >= n || grid[new_x][new_y] != 1)
						continue;
					grid[new_x][new_y] = 2;
					q.push(make_pair(new_x, new_y));
				}
			}
			if (q.empty())
				break;
			rs++;
		}

		for (int i = 0; i<m; i++) {
			for (int j = 0; j<n; j++) {
				if (grid[i][j] == 1) {
					return -1;
				}
			}
		}
		return rs;
	}
};