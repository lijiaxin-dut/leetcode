#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>
#include"ListNode.h"

using namespace std;

//Description
//Given a linked list, rotate the list to the right by k places, where k is non-negative.
//Input: 1->2->3->4->5->NULL, k = 2
//	Output : 4->5->1->2->3->NULL
//	Explanation :
//	rotate 1 steps to the right : 5->1->2->3->4->NULL
//	rotate 2 steps to the right : 4->5->1->2->3->NULL

// 单独考虑空链表或者链表的长度为1
// 单独考虑整数倍

class Solution_61 {
	int cumpute_length(ListNode *head) {
		int length = 0;
		while (head != NULL) {
			length++;
			head = head->next;
		}
		return length;

	}
public:
	ListNode* rotateRight(ListNode* head, int k) {
		if (head == NULL || head->next == NULL)
			return head;
		int length = cumpute_length(head);
		k = k%length;
		if (k == 0)
			return head;
		ListNode dumy(-1);
		dumy.next = head;
		ListNode *first = &dumy;
		ListNode *second = &dumy;
		for (int i = 0; i<k; i++) {
			first = first->next;
		}
		while (first->next != NULL) {
			first = first->next;
			second = second->next;
		}
		ListNode *newhead = second->next;
		second->next = NULL;
		first->next = head;
		return newhead;
	}
};
//int main() {
//	ListNode *n1 = new ListNode(1);
//	ListNode *n2 = new ListNode(2);
//	ListNode *n3 = new ListNode(3);
//	ListNode *n4 = new ListNode(4);
//	ListNode *n5 = new ListNode(5);
//	n1->next = n2;
//	n2->next = n3;
//	n3->next = n4;
//	n4->next = n5;
//	Solution_61 s;
//	s.rotateRight(n1, 6);
//}