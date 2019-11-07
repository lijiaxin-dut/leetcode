#include<vector>
#include<queue>
using namespace std;


//
//Given an n - ary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).
//
//For example, given a 3 - ary tree :
//
//
//
//We should return its level order traversal :
//
//[
//	[1],
//	[3, 2, 4],
//	[5, 6]
//]


//BFS

class Solution_429 {
	class Node {
	public:
		int val;
		vector<Node*> children;

		Node() {}

		Node(int _val, vector<Node*> _children) {
			val = _val;
			children = _children;
		}
	};
public:
	vector<vector<int>> levelOrder(Node* root) {

		vector<vector<int>>rs;
		if (root == nullptr)
			return rs;
		queue<Node*>q;
		q.push(root);
		while (!q.empty()) {
			int level_size = q.size();
			vector<int>cur_level;
			for (int i = 0; i<level_size; i++) {
				auto t = q.front();
				q.pop();
				cur_level.push_back(t->val);
				for (auto &child : t->children) {
					q.push(child);
				}
			}
			rs.push_back(cur_level);
		}
		return rs;

	}
};