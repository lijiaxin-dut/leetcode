#include<queue>
#include"TreeNode.h"
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

//层序遍历，当遇到空节点时，停止遍历，如果后面都是空节点，则是完全二叉树

class Solution {

public:
	bool isCompleteTree(TreeNode* root) {
		queue<TreeNode*>q;
		q.push(root);
		while (!q.empty() && q.front() != nullptr) {
			auto root = q.front();
			q.pop();
			q.push(root->left);
			q.push(root->right);
		}
		while (!q.empty() && q.front() == nullptr)
			q.pop();
		return q.empty();
	}
};