#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>
#include"ListNode.h"

using namespace std;

//Given a linked list, swap every two adjacent nodes and return its head.
//
//You may not modify the values in the list's nodes, only nodes itself may be changed.
//
//
//
//Example:
//
//Given 1->2->3->4, you should return the list as 2->1->4->3.


//ʹ������ָ�룬����ָ���ָ�򼴿�
//��ͼ�������
//���������ڵ�


class Solution_24 {
public:
	ListNode* swapPairs(ListNode* head) {
		if (head == NULL || head->next == NULL)
			return head;
		ListNode *dumy = new ListNode(-1);
		dumy->next = head;
		ListNode *before = dumy;
		ListNode *current = head;
		ListNode *after = head->next;
		while (true) {
			current->next = after->next;
			before->next = after;
			after->next = current;

			before = current;
			current = current->next;
			if (current == NULL || current->next == NULL)
				break;
			after = current->next;
		}
		return dumy->next;
	}
};