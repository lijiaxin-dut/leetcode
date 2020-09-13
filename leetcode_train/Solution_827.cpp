#include<vector>
#include<iostream>
#include<algorithm>
#include<unordered_set>
using namespace std;

//在二维地图上， 0代表海洋， 1代表陆地，我们最多只能将一格 0 海洋变成 1变成陆地。
//
//进行填海之后，地图上最大的岛屿面积是多少？（上、下、左、右四个方向相连的 1 可形成岛屿）


//dfs
//统计每一个联通分量的个数，并且记录，它属于的联通分量的index
//对于每一个0的位置，判断四个方向的联通分量个数，然后求和

class Solution {
	vector<int>xx{ 1,-1,0,0 };
	vector<int>yy{ 0,0,1,-1 };
public:
	int largestIsland(vector<vector<int>>& grid) {
		int m = grid.size();
		if (m == 0) {
			return 0;
		}
		int n = grid.size();
		int index = 2;
		vector<int>each_size{ 0,0 };
		int rs = 0;
		for (int i = 0; i<m; i++) {
			for (int j = 0; j<n; j++) {
				if (grid[i][j] == 1) {
					int cur_area = 1;
					grid[i][j] = index;
					dfs(grid, i, j, cur_area, index);
					rs = max(rs, cur_area);
					each_size.push_back(cur_area);
					index++;
				}
			}
		}
		for (int i = 0; i<m; i++) {
			for (int j = 0; j<n; j++) {
				if (grid[i][j] == 0) {
					rs = max(rs, calculate_rs(m, n, i, j, each_size, grid));
				}
			}
		}
		return rs;
	}
	void dfs(vector<vector<int>>&grid, int x, int y, int &cur_area, int index) {
		int m = grid.size();
		int n = grid.size();
		for (int i = 0; i<4; i++) {
			int new_x = x + xx[i];
			int new_y = y + yy[i];
			if (new_x<0 || new_x >= m || new_y<0 || new_y >= n || grid[new_x][new_y] != 1)
				continue;
			grid[new_x][new_y] = index;
			cur_area++;
			dfs(grid, new_x, new_y, cur_area, index);
		}
	}
	int calculate_rs(int m, int n, int x, int y, vector<int>&each_size, vector<vector<int>>&grid) {
		unordered_set<int>s;
		for (int i = 0; i<4; i++) {
			int new_x = x + xx[i];
			int new_y = y + yy[i];
			if (new_x<0 || new_x >= m || new_y<0 || new_y >= n)
				continue;
			s.insert(grid[new_x][new_y]);
		}
		int rs = 1;
		for (auto i : s) {
			rs += each_size[i];
		}
		return rs;

	}

};