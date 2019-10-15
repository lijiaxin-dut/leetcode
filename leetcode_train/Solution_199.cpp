#include<vector>
#include"TreeNode.h"
#include<queue>

using namespace std;

//Given a binary tree, imagine yourself standing on the right side of it, 
//return the values of the nodes you can see ordered from top to bottom.

//bfs即可

//也可以用dfs
//跟-右-左的顺序
//记录当前的层数，当第一次达到该层时，保存该节点


class Solution_199 {
public:
	vector<int> rightSideView(TreeNode* root) {
		if (root == NULL)
			return{};
		vector<int>rs;
		queue<TreeNode*>Q;
		Q.push(root);
		while (!Q.empty()) {
			int l = Q.size();
			rs.push_back(Q.front()->val);
			for (int i = 0; i<l; i++) {
				root = Q.front();
				Q.pop();
				if (root->right != NULL)
					Q.push(root->right);
				if (root->left != NULL)
					Q.push(root->left);
			}
		}
		return rs;
	}
};