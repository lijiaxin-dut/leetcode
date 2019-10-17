#include"ListNode.h"
#include<iostream>

//Reverse a singly linked list.
//
//Example:
//
//Input: 1->2->3->4->5->NULL
//	Output : 5->4->3->2->1->NULL


//递归或者非递归
//递归  不断的向后走，回溯时修改指针
//注意修改头指针的next指针为空


class Solution_206 {
public:
	ListNode* reverseList_recursive(ListNode* head) {
		if (head == NULL || head->next == NULL)
			return head;
		return help(head);

	}
	ListNode* help(ListNode *p1) {
		if (p1 == NULL || p1->next == NULL)
			return p1;
		ListNode *p = help(p1->next);
		p1->next->next = p1;
		p1->next = NULL;
		return p;


	} 
	ListNode* reverseList_iterator(ListNode* head) {
		if (head == NULL || head->next == NULL)
			return head;
		ListNode *p1 = head;
		ListNode *p2 = head->next;
		p1->next = NULL;
		ListNode *p3;
		while (p2 != NULL) {
			p3 = p2->next;
			p2->next = p1;
			p1 = p2;
			p2 = p3;
		}
		return p1;

	}
};