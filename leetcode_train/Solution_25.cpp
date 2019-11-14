#include"ListNode.h"


//
//Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
//
//k is a positive integer and is less than or equal to the length of the linked list.If the number of nodes is not a multiple of k then left - out nodes in the end should remain as it is.
//
//Example:
//
//Given this linked list : 1->2->3->4->5
//
//For k = 2, you should return : 2->1->4->3->5
//
//For k = 3, you should return : 3->2->1->4->5



//一边遍历一遍将链表进行反转
//注意链表不要断开

//


class Solution_25 {
public:
	ListNode* reverseKGroup(ListNode* head, int k) {
		if (head == nullptr || k == 1)
			return head;
		ListNode*dumy = new ListNode(-1);
		ListNode *pre = dumy;
		pre->next = head;
		ListNode *cur = head;
		for (int i = 1; cur != nullptr; i++) {
			if (i%k == 0) {
				ListNode *cur_next = cur->next;
				cur->next = nullptr;
				auto new_head = reverseLinklist(pre->next, cur_next);
				auto new_pre = pre->next;
				pre->next = new_head;
				pre = new_pre;
				cur = cur_next;
			}
			else {
				cur = cur->next;
			}
		}
		return dumy->next;

	}
	ListNode *reverseLinklist(ListNode *head, ListNode *h) {
		if (head == nullptr)
			return head;
		ListNode *p1 = head;
		ListNode *p2 = head->next;
		head->next = h;
		while (p2 != nullptr) {
			ListNode *p3 = p2->next;
			p2->next = p1;
			p1 = p2;
			p2 = p3;
		}
		return p1;
	}
};

