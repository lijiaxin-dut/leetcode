#include"Graph.h"
#include<stack>
#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<queue>
using namespace std;

//基于队列优化的bellman ford

//SPFA

//负环检测
//
//BELLMAN - FORD(G, w, s)
//1  INITIALIZE - SINGLE - SOURCE(G, s)
//   进行V-1次松弛，因为当没有环时，路径最长为n-1个点
//   d[s]=0
//2  for i ← 1 to | V[G] | -1
//3       do for each edge(u, v) ∈ E[G]
//4              do RELAX(u, v, w)
//5  for each edge(u, v) ∈ E[G]
//6       do if d[v] > d[u] + w(u, v)
//7             then return FALSE
//8  return TRUE


class SPFA {
	vector<int>hop_to_each_node;
	vector<bool>on_queue;	
	queue<int>Q;
	void spfa(graph &g,int s) {
		hop_to_each_node.resize(g.n);
		on_queue.resize(g.n);
		Q.push(s);
		on_queue[s] = true;
		while (!Q.empty()) {
			int current_node = Q.front();
			Q.pop();
			on_queue[current_node] = false;
			for (auto &out_edge : g.adj[current_node]) {
				int w = out_edge.end_node;
				if (hop_to_each_node[w] > hop_to_each_node[current_node] + 1) {
					hop_to_each_node[w] = hop_to_each_node[current_node] + 1;
					if (on_queue[w] == false) {
						Q.push(w);
						on_queue[w] = true;
					}
				}
			}
			
		}
		
	}

};