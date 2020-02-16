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
	Node_graph(int val) :val(val){}
	Node_graph(int _val, vector<Node_graph*> _neighbors) {
		val = _val;
		neighbors = _neighbors;
	}
};



class Solution_134 {
public:
	Node_graph* cloneGraph(Node_graph* node) {
		if (node == nullptr)
			return nullptr;
		unordered_map<Node_graph*, Node_graph*>hash_map;
		queue<Node_graph*>todo;
		todo.push(node);
		Node_graph *root = node;
		while (!todo.empty()) {
			node = todo.front();
			todo.pop();
			Node_graph*new_node = nullptr;
			if (hash_map.find(node) != hash_map.end()) {
				new_node = hash_map[node];
			}
			else {
				new_node = new Node_graph(node->val);
				hash_map[node] = new_node;
			}
			for (auto one_neighbor : node->neighbors) {
				if (hash_map.find(one_neighbor) != hash_map.end()) {
					new_node->neighbors.push_back(hash_map[one_neighbor]);
				}
				else {
					Node_graph *new_nei_node = new Node_graph(one_neighbor->val);
					hash_map[one_neighbor] = new_nei_node;
					new_node->neighbors.push_back(new_nei_node);
					todo.push(one_neighbor);
				}
			}
		}
		return hash_map[root];

	}
};
