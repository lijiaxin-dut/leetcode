#include"ListNode.h"
#include<iostream>

using namespace std;

//Sort a linked list in O(n log n) time using constant space complexity.
//
//Example 1:
//
//Input: 4->2->1->3
//	Output : 1->2->3->4
//	Example 2 :
//
//	Input : -1->5->3->4->0
//	Output : -1->0->3->4->5

//使用归并排序
//快慢指针找到链表终点
//递归出口为只有一个节点或者没有节点

//然后合并两个有序链表
//使用一个dumy头指针



class Solution_148 {
public:
	ListNode* sortList(ListNode* head) {
		if (head == NULL || head->next == NULL)
			return head;
		ListNode*fast = head;
		ListNode*slow = head;
		while (fast->next != NULL&&fast->next->next != NULL) {
			fast = fast->next->next;
			slow = slow->next;
		}
		ListNode *next_head = slow->next;
		slow->next = NULL;
		auto h1 = sortList(head);
		auto h2 = sortList(next_head);
		ListNode *new_head = merge(h1, h2);
		return new_head;
	}
	ListNode * merge(ListNode *h1, ListNode*h2) {
		ListNode dumy_head(-1);
		ListNode *dumy = &dumy_head;
		while (h1 != NULL&&h2 != NULL) {
			if (h1->val>h2->val) {
				dumy->next = h2;
				h2 = h2->next;
				dumy = dumy->next;
			}
			else {
				dumy->next = h1;
				h1 = h1->next;
				dumy = dumy->next;
			}
		}
		if (h1 != NULL)
			dumy->next = h1;
		if (h2 != NULL)
			dumy->next = h2;
		return dumy_head.next;
	}
};

//int main() {
//	ListNode *n1 = new ListNode(4);
//	ListNode *n2 = new ListNode(2);
//	n1->next = n2;
//	ListNode *n3 = new ListNode(5);
//	n2->next = n3;
//	ListNode *n4 = new ListNode(7);
//	n3->next = n4;
//	Solution_148 s;
//	s.sortList(n1);
//}