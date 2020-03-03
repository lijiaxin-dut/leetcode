#include<vector>

using namespace std;

//you are given a map in form of a two - dimensional integer grid where 1 represents land and 0 represents water.
//
//Grid cells are connected horizontally / vertically(not diagonally).The grid is completely surrounded by water, and there is exactly one island(i.e., one or more connected land cells).
//
//The island doesn't have "lakes" (water inside that isn't connected to the water around the island).One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.
//
//
//
//Example:
//
//Input:
//[[0, 1, 0, 0],
//[1, 1, 1, 0],
//[0, 1, 0, 0],
//[1, 1, 0, 0]]
//
//Output : 16

//统计周围1的个数
//周围没有1，周长+4
//周围一个1，周长+3


class Solution {
	vector<int>xx{ 1,-1,0,0 };
	vector<int>yy{ 0,0,1,-1 };
public:
	int islandPerimeter(vector<vector<int>>& grid) {
		int m = grid.size();
		int n = grid[0].size();
		int rs = 0;
		for (int i = 0; i<m; i++) {
			for (int j = 0; j<n; j++) {
				if (grid[i][j] == 1) {
					int one_number = count_one(grid, i, j);
					rs += 4 - one_number;
				}
			}
		}
		return rs;
	}
	int count_one(vector<vector<int>>& grid, int cur_x, int cur_y) {
		int rs = 0;
		for (int i = 0; i<4; i++) {
			int new_x = cur_x + xx[i];
			int new_y = cur_y + yy[i];
			if (new_x<0 || new_x >= grid.size() || new_y<0 || new_y >= grid[0].size())
				continue;
			if (grid[new_x][new_y] == 1)
				rs++;
		}
		return rs;
	}
};