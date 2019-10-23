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

//不能抢劫两个相邻的节点
//自底向上递归

//包括根节点
//hash_map[root]=
//hash_map[root->left->left]+hash_map[root->left->right]+
//hash_map[root->right->left]+hash_map[root->right->right]+root->val

//不包括根节点
//hash_map[root]=hash_map[root->left]+hash_map[root->right]

//上面二者选最大


class Solution_337 {
public:
	int rob(TreeNode* root) {
		unordered_map<TreeNode*, int>hash_map;//hash_map[x] 表示以x为根节点的tree的最大值
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