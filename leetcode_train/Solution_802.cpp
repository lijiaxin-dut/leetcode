#include<vector>
#include<set>
#include<queue>
#include<unordered_set>

using namespace std;


//In a directed graph, we start at some node and every turn, walk along a directed edge of the graph.If we reach a node that is terminal(that is, it has no outgoing directed edges), we stop.
//
//Now, say our starting node is eventually safe if and only if we must eventually walk to a terminal node.More specifically, there exists a natural number K so that for any choice of where to walk, we must have stopped at a terminal node in less than K steps.
//
//Which nodes are eventually safe ? Return them as an array in sorted order.
//
//The directed graph has N nodes with labels 0, 1, ..., N - 1, where N is the length of graph.The graph is given in the following form : graph[i] is a list of labels j such that(i, j) is a directed edge of the graph.
//
//Example :
//	Input : graph = [[1, 2], [2, 3], [5], [0], [5], [], []]
//	Output : [2, 4, 5, 6]
//	Here is a diagram of the above graph.
//

//找出没有出度的节点，然后依次找出指出的边全在已经找到的safe节点的点，将边从图中删除
//建立reverg graph
//方便查找



class Solution {
public:
	vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
		int n = graph.size();
		vector<unordered_set<int>>rg(n);//指向这个点的邻居
		vector<int>out_degree(n, 0);
		queue<int>q;
		for (int i = 0; i<n; i++) {
			out_degree[i] = graph[i].size();
			if (out_degree[i] == 0)
				q.push(i);
			for (auto &one_neighbor : graph[i]) {
				rg[one_neighbor].insert(i);
			}
		}
		vector<int>rs;
		while (!q.empty()) {
			int cur_node = q.front();
			q.pop();
			for (auto &to_cur_node : rg[cur_node]) {
				out_degree[to_cur_node]--;
				if (out_degree[to_cur_node] == 0)
					q.push(to_cur_node);
			}
		}
		for (int i = 0; i<n; i++)
			if (out_degree[i] == 0)
				rs.push_back(i);
		return rs;

	}
};