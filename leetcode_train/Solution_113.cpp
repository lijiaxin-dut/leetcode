#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>
#include<queue>
#include"TreeNode.h"

using namespace std;

class Solution_113 {
public:
	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		vector<vector<int>> rs;
		vector<int>partial_rs;
		int current_sum = 0;
		help(rs, partial_rs, root, current_sum, sum);
		return rs;
	}
	void help(vector<vector<int>> &rs, vector<int>&partial_rs, TreeNode*root, int &current_sum, int sum) {
		if (root == NULL)
			return;
		current_sum += root->val;
		partial_rs.push_back(root->val);
		if (root->left == NULL&&root->right == NULL) {
			if (current_sum == sum) {
				rs.push_back(partial_rs);
			}
			current_sum -= root->val;
			partial_rs.pop_back();
			return;
		}
		help(rs, partial_rs, root->left, current_sum, sum);
		help(rs, partial_rs, root->right, current_sum, sum);
		current_sum -= root->val;
		partial_rs.pop_back();

	}
};

//int main() {
//	TreeNode *t1 = new TreeNode(5);
//	TreeNode *t2 = new TreeNode(4);
//	TreeNode *t3 = new TreeNode(8);
//	t1->left = t2;
//	t1->right = t3;
//	TreeNode *t4 = new TreeNode(11);
//	t2->left = t4;
//	TreeNode *t5 = new TreeNode(7);
//	TreeNode *t6 = new TreeNode(2);
//	t4->left = t5;
//	t4->right = t6;
//	Solution_113 s;
//	s.pathSum(t1, 22);
//}
