#include"TreeNode.h"
#include<unordered_map>
#include<algorithm>
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

//���������������ڵĽڵ�
//�Ե����ϵݹ�

//�������ڵ�
//hash_map[root]=
//hash_map[root->left->left]+hash_map[root->left->right]+
//hash_map[root->right->left]+hash_map[root->right->right]+root->val

//���������ڵ�
//hash_map[root]=hash_map[root->left]+hash_map[root->right]

//�������ѡ���


class Solution_337 {
public:
	int rob(TreeNode* root) {
		unordered_map<TreeNode*, int>hash_map;//hash_map[x] ��ʾ��xΪ���ڵ��tree�����ֵ
		return dfs(root, hash_map);
	}
	int dfs(TreeNode*x, unordered_map<TreeNode*, int>&hash_map) {
		if (x == NULL)
			return 0;
		if (hash_map.find(x) != hash_map.end())
			return hash_map[x];
		int val = 0;
		if (x->left)
			val += dfs(x->left->left, hash_map) + dfs(x->left->right, hash_map);
		if (x->right)
			val += dfs(x->right->left, hash_map) + dfs(x->right->right, hash_map);
		val = max(dfs(x->left, hash_map) + dfs(x->right, hash_map), val + x->val);
		hash_map[x] = val;
		return val;

	}
};