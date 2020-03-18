#include"Graph.h"
#include<stack>
#include<iostream>
#include<algorithm>
using namespace std;

//拓扑排序
//dfs的后续遍历的逆后续，就是拓扑排序的结果

//或者使用队列来操作
//使用集合S表示入度为0的节点
//不断的遍历S中的点，并且将对应的入度减一
//

//最长路径
//按照拓扑排序的顺序松弛

class topolo_gical {
public:
	vector<bool>marked;
	vector<int>nodes_id;

	void topolo_gical_dfs(graph &g) {
		marked.resize(g.n, false);
		nodes_id.clear();
		for (int i = 0; i < g.n; i++) {
			if (marked[i] == false)
				dfs(g, i);
		}
		reverse(nodes_id.begin(), nodes_id.end());
	}
	void dfs(graph &g, int v) {
		marked[v] = true;
		for (auto &out_edge : g.adj[v]) {
			int w = out_edge.end_node;
			if (marked[w] == false) {
				dfs(g, w);
			}		
		}
		nodes_id.push_back(v);
	}
	void topolo_gical_queue(graph &g) {
		nodes_id.clear();
		vector<int>in_degree(g.n,0);
		for (auto &one_node : g.adj) {
			for (auto &one_edge : one_node) {
				in_degree[one_edge.end_node]++;
			}
		}
		deque<int>S;
		for (int i = 0; i < g.n; i++) {
			if (in_degree[i] == 0) {
				S.push_back(i);
			}
		}
		while (!S.empty()) {
			int current_node = S.front();
			S.pop_front();
			nodes_id.push_back(current_node);
			for (auto &one_edge : g.adj[current_node]) {
				in_degree[one_edge.end_node]--;
				if (in_degree[one_edge.end_node] == 0)
					S.push_back(one_edge.end_node);
			}
			
		}
	
	}

};

//int main() {
//	graph g(13);
//	g.add_edge(0, 1);
//	g.add_edge(0, 5);
//	g.add_edge(0, 6);
//	g.add_edge(2, 0);
//	g.add_edge(2, 3);
//	g.add_edge(3, 5);
//	g.add_edge(5, 4);
//	g.add_edge(6, 4);
//	g.add_edge(6, 9);
//	g.add_edge(7, 6);
//	g.add_edge(8, 7);
//	g.add_edge(9, 10);
//	g.add_edge(9, 11);
//	g.add_edge(9, 12);
//	g.add_edge(11, 12);
//	topolo_gical top;
//	top.topolo_gical_dfs(g);
//	if (!top.nodes_id.empty()) {
//		for (auto &i : top.nodes_id)
//			cout << i << "\t";
//	}
//	cout << endl;
//	top.topolo_gical_queue(g);
//	if (!top.nodes_id.empty()) {
//		for (auto &i : top.nodes_id)
//			cout << i << "\t";
//	}
//}