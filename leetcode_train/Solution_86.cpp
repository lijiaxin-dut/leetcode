#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>
#include"ListNode.h"

using namespace std;

//Description
//Given a linked list and a value x, partition it such that all nodes less than x 
//come before nodes greater than or equal to x.
//You should preserve the original relative order of the nodes in each of the two partitions.

//使用四个辅助指针，两个记录头部，两个记录当前的尾部，结束后拼接为一条完整的链表
//注意将尾部置为空

class Solution_86 {
public:
	ListNode* partition(ListNode* head, int x) {
		if (head == NULL || head->next == NULL)
			return head;
		ListNode *less_pointer = new ListNode(-1);
		ListNode *greater_pointer = new ListNode(-1);
		ListNode *less = less_pointer;
		ListNode *great = greater_pointer;
		while (head) {
			if (head->val >= x) {
				greater_pointer->next = head;
				greater_pointer = greater_pointer->next;
				head = head->next;
			}
			else {
				less_pointer->next = head;
				less_pointer = less_pointer->next;
				head = head->next;
			}
		}
		greater_pointer->next = NULL;
		less_pointer->next = great->next;
		return less->next;
	}
};
//int main() {
//	ListNode *n1 = new ListNode(1);
//	ListNode *n2 = new ListNode(4);
//	ListNode *n3 = new ListNode(3);
//	ListNode *n4 = new ListNode(2);
//	ListNode *n5 = new ListNode(5);
//	ListNode *n6 = new ListNode(2);
//	n1->next = n2;
//	n2->next = n3;
//	n3->next = n4;
//	n4->next = n5;
//	n5->next = n6;
//	Solution_86 s;
//	s.partition(n1, 3);
//}