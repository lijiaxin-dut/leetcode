#include<stack>
#include<vector>

using namespace std;

//Given an n - ary tree, return the preorder traversal of its nodes' values.
//
//Nary - Tree input serialization is represented in their level order traversal, each group of children is separated by the null value(See examples).

//使用栈，在将子节点放入栈中时，从右向左放入


class Solution_589 {
	class Node {
	public:
		int val;
		vector<Node*> children;

		Node() {}

		Node(int _val) {
			val = _val;
		}

		Node(int _val, vector<Node*> _children) {
			val = _val;
			children = _children;
		}
	};
public:
	vector<int> preorder(Node* root) {
		stack<Node*>s;
		vector<int>rs;
		while (!s.empty() || root != nullptr) {
			rs.push_back(root->val);
			for (int i = (int)root->children.size() - 1; i >= 1; i--) {
				s.push(root->children[i]);
			}
			if (root->children.empty()) {
				if (!s.empty()) {
					root = s.top();
					s.pop();
				}
				else {
					root = nullptr;
				}
			}
			else {
				root = root->children[0];
			}

		}
		return rs;
	}
};