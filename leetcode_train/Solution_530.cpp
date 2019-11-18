#include<vector>
#include"TreeNode.h"
#include<algorithm>



using namespace std;

//Given a binary search tree with non - negative values, find the minimum absolute difference between values of any two nodes.
//
//Example:
//
//Input:
//
//1
//\
//3
///
//2
//



//中序遍历，记录前驱节点
//

class Solution_530 {
public:
	int getMinimumDifference(TreeNode* root) {
		int rs = INT_MAX;
		TreeNode *pre = nullptr;
		inorder(root, rs, pre);
		return rs;
	}
	void inorder(TreeNode *node, int &rs, TreeNode *&pre) {
		if (node == nullptr)
			return;
		inorder(node->left, rs, pre);
		if (pre != nullptr) {
			rs = min(rs, abs(node->val - pre->val));
		}
		pre = node;
		inorder(node->right, rs, pre);



	}
};