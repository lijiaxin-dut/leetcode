#include"TreeNode.h"
#include<unordered_set>

using namespace std;


class Solution_653 {
	unordered_set<int>hash_set;
public:
	bool findTarget(TreeNode* root, int k) {
		bool find = false;
		dfs(root, k, find);
		return find;
	}
	void dfs(TreeNode *root, int k, bool &find) {
		if (root == nullptr || find == true)
			return;
		if (hash_set.count(root->val) != 0) {
			find = true;
			return;
		}
		hash_set.insert(k - root->val);
		dfs(root->left, k, find);
		dfs(root->right, k, find);

	}
};