#include<vector>
#include<queue>
using namespace std;

//Given a matrix consists of 0 and 1, find the distance of the nearest 0 for each cell.
//
//The distance between two adjacent cells is 1.
//
//
//
//Example 1:
//
//Input:
//[[0, 0, 0],
//[0, 1, 0],
//[0, 0, 0]]
//
//Output :
//	[[0, 0, 0],
//	[0, 1, 0],
//	[0, 0, 0]]


//将所有的1都变成INT_MAX
//所有的零点都作为起点
//进行dfs   不需要进行mark  ，永远取最小的距离

class Solution_542 {
	vector<int>xx{ -1,1,0,0 };
	vector<int>yy{ 0,0,-1,1 };
public:
	vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {

		int m = matrix.size();
		int n = matrix[0].size();
		queue<pair<int, int>>q;
		for (int i = 0; i<m; i++) {
			for (int j = 0; j<n; j++) {
				if (matrix[i][j] == 0)
					q.push(make_pair(i, j));
				else
					matrix[i][j] = INT_MAX;
			}
		}
		while (!q.empty()) {
			auto t = q.front();
			q.pop();
			for (int i = 0; i<4; i++) {
				int new_x = t.first + xx[i];
				int new_y = t.second + yy[i];
				if (new_x<0 || new_x >= m || new_y<0 || new_y >= n)
					continue;
				if (matrix[new_x][new_y]>matrix[t.first][t.second] + 1) {
					matrix[new_x][new_y] = matrix[t.first][t.second] + 1;
					q.push(make_pair(new_x, new_y));
				}
			}
		}
		return matrix;
	}
};