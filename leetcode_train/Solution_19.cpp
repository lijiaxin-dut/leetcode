#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>
#include"ListNode.h"
using namespace std;

//Description
//Given a linked list, remove the n-th node from the end of list and return its head.

//增加一个辅助的链表头，用来处理删除第一个元素的情况
//使用两个指针

class Solution_19 {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode dumy(-1);
		dumy.next = head;
		ListNode *first = &dumy;
		ListNode *second = &dumy;
		for (int i = 0; i<n; i++) {
			first = first->next;
		}
		while (first->next != NULL)
		{
			first = first->next;
			second = second->next;
		}
		second->next = second->next->next;
		return dumy.next;
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
//	Solution_19 s;
//	s.removeNthFromEnd(n1, 2);
//}