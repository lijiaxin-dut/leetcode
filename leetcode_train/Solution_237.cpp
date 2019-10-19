#include"ListNode.h"

//
//Write a function to delete a node(except the tail) in a singly linked list, given only access to that node.
//
//Given linked list -- head = [4, 5, 1, 9], which looks like following :

//改变当前节点的next指针的指向和值

class Solution_237 {
public:
	void deleteNode(ListNode* node) {
		node->val = node->next->val;
		node->next = node->next->next;
	}
};