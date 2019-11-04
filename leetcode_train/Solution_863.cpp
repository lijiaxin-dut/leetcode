#include"TreeNode.h"
#include<vector>
#include<unordered_map>
#include<unordered_set>

using namespace std;



/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/

//We are given a binary tree(with root node root), a target node, and an integer value K.
//
//Return a list of the values of all nodes that have a distance K from the target node.The answer can be returned in any order.
//
//
//
//Example 1:
//
//Input: root = [3, 5, 1, 6, 2, 0, 8, null, null, 7, 4], target = 5, K = 2
//
//	Output : [7, 4, 1]
//
//	Explanation :
//	The nodes that are a distance 2 from the target node(with value 5)
//	have values 7, 4, and 1.
//


//使用辅助变量构造每个节点的父亲节点
//使用mark标记已经判断过的节点

//不断的在左子树，右子树，父亲子树中寻找


class Solution_863 {
public:
	vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
		unordered_map<TreeNode*, TreeNode*>parents;
		unordered_set<TreeNode*>mark;
		generate_parent(root, parents);
		vector<int>res;
		help(res, target, K, parents, mark);
		return res;
	}
	void generate_parent(TreeNode* root, unordered_map<TreeNode*, TreeNode*>&parents) {
		if (root->left) {
			parents[root->left] = root;
			generate_parent(root->left, parents);
		}
		if (root->right) {
			parents[root->right] = root;
			generate_parent(root->right, parents);
		}
	}
	void help(vector<int>&res, TreeNode*x, int K, unordered_map<TreeNode*, TreeNode*>&parents, unordered_set<TreeNode*>mark) {
		if (mark.find(x) != mark.end())
			return;
		mark.insert(x);
		if (K == 0) {
			res.push_back(x->val);
			return;
		}
		if (x->left)
			help(res, x->left, K - 1, parents, mark);
		if (x->right)
			help(res, x->right, K - 1, parents, mark);
		if (parents.find(x) != parents.end())
			help(res, parents[x], K - 1, parents, mark);
	}


};
