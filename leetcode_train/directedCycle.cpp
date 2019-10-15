#include"Graph.h"
#include<stack>
#include<iostream>
using namespace std;

//����ͼ�Ļ����

class directed_cycle {
	vector<bool>marked;//�����Щ���Ѿ������ʹ�
	vector<bool>on_stack;//�����Щ���ڵ�ǰ�ĵݹ�ջ�ϣ����һ�����ظ����֣���˵���������һ������
	vector<edge>edge_to;
	void dfs(graph &g, int v) {
		marked[v] = true;
		on_stack[v] = true;
		for (auto &out_edge : g.adj[v]) {
			int w = out_edge.end_node;
			if (has_cycle == true)
				return;
			else if (marked[w] == false) {
				edge_to[w] = out_edge;
				dfs(g, w);
			}
			//�ҵ���һ����
			else if (on_stack[w] == true) {
				has_cycle = true;
				//�ӵ�ǰ�ڵ�һֱ��ǰ�ң��ҵ��ýڵ�Ϊֹ����˵���ҵ���һ����
				for (edge e = out_edge; e.start_node != w; e = edge_to[e.start_node]) {
					cycle.push_back(e.start_node);
				}
				cycle.push_back(w);
				cycle.push_back(v);
				reverse(cycle.begin(), cycle.end());
			}
		}
		on_stack[v] = false;
	}
public:
	bool has_cycle = false;
	vector<int>cycle;
	void print_cycle() {
		for (int i = 0; i < cycle.size(); i++) {
			cout << cycle[i]<<"\t";
		}
	}
	directed_cycle(graph &g) {
		edge_to.resize(g.n);
		marked.resize(g.n,false);
		on_stack.resize(g.n, false);
		for (int i = 0; i < g.n; i++) {
			if (marked[i] == false)
				dfs(g, i);
		}
		
	}


	
};

//int main() {
//	graph g(5);
//	g.add_edge(0, 1);
//	g.add_edge(1, 2);
//	g.add_edge(2, 3);
//	g.add_edge(3, 4);
//	g.add_edge(4, 1);
//	directed_cycle d(g);
//	if (d.has_cycle == true) {
//		d.print_cycle();
//	}
//};
