#pragma once
#include<vector>
class edge {
public:
	int start_node;
	int end_node;
	edge(int s = -1, int e = -1) {
		this->start_node = s;
		this->end_node = e;
	}
};
class graph {
public:
	std::vector<std::vector<edge>>adj;
	int n;

	graph(int n) {
		this->n = n;
		adj.resize(n);
	}

	void add_edge(int s, int e) {
		adj[s].emplace_back(s, e);
	}
	graph reverse_graph() {
		graph g(n);
		for (auto &one_node : this->adj) {
			for (auto &one_edge : one_node) {
				g.adj[one_edge.end_node].emplace_back(one_edge.end_node, one_edge.start_node);
			}
		}
		return g;

	}
};
