﻿#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

//在一个 N x N 的坐标方格 grid 中，每一个方格的值 grid[i][j] 表示在位置(i, j) 的平台高度。
//现在开始下雨了。当时间为 t 时，此时雨水导致水池中任意位置的水位为 t 。你可以从一个平台游向四周相邻的任意一个平台，但是前提是此时水位必须同时淹没这两个平台。假定你可以瞬间移动无限距离，也就是默认在方格内部游动是不耗时的。当然，在你游泳的时候你必须待在坐标方格里面。
//你从坐标方格的左上平台(0，0) 出发。最少耗时多久你才能到达坐标方格的右下平台 (N - 1, N - 1)？
//
//
//示例 1:
//输入: [[0, 2], [1, 3]]
//	输出 : 3
//	解释 :
//	时间为0时，你位于坐标方格的位置为(0, 0)。
//	此时你不能游向任意方向，因为四个相邻方向平台的高度都大于当前时间为 0 时的水位。
//	等时间到达 3 时，你才可以游向平台(1, 1).因为此时的水位是 3，坐标方格中的平台没有比水位 3 更高的，所以你可以游向坐标方格中的任意位置

//根据下限和上限进行二分


class Solution {
	vector<int>xx{ 0,0,1,-1 };
	vector<int>yy{ 1,-1,0,0 };
public:
	int swimInWater(vector<vector<int>>& grid) {
		int n = grid.size();
		int left = 2499;
		int right = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				right = max(right, grid[i][j]);
				left = min(left, grid[i][j]);
			}
		}
		int ans = right;
		while (left <= right) {
			int mid = left + (right - left) / 2;
			bool rs = dfs(grid, mid);
			if (rs == true) {
				ans = min(ans, mid);
				right = mid - 1;
			}
			else {
				left = mid + 1;
			}
		}

		return ans;
	}
	bool dfs(vector<vector<int>>& grid, int val) {
		if (grid[0][0] > val)
			return false;
		queue<pair<int, int>>q;
		q.push({ 0,0 });
		int n = grid.size();
		vector<vector<bool>>mark(n, vector<bool>(n, false));
		mark[0][0] = true;
		while (!q.empty()) {
			int cur_x = q.front().first;
			int cur_y = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int new_x = cur_x + xx[i];
				int new_y = cur_y + yy[i];
				if (new_x < 0 || new_x >= n || new_y<0 || new_y >= n || mark[new_x][new_y] == true || grid[new_x][new_y]>val)
					continue;
				q.push({ new_x,new_y });
				mark[new_x][new_y] = true;
			}
		}
		return mark[n - 1][n - 1];

	}
};