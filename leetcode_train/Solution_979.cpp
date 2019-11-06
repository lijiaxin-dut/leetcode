#include<vector>
#include"TreeNode.h"
#include<unordered_map>
#include<unordered_set>
#include<queue>

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
//
//Given the root of a binary tree with N nodes, each node in the tree has node.val coins, and there are N coins total.
//
//In one move, we may choose two adjacent nodes and move one coin from one node to another.  (The move may be from parent to child, or from child to parent.)
//
//Return the number of moves required to make every node have exactly one coin.


//hard
//
//     0
// 0       0
//4  0   3   0

//if we get '+3' from the left child, that means that the left subtree has 3 extra coins to move out.If we get '-1' from the right child, we need to move 1 coin in.So, we increase the number of moves by 4 (3 moves out left + 1 moves in right).

// then return the final ballance: r->val (coins in the root) + 3 (left) + (-1) (right) - 1 (keep one coin for the root).

class Solution_979 {
public:
	int ans = 0;
	int distributeCoins(TreeNode* root) {
		help(root);
		return ans;
	}
	int help(TreeNode *x) {
		if (x == NULL)
			return 0;
		int left = help(x->left);
		int right = help(x->right);
		ans += abs(left) + abs(right);
		return x->val + left + right - 1;//当前x节点多出的硬币或者缺少的硬币
	}
};
