#include"TreeNode.h"
#include"ListNode.h"

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
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
//Given a binary tree root and a linked list with head as the first node.
//
//Return True if all the elements in the linked list starting from the head correspond to some downward path connected in the binary tree otherwise return False.
//
//In this context downward path means a path that starts at some node and goes downwards.
//


//dfsÅÐ¶Ï
//return help(head->next, node->left) || help(head->next, node->right);

class Solution {
public:
	bool isSubPath(ListNode* head, TreeNode* root) {
		if (root == nullptr)
			return false;
		return help(head, root) || isSubPath(head, root->left) || isSubPath(head, root->right);
	}
	bool help(ListNode*head, TreeNode*node) {
		if (head == nullptr&&node == nullptr)
			return true;
		if (head != nullptr&&node == nullptr)
			return false;
		if (head == nullptr&&node != nullptr)
			return true;
		if (head->val != node->val)
			return false;
		return help(head->next, node->left) || help(head->next, node->right);
	}
};