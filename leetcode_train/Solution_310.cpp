#include<vector>
#include<queue>
#include<unordered_set>

//给定一个无向图，没有环，找到图中的根节点，使得树高度最小

//


//1.所有节点都作为跟节点，bfs,记录最小的高度
//2.不断的删除叶子节点，找到最远的节点，最多有两个节点可以作为根节点


using namespace std;
class Solution_310 {
	int bfs(vector<vector<int>>&adj, int start_node, int n) {
		int deep = 0;
		vector<bool>mark(n, false);
		queue<int>Q;
		Q.push(start_node);
		mark[start_node] = true;
		while (!Q.empty()) {
			int current_level_size = Q.size();
			deep++;
			for (int i = 0; i<current_level_size; i++) {
				auto current_node = Q.front();
				Q.pop();
				for (auto &one_node : adj[current_node]) {
					if (mark[one_node] == false) {
						mark[one_node] = true;
						Q.push(one_node);
					}
				}

			}
		}
		return deep;



	}
public:
	vector<int> findMinHeightTrees_1(int n, vector<vector<int>>& edges) {
		vector<vector<int>>adj(n);
		for (auto &one_edge : edges) {
			adj[one_edge[0]].push_back(one_edge[1]);
			adj[one_edge[1]].push_back(one_edge[0]);
		}
		vector<pair<int, int>>node_deep;
		int min_deep = INT_MAX;
		for (int i = 0; i<n; i++) {
			int current_deep = bfs(adj, i, n);
			if (current_deep<min_deep) {
				min_deep = current_deep;
			}
			node_deep.push_back(make_pair(i, current_deep));
		}
		vector<int>rs;
		for (auto &one_node : node_deep) {
			if (one_node.second == min_deep) {
				rs.push_back(one_node.first);
			}
		}
		return rs;


	}

	vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
		if (n == 1)
			return{ 0 };
		vector<unordered_set<int>>adj(n);
		for (auto &one_edge : edges) {
			adj[one_edge[0]].insert(one_edge[1]);
			adj[one_edge[1]].insert(one_edge[0]);
		}
		queue<int>Q;
		for (int i = 0; i<n; i++)
			if (adj[i].size() == 1)
				Q.push(i);
		while (n>2) {
			int current_size = Q.size();
			n = n - current_size;
			for (int i = 0; i<current_size; i++) {
				int leaf = Q.front();
				Q.pop();
				for (auto&to_leaf : adj[leaf]) {
					adj[to_leaf].erase(leaf);
					if (adj[to_leaf].size() == 1) {
						Q.push(to_leaf);
					}
				}
			}
		}
		vector<int>rs;
		while (!Q.empty()) {
			rs.push_back(Q.front());
			Q.pop();
		}
		return rs;
	}
};