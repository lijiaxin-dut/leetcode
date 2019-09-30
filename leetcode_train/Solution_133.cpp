#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>
#include<memory>
#include<unordered_map>
#include<set>
#include<queue>

using namespace std;


//Given a reference of a node in a connected undirected graph, 
//return a deep copy(clone) of the graph.Each node in the graph 
//contains a val(int) and a list(List[Node]) of its neighbors.

//ʹ��map��Ǹýڵ��Ƿ��Ѿ����ɹ�

//old_node  ---->  new_node

//���ô�����ʱ���������
//ָ����ָ������ȣ�����ָ������


class Node_graph {
public:
	int val;
	vector<Node_graph*> neighbors;

	Node_graph() {}

	Node_graph(int _val, vector<Node_graph*> _neighbors) {
		val = _val;
		neighbors = _neighbors;
	}
};



class Solution_134 {
public:
	Node_graph* cloneGraph(Node_graph* node) {
		queue<Node_graph*>todo_node;
		todo_node.push(node);
		unordered_map<Node_graph*, Node_graph*>hash_map;
		int i = 0;
		while (!todo_node.empty()) {
			auto current_node = todo_node.front();
			todo_node.pop();
			Node_graph*new_node;
			//�ýڵ��Ѿ����ɹ���
			if (hash_map.count(current_node) != 0) {
				new_node = hash_map[current_node];
			}
			else {
				//�����µĽڵ�
				new_node = new Node_graph();
				new_node->val = current_node->val;
				hash_map[current_node] = new_node;
			}
			for (auto one_neighbor : current_node->neighbors) {
				if (hash_map.count(one_neighbor) == 0) {
					Node_graph *new_neigh = new Node_graph();
					new_neigh->val = one_neighbor->val;
					hash_map[one_neighbor] = new_neigh;
					todo_node.push(one_neighbor);
					new_node->neighbors.push_back(new_neigh);
				}
				else
					new_node->neighbors.push_back(hash_map[one_neighbor]);
			}


		}
		return hash_map[node];

	}
};
