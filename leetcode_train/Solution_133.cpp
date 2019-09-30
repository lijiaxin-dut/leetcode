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

//使用map标记该节点是否已经生成过

//old_node  ---->  new_node

//不用创建临时对象的引用
//指针所指对象相等，两个指针就相等


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
			//该节点已经生成过了
			if (hash_map.count(current_node) != 0) {
				new_node = hash_map[current_node];
			}
			else {
				//生成新的节点
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
