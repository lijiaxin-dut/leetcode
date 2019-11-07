#include<vector>
#include<queue>
#include<string>
#include<unordered_set>
#include<iostream>
using namespace std;


//
//Consider a directed graph, with nodes labelled 0, 1, ..., n - 1.  In this graph, each edge is either red or blue, and there could be self - edges or parallel edges.
//
//Each[i, j] in red_edges denotes a red directed edge from node i to node j.Similarly, each[i, j] in blue_edges denotes a blue directed edge from node i to node j.
//
//Return an array answer of length n, where each answer[X] is the length of the shortest path from node 0 to node X such that the edge colors alternate along the path(or -1 if such a path doesn't exist).
//

//两次BFS， 第一次先走红边
//第二次先走蓝边
//每个节点最多访问两次
//两个mark  蓝色的边到当前点，和红色的边到当前点


class Solution {
	vector<vector<int>>matrix;
public:
	vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
		unordered_set<vector<int>>red_edge;
		unordered_set<vector<int>>blue_edge;
		vector<vector<vector<int>>>adj(n);
		for (auto &one_red : red_edges) {
			red_edge.insert(one_red);
			adj[one_red[0]].push_back(one_red);
		}
		for (auto &one_blue : blue_edges) {
			blue_edge.insert(one_blue);
			adj[one_blue[0]].push_back(one_blue);
		}
		auto A = bfs(n, red_edge, blue_edge, adj);
		auto B = bfs(n, blue_edge, red_edge, adj);
		vector<int>rs(n, 0);
		for (int i = 1; i<n; i++) {
			if (A[i] == INT_MAX&&B[i] == INT_MAX)
				rs[i] = -1;
			else if (A[i] == INT_MAX)
				rs[i] = B[i];
			else if (B[i] == INT_MAX)
				rs[i] = A[i];
			else
				rs[i] = min(A[i], B[i]);
		}
		return rs;
	}
	vector<int>bfs(int n, set<vector<int>>&red_edge, set<vector<int>>&blue_edge, vector<vector<vector<int>>>&adj) {
		vector<int>disTo(n, INT_MAX);
		vector<int>rs(n, INT_MAX);
		vector<int>blue_mark(n, 0);
		vector<int>red_mark(n, 0);
		queue<int>q;
		blue_mark[0] = 1;
		red_mark[0] = 1;
		q.push(0);
		disTo[0] = 0;
		int path_size = 0;
		while (!q.empty()) {
			path_size++;
			int level_size = q.size();
			for (int i = 0; i<level_size; i++) {
				auto t = q.front();
				q.pop();
				for (auto &out_edge : adj[t]) {
					int end_node = out_edge[1];
					if (path_size % 2 == 0 && blue_mark[end_node] == 0) {
						if (blue_edge.find(out_edge) != blue_edge.end()) {
							blue_mark[end_node] = 1;
							disTo[end_node] = path_size;
							rs[end_node] = min(disTo[end_node], rs[end_node]);
							q.push(end_node);
						}
					}
					if (path_size % 2 == 1 && red_mark[end_node] == 0) {
						if (red_edge.find(out_edge) != red_edge.end()) {
							red_mark[end_node] = 1;
							disTo[end_node] = path_size;
							rs[end_node] = min(disTo[end_node], rs[end_node]);
							q.push(end_node);
						}
					}
				}

			}
		}
		return rs;
	}
};