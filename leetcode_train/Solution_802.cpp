#include<vector>
#include<set>
#include<queue>


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



class Solution_802 {
public:
	vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
		vector<int> rs;
		int n = graph.size();
		vector<bool>mark(n, false);
		vector<set<int>> g(n, set<int>());
		vector<set<int>> revg(n, set<int>());
		queue<int> q;

		for (int i = 0; i<n; i++) {
			if (graph[i].empty())
				q.push(i);
			for (auto j : graph[i]) {
				g[i].insert(j);
				revg[j].insert(i);
			}
		}
		while (!q.empty()) {
			int t = q.front();
			q.pop();
			mark[t] = true;
			for (auto &in : revg[t]) {
				g[in].erase(t);
				if (g[in].empty())
					q.push(in);
			}
		}
		for (int i = 0; i<n; i++) {
			if (mark[i])
				rs.push_back(i);
		}
		return rs;


	}
};