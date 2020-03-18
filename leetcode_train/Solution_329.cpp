#include<vector>
#include<memory>
#include<iostream>
#include<string>
#include<queue>
using namespace std;
//
//Given an integer matrix, find the length of the longest increasing path.
//
//From each cell, you can either move to four directions : left, right, up or down.You may NOT move diagonally or move outside of the boundary(i.e.wrap - around is not allowed).
//
//Example 1 :
//
//	Input : nums =
//	[
//		[9, 9, 4],
//		[6, 6, 8],
//		[2, 1, 1]
//	]
//Output : 4
//	Explanation : The longest increasing path is[1, 2, 6, 9].

//topo找最长路径
//  首先找到topo排序
//	按照拓扑排序的顺序松弛  dp[i]=max(dp[i],do[j]+i)  j->i
//或者
//dfs+memory

class Solution_329 {
	vector<int>xx{ 1,-1,0,0 };
	vector<int>yy{ 0,0,1,-1 };
public:

	int longestIncreasingPath_dfs(vector<vector<int>>& matrix) {
		int m = matrix.size();
		if (m == 0)
			return 0;
		int n = matrix[0].size();
		int rs = 1;
		vector<vector<int>>dp(m, vector<int>(n, 0));
		for (int i = 0; i<m; i++) {
			for (int j = 0; j<n; j++) {
				rs = max(rs, dfs(matrix, dp, i, j, m, n));
			}
		}
		return rs;

	}
	int dfs(vector<vector<int>>& matrix, vector<vector<int>>& dp, int i, int j, int m, int n) {
		if (dp[i][j] != 0)
			return dp[i][j];
		int cur_rs = 1;
		for (int k = 0; k<4; k++) {
			int new_x = i + xx[k];
			int new_y = j + yy[k];
			if (new_x<0 || new_x >= m || new_y<0 || new_y >= n || matrix[i][j] >= matrix[new_x][new_y])
				continue;
			cur_rs = max(cur_rs, dfs(matrix, dp, new_x, new_y, m, n) + 1);
		}
		dp[i][j] = cur_rs;
		return cur_rs;
	}



	int longestIncreasingPath(vector<vector<int>>& matrix) {
		int m = matrix.size();
		if (m == 0)
			return 0;
		int n = matrix[0].size();

		int node_size = m*n;
		vector<vector<int>>graph(node_size);
		vector<vector<int>>to_graph(node_size);
		vector<int>node_in_degree(node_size, 0);
		for (int i = 0; i<m; i++) {
			for (int j = 0; j<n; j++) {
				int cur_node = i*n + j;
				for (int k = 0; k<4; k++) {
					int new_x = i + xx[k];
					int new_y = j + yy[k];
					if (new_x<0 || new_x >= m || new_y<0 || new_y >= n)
						continue;
					if (matrix[i][j]<matrix[new_x][new_y]) {
						graph[cur_node].push_back(new_x*n + new_y);
						to_graph[new_x*n + new_y].push_back(cur_node);
						node_in_degree[new_x*n + new_y]++;
					}
				}

			}
		}
		vector<int>topo_order;
		queue<int>q;
		for (int i = 0; i<node_size; i++) {
			if (node_in_degree[i] == 0) {
				q.push(i);
			}
		}
		while (!q.empty()) {
			int cur_node = q.front();
			q.pop();
			topo_order.push_back(cur_node);
			for (auto out_cur_node : graph[cur_node]) {
				node_in_degree[out_cur_node]--;
				if (node_in_degree[out_cur_node] == 0) {
					q.push(out_cur_node);
					
				}
			}
		}

		vector<int>dp(node_size, 0);
		for (int j = 0; j<node_size; j++) {
			int i = topo_order[j];
			for (auto to_node_i : to_graph[i]) {
				dp[i] = max(dp[i], dp[to_node_i] + 1);
			}
		}
		return *max_element(dp.begin(), dp.end()) + 1;

	}
};
