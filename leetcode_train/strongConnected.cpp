#include"Graph.h"
#include<stack>
#include<iostream>
#include<algorithm>
#include<unordered_map>
using namespace std;

//������ͼ�м���ǿ��ͨ����

//��������ͼG
//���ȼ���G�ķ���ͼG_R
//�õ�G_R��dfs�����������
//������������У���G�н���dfs
//ÿ��dfs��õ�һ��ǿ��ͨ����



class SCC {
private:
	//������������
	vector<int>nodes_id;
	void topolo_gical_dfs(graph &g) {
		vector<bool>marked;
		marked.resize(g.n, false);
		nodes_id.clear();
		for (int i = 0; i < g.n; i++) {
			if (marked[i] == false)
				dfs(g, i, marked);
		}
		reverse(nodes_id.begin(), nodes_id.end());
	}
	void dfs(graph &g, int v, vector<bool>&marked) {
		marked[v] = true;
		for (auto &out_edge : g.adj[v]) {
			int w = out_edge.end_node;
			if (marked[w] == false) {
				dfs(g, w, marked);
			}
		}
		nodes_id.push_back(v);
	}
	
public:
	int count = 0;
	unordered_map<int,vector<int>>id;
	vector<bool>marked;
	//����ǿ��ͨ����
	void find_strong_connedted(graph &g) {
		marked.resize(g.n);
		auto re_f = g.reverse_graph();
		this->topolo_gical_dfs(re_f);
		for (auto &i : this->nodes_id) {
			if (marked[i] == false) {
				dfs(g, i);
				count++;
			}
		}
		
	}
	void dfs(graph &g, int v) {
		marked[v] = true;;
		id[count].push_back(v);
		for (auto &one_edge : g.adj[v]) {
			if (marked[one_edge.end_node] == false)
				dfs(g, one_edge.end_node);
		}
	}


};

int main() {
	graph g(13);
	g.add_edge(0, 1);
	g.add_edge(0, 5);
	g.add_edge(2, 0);
	g.add_edge(2, 3);
	g.add_edge(3, 2);
	g.add_edge(3, 5);
	g.add_edge(4, 2);
	g.add_edge(4, 3);
	g.add_edge(5, 4);
	g.add_edge(6, 0);
	g.add_edge(6, 4);
	g.add_edge(6, 9);
	g.add_edge(7,6);
	g.add_edge(7, 8);
	g.add_edge(8, 7);
	g.add_edge(8, 9);
	g.add_edge(9, 10);
	g.add_edge(9, 11);
	g.add_edge(10, 12);
	g.add_edge(11, 4);
	g.add_edge(11, 12);
	g.add_edge(12, 9);
	SCC s;
	s.find_strong_connedted(g);
	for (auto &one_com : s.id) {
		for (auto &one_con_id : one_com.second) {
			cout << one_con_id << "\t";
		}
		cout << endl;
	}

}