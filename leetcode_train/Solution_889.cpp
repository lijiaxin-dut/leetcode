#include"TreeNode.h"
#include<vector>

using namespace std;

//
//Return any binary tree that matches the given preorder and postorder traversals.
//
//Values in the traversals pre and post are distinct positive integers.

//前序  根左右
//后续  左右根
//自底向上递归
//紧接着根节点的为左子树的根节点，在后续中找到该节点，就可以将序列中的左右子树区分开


class Solution_889 {
public:
	TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
		int pre_end = pre.size() - 1;
		int post_end = post.size() - 1;
		return help(pre, 0, pre_end, post, 0, post_end);
	}
	TreeNode*help(vector<int>& pre, int pre_start, int pre_end, vector<int>& post, int post_start, int post_end) {
		if (pre_start>pre_end)
			return nullptr;
		if (pre_start == pre_end)
			return new TreeNode(pre[pre_start]);
		TreeNode*new_node = new TreeNode(pre[pre_start]);
		int back_post_start = post_start;
		int length = 0;
		while (back_post_start <= post_end) {
			if (pre[pre_start + 1] == post[back_post_start++])
				break;
			else
				length++;
		}

		new_node->left = help(pre, pre_start + 1, pre_start + 1 + length, post, post_start, back_post_start - 1);
		new_node->right = help(pre, pre_start + 1 + length + 1, pre_end, post, back_post_start, post_end - 1);
		return new_node;

	}
};