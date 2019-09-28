#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>
#include<memory>
#include<unordered_map>
#include<set>


using namespace std;



//Given a 2d grid map of '1's(land) and '0's(water), count the number of islands.An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically.You may assume all four edges of the grid are all surrounded by water.
//
//Example 1:
//
//Input:
//11110
//11010
//11000
//00000
//
//Output : 1
//	Example 2 :
//
//	Input :
//	11000
//	11000
//	00100
//	00011
//
//	Output : 3
//


//dfs
//从每一个未访问的节点开始
//找到该点可以到达的所有1
//标记遇到过的点

//跳过已经遇到过的点
class UF
{
private:
	int* id;
public:
	int count = 0;
	UF(int N)
	{
		id = new int[N];
		for (int i = 0; i < N; i++) {
			id[i] = i;
		}
	}
	~UF()
	{
		delete[] id;
	}
	int find(int p) {
		int root = p;
		while (root != id[root]) {
			root = id[root];
		}
		while (p != id[p]) {
			int temp = id[p];
			id[p] = root;
			p = temp;
		}
		return root;
	}

	bool connected(int p, int q) {
		return find(p) == find(q);
	}
	void connect(int p, int q) {
		int i = find(p);
		int j = find(q);
		if (i == j)
			return;
		id[i] = j;
		count--;
	}
};
class Solution_200 {
public:
	int numIslands(vector<vector<char>>& grid) {
		int n = grid.size();
		if (n == 0)
			return 0;
		int m = grid[0].size();
		UF un(m*n + 1);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (grid[i][j] == '1')
					un.count++;
			}
		}
		vector<int>change_x{ -1,1,0,0 };
		vector<int>change_y{ 0,0,-1,1 };
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (grid[i][j] == '1') {
					for (int k = 0; k < 4; k++) {
						int new_x = i + change_x[k];
						int new_y = j + change_y[k];
						if (new_x < 0 || new_x >= m || new_y < 0 || new_y >= n)
							continue;
						if (grid[new_x][new_y] == '1') {
							un.connect(i*n + j, new_x*n + new_y);
						}
					}
				}
			}
		}
		return un.count;
	}

	int numIslands_dfs(vector<vector<char>>& grid) {
		int m = grid.size();
		if (m == 0)
			return 0;
		int n = grid[0].size();
		int rs = 0;
		vector<vector<bool>>mark(m, vector<bool>(n, false));
		vector<int>change_x{ -1,1,0,0 };
		vector<int>change_y{ 0,0,-1,1 };
		for (int i = 0; i<m; i++) {
			for (int j = 0; j<n; j++) {
				if (grid[i][j] == '1'&&mark[i][j] == false) {
					rs++;
					dfs(m, n, change_x, change_y, grid, mark, i, j);
				}
			}
		}
		return rs;

	}
	void dfs(int m, int n, vector<int>&change_x, vector<int>&change_y, vector<vector<char>>& grid, vector<vector<bool>>&mark, int x, int y) {
		if (mark[x][y] == true)
			return;
		mark[x][y] = true;
		for (int i = 0; i < 4; i++) {
			int new_x = x + change_x[i];
			int new_y = y + change_y[i];
			if (new_x < 0 || new_x >= m || new_y < 0 || new_y >= n)
				continue;
			if (grid[new_x][new_y] == '1') {
				dfs(m, n, change_x, change_y, grid, mark, new_x, new_y);
			}
		}

	}
};
