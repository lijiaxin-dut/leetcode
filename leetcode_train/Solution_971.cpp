#include<vector>
#include"TreeNode.h"

using namespace std;

//给定一颗二叉树和二叉树的前序遍历
//判断能否交换二叉树的左右节点，使得前序遍历的结果是正确的

//始终判断当前节点是否与数组中的节点相等
//然后判断左子树是否与下一个数组中的数字相等

//若不相等，则先遍历右子树，后遍历左子树
//



class Solution_971 {
public:
	vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
		int index = 0;
		vector<int>rs;
		dfs(rs, root, index, voyage);
		if (!rs.empty() && rs[0] == -1)
		{
			rs.clear();
			rs.push_back(-1);
		}
		return rs;
	}
	void dfs(vector<int>&rs, TreeNode*x, int &index, vector<int>& voyage) {
		if (x == NULL)
			return;
		if (x->val != voyage[index]) {
			rs.clear();
			rs.push_back(-1);
			return;
		}
		index++;
		if (x->left != NULL&&x->left->val != voyage[index]) {
			rs.push_back(x->val);
			dfs(rs, x->right, index, voyage);
			dfs(rs, x->left, index, voyage);
		}
		else {
			dfs(rs, x->left, index, voyage);
			dfs(rs, x->right, index, voyage);
		}

	}
};