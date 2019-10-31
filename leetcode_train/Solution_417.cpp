#include<vector>

using namespace std;

//Given an m x n matrix of non - negative integers representing the height of each unit cell in a continent, the "Pacific ocean" touches the left and top edges of the matrix and the "Atlantic ocean" touches the right and bottom edges.
//
//Water can only flow in four directions(up, down, left, or right) from a cell to another one with height equal or lower.
//
//Find the list of grid coordinates where water can flow to both the Pacific and Atlantic ocean.
//
//Note:
//
//The order of returned grid coordinates does not matter.
//Both m and n are less than 150.
//
//
//Example :
//
//	Given the following 5x5 matrix :
//
//Pacific ~~~~~
//~1   2   2   3  (5) *
//~3   2   3  (4) (4) *
//~2   4  (5)  3   1 *
//~(6) (7)  1   4   5 *
//~(5)  1   1   2   4 *
//*   *   *   *   * Atlantic
//
//Return :
//
//[[0, 4], [1, 3], [1, 4], [2, 2], [3, 0], [3, 1], [4, 0]](positions with parentheses in above matrix).



//1.dfs从任何一个点进行dfs,看能都到达两个边缘

//2.从边缘dfs,向高处流，最后两个求两侧的交集，都能访问哪些点，就是结果


class Solution_417 {
	vector<int>xx{ -1,1,0,0 };
	vector<int>yy{ 0,0,-1,1 };
public:
	vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
		vector<vector<int>>  rs;
		int m = matrix.size();
		if (m == 0)
			return rs;
		int n = matrix[0].size();
		for (int i = 0; i<m; i++) {
			for (int j = 0; j<n; j++) {
				vector<vector<bool>>mark(m, vector<bool>(n, false));
				bool is_get_left = false;
				bool is_get_right = false;
				mark[i][j] = true;
				dfs(matrix, is_get_left, is_get_right, m, n, i, j, mark);
				if (is_get_right == true && is_get_left == true) {
					rs.push_back({ i,j });
				}
			}
		}
		return rs;
	}
	void dfs(vector<vector<int>>& matrix, bool &is_get_left, bool &is_get_right, int m, int n, int current_x, int current_y, vector<vector<bool>>&mark) {
		if (current_x == 0 || current_y == 0)
			is_get_left = true;
		if (current_x == m - 1 || current_y == n - 1)
			is_get_right = true;
		if (is_get_right == true && is_get_left == true)
			return;
		for (int i = 0; i<4; i++) {
			int new_x = current_x + xx[i];
			int new_y = current_y + yy[i];
			if (new_x<0 || new_x >= m || new_y<0 || new_y >= n)
				continue;
			if (mark[new_x][new_y] == false && matrix[current_x][current_y] >= matrix[new_x][new_y]) {
				mark[new_x][new_y] = true;
				dfs(matrix, is_get_left, is_get_right, m, n, new_x, new_y, mark);
			}
		}
	}
	vector<vector<int>> pacificAtlantic_1(vector<vector<int>>& matrix) {
		vector<vector<int>>  rs;
		int m = matrix.size();
		if (m == 0)
			return rs;
		int n = matrix[0].size();
		vector<vector<bool>> pacific(m, vector<bool>(n, false));
		vector<vector<bool>> atlantic(m, vector<bool>(n, false));
		for (int i = 0; i<m; i++) {
			pacific[i][0] = true;
			dfs_1(matrix, m, n, i, 0, pacific);
			atlantic[i][n - 1] = true;
			dfs_1(matrix, m, n, i, n - 1, atlantic);
		}
		for (int j = 0; j<n; j++) {
			pacific[0][j] = true;
			dfs_1(matrix, m, n, 0, j, pacific);
			atlantic[m - 1][j] = true;
			dfs_1(matrix, m, n, m - 1, j, atlantic);
		}
		for (int i = 0; i<m; i++) {
			for (int j = 0; j<n; j++) {
				if (pacific[i][j] == true && atlantic[i][j] == true)
					rs.push_back({ i,j });
			}
		}
		return rs;
	}
	void dfs_1(vector<vector<int>>& matrix, int m, int n, int current_x, int current_y, vector<vector<bool>>&mark) {
		for (int i = 0; i<4; i++) {
			int new_x = current_x + xx[i];
			int new_y = current_y + yy[i];
			if (new_x<0 || new_x >= m || new_y<0 || new_y >= n)
				continue;
			if (mark[new_x][new_y] == false && matrix[current_x][current_y] <= matrix[new_x][new_y]) {
				mark[new_x][new_y] = true;
				dfs_1(matrix, m, n, new_x, new_y, mark);
			}
		}


	}
};

//int main() {
//	Solution_417 s;
//	vector<vector<int>>m{
//		{1,2,2,3,5},{3,2,3,4,4},{2,4,5,3,1} ,{6,7,1,4,5},{5,1,1,2,4} };
//	s.pacificAtlantic(m);
//}