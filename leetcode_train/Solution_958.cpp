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

//����������������սڵ�ʱ��ֹͣ������������涼�ǿսڵ㣬������ȫ������

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