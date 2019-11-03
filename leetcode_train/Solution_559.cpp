#include<vector>
#include<algorithm>
using namespace std;

//Given a n - ary tree, find its maximum depth.
//
//The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
//
//For example, given a 3 - ary tree :

//返回子节点的最大值+1


class Solution_559 {
public:
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
	int maxDepth(Node* root) {
		if (root == NULL)
			return 0;
		return help(root);
	}
	int help(Node *x) {
		if (x == NULL)
			return 1;
		int rs = 0;
		for (auto &child : x->children) {
			rs = max(rs, help(child));
		}
		return rs + 1;
	}
};