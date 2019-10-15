#include<vector>
#include"TreeNode.h"
#include<queue>

using namespace std;

//Given a binary tree, imagine yourself standing on the right side of it, 
//return the values of the nodes you can see ordered from top to bottom.

//bfs����

//Ҳ������dfs
//��-��-���˳��
//��¼��ǰ�Ĳ���������һ�δﵽ�ò�ʱ������ýڵ�


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