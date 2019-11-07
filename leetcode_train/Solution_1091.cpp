#include<vector>
#include<queue>
#include<string>
#include<unordered_set>
#include<iostream>
using namespace std;


//In an N by N square grid, each cell is either empty(0) or blocked(1).
//
//A clear path from top - left to bottom - right has length k if and only if it is composed of cells C_1, C_2, ..., C_k such that :
//
//Adjacent cells C_i and C_{ i + 1 } are connected 8 - directionally(ie., they are different and share an edge or corner)
//C_1 is at location(0, 0) (ie.has value grid[0][0])
//C_k is at location(N - 1, N - 1) (ie.has value grid[N - 1][N - 1])
//If C_i is located at(r, c), then grid[r][c] is empty(ie.grid[r][c] == 0).
//Return the length of the shortest such clear path from top - left to bottom - right.If such a path does not exist, return -1.

//°Ë¸ö·½ÏòBFS



class Solution_1091 {
	vector<int>xx{ 0, 0,1,-1,-1,1,-1, 1 };
	vector<int>yy{ 1,-1,0, 0,-1,1, 1,-1 };
public:
	int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
		if (grid.empty() || grid[0][0] == 1)
			return -1;
		if (grid.size() == 1 && grid[0][0] == 0)
			return 1;
		int m = grid.size();
		int n = grid[0].size();
		vector<vector<bool>>mark(n, vector<bool>(n, false));
		queue<pair<int, int>>q;
		q.push(make_pair(0, 0));
		mark[0][0] = true;
		int rs = 1;
		while (!q.empty()) {
			int level_size = q.size();
			rs++;
			for (int i = 0; i<level_size; i++) {
				auto x = q.front().first;
				auto y = q.front().second;
				q.pop();
				for (int k = 0; k<8; k++) {
					int new_x = x + xx[k];
					int new_y = y + yy[k];
					if (new_x<0 || new_x >= m || new_y<0 || new_y >= n || mark[new_x][new_y] == true || grid[new_x][new_y] == 1)
						continue;
					mark[new_x][new_y] = true;
					if (new_x == m - 1 && new_y == n - 1)
						return rs;
					q.push(make_pair(new_x, new_y));
				}
			}
		}
		return -1;
	}
};