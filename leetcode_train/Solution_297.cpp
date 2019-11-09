#include"TreeNode.h"
#include<sstream>

using namespace std;

//序列化和反序列化二叉树

//序列化：dfs保存所有的节点
//反序列化：第一个元素为根节点
//自底向上递归，遇到标记符时，返回根节点


/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
class Codec_297 {
	void help_serialize(TreeNode *node, ostringstream  &out) {
		if (node != NULL) {
			out << node->val << " ";
			help_serialize(node->left, out);
			help_serialize(node->right, out);
		}
		else {
			out << "# ";
		}
	}

	TreeNode* help_deserialize(istringstream &in) {
		string val;
		in >> val;
		if (val == "#")
			return NULL;
		TreeNode *node = new TreeNode(stoi(val));
		node->left = help_deserialize(in);
		node->right = help_deserialize(in);
		return node;
	}
public:

	// Encodes a tree to a single string.
	string serialize(TreeNode* root) {
		ostringstream out;
		help_serialize(root, out);
		return out.str();
	}

	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data) {
		istringstream in(data);
		return help_deserialize(in);
	}
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));