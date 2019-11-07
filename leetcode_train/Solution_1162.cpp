#include<vector>
#include<queue>
#include<string>
#include<unordered_set>
#include<iostream>
using namespace std;

//Given an N x N grid containing only values 0 and 1, where 0 represents water and 1 represents land, find a water cell such that its distance to the nearest land cell is maximized and return the distance.
//
//The distance used in this problem is the Manhattan distance : the distance between two cells(x0, y0) and (x1, y1) is | x0 - x1 | +| y0 - y1 | .
//
//If no land or water exists in the grid, return -1.

//多源BFS
//从所有的1开始BFS，遍历所有的0点，记录遍历的层数




class Solution_1162 {
	vector<int>xx{ 0, 0,1,-1 };
	vector<int>yy{ 1,-1,0, 0 };
public:
	int maxDistance(vector<vector<int>>& grid) {
		queue<pair<int, int>>q;
		int m = grid.size();
		int n = grid[0].size();
		for (int i = 0; i<m; i++) {
			for (int j = 0; j<n; j++) {
				if (grid[i][j] == 1)
					q.push(make_pair(i, j));
			}
		}
		if (q.size() == m*n || q.size() == 0)
			return -1;
		int step = 0;
		while (!q.empty()) {
			int level_size = q.size();
			for (int i = 0; i<level_size; i++) {
				auto cur = q.front();
				q.pop();
				for (int j = 0; j<4; j++) {
					int new_x = cur.first + xx[j];
					int new_y = cur.second + yy[j];
					if (new_x<0 || new_x >= m || new_y<0 || new_y >= n || grid[new_x][new_y] != 0)
						continue;
					grid[new_x][new_y] = 1;
					q.push(make_pair(new_x, new_y));
				}
			}
			step++;
		}
		return step - 1;
	}
};