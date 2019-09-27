#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>
#include<queue>
#include"TreeNode.h"
#include"ListNode.h"

using namespace std;

//Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
//
//For this problem, a height - balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
//
//Example:
//
//Given the sorted linked list : [-10, -3, 0, 5, 9],
//
//One possible answer is : [0, -3, 9, -10, null, 5], which represents the following height balanced BST :
//
//0
/// \
//- 3   9
/// /
//-10  5

//递归调用
//快慢指针找到链表的终点，作为根节点
//链表前半部分为左子树
//链表后半部分为右子树


class Solution_109 {
public:
	TreeNode* sortedListToBST(ListNode* head) {
		return help(head);
	}
	TreeNode*help(ListNode *head) {
		if (head == NULL)
			return NULL;
		if (head->next == NULL)
			return new TreeNode(head->val);
		ListNode*fast = head;
		ListNode*slow = head;
		ListNode*pre_slow = head;
		while (fast&&fast->next) {
			fast = fast->next->next;
			pre_slow = slow;
			slow = slow->next;
		}
		TreeNode*root = new TreeNode(slow->val);
		pre_slow->next = NULL;
		root->left = help(head);
		root->right = help(slow->next);
		return root;
	}
};