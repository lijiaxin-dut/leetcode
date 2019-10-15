#include"ListNode.h"
#include<iostream>

//Remove all elements from a linked list of integers that have value val.
//
//Example:
//
//Input:  1->2->6->3->4->5->6, val = 6
//	Output : 1->2->3->4->5

//�������ڵ�
//ע��ʲôʱ��ָ�����

class Solution {
public:
	ListNode* removeElements(ListNode* head, int val) {
		ListNode *dumy = new ListNode(-1);
		dumy->next = head;
		head = dumy;
		while (head != NULL&&head->next != NULL) {
			if (head->next->val == val) {
				head->next = head->next->next;
			}
			else
				head = head->next;
		}
		return dumy->next;
	}
};