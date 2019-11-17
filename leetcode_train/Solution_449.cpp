#include<string>
#include"TreeNode.h"
#include<sstream>

using namespace std;

//Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.
//
//Design an algorithm to serialize and deserialize a binary search tree.There is no restriction on how your serialization / deserialization algorithm should work.You just need to ensure that a binary search tree can be serialized to a string and this string can be deserialized to the original tree structure.
//
//The encoded string should be as compact as possible.
//
//Note: Do not use class member / global / static variables to store states.Your serialize and deserialize algorithms should be stateless.

//dfs¼´¿É

class Codec {
public:

	// Encodes a tree to a single string.
	string serialize(TreeNode* root) {
		string rs;
		help_serialize(root, rs);
		return rs;
	}
	void help_serialize(TreeNode*node, string &rs) {
		//cout<<1;
		if (node == NULL) {
			rs += "# ";
			return;
		}
		rs += to_string(node->val) + " ";
		help_serialize(node->left, rs);
		help_serialize(node->right, rs);
	}

	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data) {
		istringstream in(data);
		return help_deserialize(in);
	}

	TreeNode* help_deserialize(istringstream &in) {
		string val;
		in >> val;
		if (val == "#") {
			return NULL;
		}
		TreeNode *new_node = new TreeNode(stoi(val));
		new_node->left = help_deserialize(in);
		new_node->right = help_deserialize(in);
		return new_node;
	}


};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
int main() {
	TreeNode *n1 = new TreeNode(1);
	TreeNode *n2 = new TreeNode(2);
	TreeNode *n3 = new TreeNode(3);
	n1->left = n2;
	n1->right = n3;
	Codec d;
	d.serialize(n1);
}